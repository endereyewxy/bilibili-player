//
// Created by endereyewxy@gmail.com on 3/30/20.
//

#ifndef BILIBILI_PLAYER_NETWORK_H
#define BILIBILI_PLAYER_NETWORK_H


#include <QtCore/QFile>
#include <QtCore/QLinkedList>
#include <QtNetwork/QNetworkAccessManager>

#include <functional>

class Network final : public QNetworkAccessManager {
Q_OBJECT

public:
    using JsonCallback = std::function<void(const QJsonValue &)>;
    using DataCallback = std::function<void(const QByteArray &)>;

    static void init();

    static Network &instance() noexcept;

    static bool isAllTasksFinished() noexcept;

    static void getJson(const QString &url, const JsonCallback &callback);

    static void getData(const QString &url, const DataCallback &callback);

    static bool getFile(const QString &desc, const QString &url, const QString &file);

signals:

    void newDownloadTask(const QString &desc);

    void currentTaskDone();

    void progressChanged(qint64 cur, qint64 tot);

private:
    QNetworkRequest m_request;
    QLinkedList<std::pair<QString, QFile *>> m_download_queue;

    void start_download_queue_();

    static Network m_instance;
};


#endif //BILIBILI_PLAYER_NETWORK_H
