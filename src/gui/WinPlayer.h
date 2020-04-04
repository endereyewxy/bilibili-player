//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#ifndef BILIBILI_PLAYER_WINPLAYER_H
#define BILIBILI_PLAYER_WINPLAYER_H


#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

#include "entity/Playlist.h"

class WinPlayer final : public QVideoWidget {
    Q_OBJECT

public:
    explicit WinPlayer(Playlist *playlist, int start);
    ~WinPlayer() override;

    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    QMediaPlayer   *m_player;
    QMediaPlaylist *m_playlist;
};


#endif //BILIBILI_PLAYER_WINPLAYER_H
