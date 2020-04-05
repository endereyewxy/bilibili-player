//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#ifndef BILIBILI_PLAYER_WINPLAYER_H
#define BILIBILI_PLAYER_WINPLAYER_H


#include <QtMultimedia/QMediaPlayer>
#include <QtWidgets/QGraphicsView>

#include "entity/Playlist.h"

class WinPlayer final : public QGraphicsView {
    Q_OBJECT

public:
    explicit WinPlayer(Playlist *playlist, int start);
    ~WinPlayer() override;

    void closeEvent(QCloseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    QMediaPlayer       *m_player;
    QMediaPlaylist     *m_playlist;
    QGraphicsScene     *m_scene;
    QGraphicsVideoItem *m_video;
    QGraphicsTextItem  *m_cursor;
    QGraphicsTextItem  *m_volume;
    int                 m_cursorTimer = 0;
    int                 m_volumeTimer = 0;

    void reconfigure_sizes();

    static QString format_time_(qint64 position);
};


#endif //BILIBILI_PLAYER_WINPLAYER_H
