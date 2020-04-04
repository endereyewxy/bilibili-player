//
// Created by endereyewxy@gmail.com on 3/30/20.
//

#include "Video.h"

#include <QtCore/QJsonArray>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonValue>
#include <QtCore/QSettings>

#include "util/Config.h"
#include "util/Network.h"

QDir Video::m_library; // NOLINT(cert-err58-cpp)
QMap<QString, Video *> Video::m_loaded;

const QString URL_BVID = "https://api.bilibili.com/x/web-interface/view?bvid=%1";        // NOLINT(cert-err58-cpp)
const QString URL_PLAY = "https://api.bilibili.com/x/player/playurl?bvid=%1&cid=%2&qn="; // NOLINT(cert-err58-cpp)

void Video::init() {
    m_library.setPath(Config::library);
    m_library.setNameFilters({ "BV??????????" });
    for (auto &bvid : m_library.entryList())
        m_loaded.insert(bvid, openExisted(bvid));
}

void Video::exit() {
    for (auto video : m_loaded.values())
        delete video;
}

const QMap<QString, Video *> &Video::currentLoaded() {
    return m_loaded;
}

Video *Video::openLibrary(const QString &bvid) {
    return m_loaded.contains(bvid) ? m_loaded[bvid] : openNetwork(bvid);
}

Video *Video::openNetwork(const QString &bvid) {
    auto video = new Video;
    video->load_network_content_(bvid, true);
    m_loaded.insert(bvid, video);
    return video;
}

Video *Video::openExisted(const QString &bvid) {
    Q_ASSERT(m_library.exists(bvid));
    QSettings data(m_library.filePath(bvid), QSettings::IniFormat);
    auto *video = new Video;
    video->m_info = {
            data.value("bvid").toString(),
            data.value("name").toString(),
            data.value("auth").toString(),
            data.value("auid").toInt(),
            data.value("desc").toString(),
            data.value("image").value<QPixmap>()
    };
    auto size = data.beginReadArray("clips");
    video->m_info.clips.resize(size);
    for (int i = 0; i < size; i++) {
        data.setArrayIndex(i);
        video->m_info.clips[i] = {
                data.value("cvid").toInt(),
                data.value("part").toString()
        };
    }
    data.endArray();
    return video;
}

const Video::Info &Video::info() const noexcept {
    return m_info;
}

QString Video::videoFile(int page) const noexcept {
    return m_library.filePath(m_info.bvid) + "." + QString::number(page) + ".flv";
}

void Video::update() {
    load_network_content_(m_info.bvid, false);
}

void Video::download() {
    for (int i = 0, size = m_info.clips.size(); i < size; i++) {
        auto url = URL_PLAY.arg(m_info.bvid).arg(m_info.clips[i].cvid);
        Network::getJson(url, [=](const QJsonValue &resp) {
            auto qn = resp.toObject()["accept_quality"].toArray()[0].toInt();
            Network::getJson(url + QString::number(qn), [=](const QJsonValue &resp) {
                auto url = resp.toObject()["durl"].toArray()[0].toObject()["url"].toString();
                Network::getFile(m_info.name, url, videoFile(i));
            });
        });
    }
}

void Video::save() const {
    QSettings data(m_library.filePath(m_info.bvid), QSettings::IniFormat);
    data.setValue("bvid", m_info.bvid);
    data.setValue("name", m_info.name);
    data.setValue("auth", m_info.auth);
    data.setValue("auid", m_info.auid);
    data.setValue("desc", m_info.desc);
    data.setValue("image", m_info.image);
    data.beginWriteArray("clips");
    for (int i = 0, size = m_info.clips.size(); i < size; i++) {
        auto &clip = m_info.clips[i];
        data.setArrayIndex(i);
        data.setValue("cvid", clip.cvid);
        data.setValue("part", clip.part);
    }
    data.endArray();
}

void Video::load_network_content_(const QString &bvid, bool first) {
    Network::getJson(URL_BVID.arg(bvid), [=](const QJsonValue &resp) {
        const auto &info = resp.toObject();
        const auto &auth = info["owner"].toObject();
        const auto &list = info["pages"].toArray();
        auto size = list.size();
        m_info = {
                bvid,
                info["title"].toString(),
                auth["name"].toString(),
                auth["mid"].toInt(),
                info["desc"].toString()
        };
        m_info.clips.resize(size);
        for (int i = 0; i < size; i++) {
            const auto &page = list[i].toObject();
            m_info.clips[i] = {
                    page["cid"].toInt(),
                    page["part"].toString()
            };
        }
        Network::getData(info["pic"].toString(), [=](const QByteArray &resp) {
            m_info.image.loadFromData(resp);
            // This is the only place, where auto-save and update signal is triggered.
            // It is ensured that, at here, all the information has been completely downloaded.
            save();
            emit updated(first);
        });
    });
}
