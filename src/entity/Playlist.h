//
// Created by endereyewxy@gmail.com on 4/1/20.
//

#ifndef BILIBILI_PLAYER_PLAYLIST_H
#define BILIBILI_PLAYER_PLAYLIST_H


#include "Video.h"

class Playlist final : public QObject {
    Q_OBJECT

public:
    struct Info {
        QString name;
        QString desc;
    };

    struct Clip {
        Video *video;
        int    page;
    };

    explicit Playlist(QObject *parent, const QString &file);

    static QString display(const Clip &clip, char sep);

    [[nodiscard]] QFileInfo file() const noexcept;
    [[nodiscard]] const Info &info() const noexcept;
    [[nodiscard]] const QList<Clip> &videos() const noexcept;

    void setInfo(const Info &info) noexcept;

    void add(Video *video, int page);
    void moveUp(int index);
    void moveDown(int index);
    void remove(int index);
    void save() const;

private:
    explicit Playlist() = default; // Hide constructor to prevent invalid objects.

    QString     m_file;
    Info        m_info;
    QList<Clip> m_videos;
};


#endif //BILIBILI_PLAYER_PLAYLIST_H
