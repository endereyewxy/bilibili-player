//
// Created by endereyewxy@gmail.com on 4/1/20.
//

#include "Playlist.h"

#include <QtCore/QSettings>

Playlist::Playlist(QObject *parent, const QString &file): QObject(parent) {
    m_file = file;
    QSettings data(file, QSettings::IniFormat);
    m_info = {
            data.value("name").toString(),
            data.value("desc").toString()
    };
    auto size = data.beginReadArray("videos");
    m_videos.reserve(size);
    for (int i = 0; i < size; i++) {
        data.setArrayIndex(i);
        m_videos.append({
            Video::openLibrary(data.value("bvid").toString()),
            data.value("page").toInt()
        });
    }
    data.endArray();
}

QString Playlist::display(const Playlist::Clip &clip, char sep) {
    auto &info = clip.video->info();
    return info.name + sep + QString("P%1 ").arg(clip.page) + info.clips[clip.page].part;
}

QFileInfo Playlist::file() const noexcept {
    return m_file;
}

const Playlist::Info &Playlist::info() const noexcept {
    return m_info;
}

const QList<Playlist::Clip> &Playlist::videos() const noexcept {
    return m_videos;
}

void Playlist::setInfo(const Playlist::Info &info) noexcept {
    m_info = info;
}

void Playlist::add(Video *video, int page) {
    m_videos.append({ video, page });
}

void Playlist::moveUp(int index) {
    Q_ASSERT(0 < index && index < m_videos.size());
    std::swap(m_videos[index - 1], m_videos[index]);
}

void Playlist::moveDown(int index) {
    Q_ASSERT(0 <= index && index < m_videos.size() - 1);
    std::swap(m_videos[index], m_videos[index + 1]);
}

void Playlist::remove(int index) {
    Q_ASSERT(0 <= index && index < m_videos.size());
    m_videos.removeAt(index);
}

void Playlist::save() const {
    QSettings data(m_file, QSettings::IniFormat);
    data.setValue("name", m_info.name);
    data.setValue("desc", m_info.desc);
    data.beginWriteArray("videos");
    for (int i = 0, size = m_videos.size(); i < size; i++) {
        data.setArrayIndex(i);
        data.setValue("bvid", m_videos[i].video->info().bvid);
        data.setValue("page", m_videos[i].page);
    }
    data.endArray();
}
