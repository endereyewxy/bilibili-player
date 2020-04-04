//
// Created by endereye@gmail.com on 3/30/20.
//

#include "Network.h"

#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QSettings>
#include <QtNetwork/QNetworkCookie>
#include <QtNetwork/QNetworkReply>

#include "util/Config.h"
#include "util/Log.h"

Network Network::m_instance; // NOLINT(cert-err58-cpp)

void Network::init() {
    m_instance.m_request.setHeader(QNetworkRequest::UserAgentHeader, Config::userAgent);
    m_instance.m_request.setRawHeader("Referer", "https://www.bilibili.com/");
    QNetworkCookie cookie("SESSDATA", Config::session.toStdString().c_str());
    QList < QNetworkCookie > cookie_jar = {cookie};
    m_instance.m_request.setHeader(QNetworkRequest::CookieHeader, QVariant::fromValue(cookie_jar));
}

Network &Network::instance() noexcept {
    return m_instance;
}

bool Network::isAllTasksFinished() noexcept {
    return m_instance.m_download_queue.isEmpty();
}

void Network::getJson(const QString &url, const Network::JsonCallback &callback) {
    m_instance.m_request.setUrl(url);
    auto reply = m_instance.get(m_instance.m_request);
    connect(reply, &QNetworkReply::finished, &m_instance, [=]() {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            Log::error(Log::Network, reply->errorString());
            return;
        }
        QJsonObject data = QJsonDocument::fromJson(reply->readAll()).object();
        if (data["code"].toInt()) {
            Log::error(Log::API, data["message"].toString());
            return;
        }
        callback(data["data"]);
    });
    Log::info(Log::Network, url);
}

void Network::getData(const QString &url, const Network::DataCallback &callback) {
    m_instance.m_request.setUrl(url);
    auto reply = m_instance.get(m_instance.m_request);
    connect(reply, &QNetworkReply::finished, &m_instance, [=]() {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            Log::error(Log::Network, reply->errorString());
            return;
        }
        callback(reply->readAll());
    });
    Log::info(Log::Network, url);
}

bool Network::getFile(const QString &desc, const QString &url, const QString &file) {
    auto file_ = new QFile(file);
    if (!file_->open(QIODevice::WriteOnly)) {
        Log::error(Log::File, file);
        Log::error(Log::File, file_->errorString());
        delete file_;
        return false;
    }
    Log::info(Log::Network, url);
    Log::info(Log::Network, "Pending");
    m_instance.m_download_queue.push_back(std::make_pair(url, file_));
    emit m_instance.newDownloadTask(desc);
    if (m_instance.m_download_queue.size() == 1)
        m_instance.start_download_queue_();
    return true;
}

void Network::start_download_queue_() {
    if (m_download_queue.isEmpty())
        return;
    auto url = m_download_queue.front().first;
    auto file = m_download_queue.front().second;
    m_request.setUrl(url);
    Log::info(Log::Network, url);
    Log::info(Log::Network, "Download started");
    auto reply = get(m_request);
    connect(reply, &QNetworkReply::downloadProgress, [=](qint64 cur, qint64 tot) {
        emit progressChanged(cur, tot);
    });
    connect(reply, &QNetworkReply::readyRead, [=]() {
        file->write(reply->readAll());
    });
    connect(reply, &QNetworkReply::finished, [=]() {
        reply->deleteLater();
        file->close();
        file->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            Log::error(Log::Network, reply->errorString());
            return;
        }
        Log::info(Log::Network, url);
        Log::info(Log::Network, "Download finished");
        m_download_queue.pop_front();
        emit currentTaskDone();
        if (!m_download_queue.isEmpty())
            start_download_queue_();
        emit progressChanged(0, 0);
    });
}
