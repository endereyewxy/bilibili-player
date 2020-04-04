//
// Created by endereyewxy@gmail.com on 3/30/20.
//

#ifndef BILIBILI_PLAYER_VIDEO_H
#define BILIBILI_PLAYER_VIDEO_H


#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtGui/QPixmap>

class Video final : public QObject {
    Q_OBJECT

public:
    struct Clip {
        int     cvid;
        QString part;
    };
    struct Info {
        QString           bvid;
        QString           name;
        QString           auth;
        int               auid;
        QString           desc;
        QPixmap           image;
        std::vector<Clip> clips;
    };

    static void init();
    static void exit();

    static const QMap<QString, Video *> &currentLoaded();


    static Video *openLibrary(const QString &bvid);
    static Video *openNetwork(const QString &bvid);
    static Video *openExisted(const QString &bvid);

    [[nodiscard]] const Info &info() const noexcept;
    [[nodiscard]] QString videoFile(int page) const noexcept;

    void update();
    void download();
    void save() const;

signals:
    void updated(bool first);

private:
    explicit Video() = default;

    Info m_info;

    void load_network_content_(const QString &bvid, bool first);

    static QDir                   m_library;
    static QMap<QString, Video *> m_loaded;
};


#endif //BILIBILI_PLAYER_VIDEO_H
