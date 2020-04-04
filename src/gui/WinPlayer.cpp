//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#include "WinPlayer.h"

#include <QtGui/QKeyEvent>
#include <QtGui/QPainter>
#include <QtGui/QIcon>
#include <QtMultimedia/QMediaPlaylist>

WinPlayer::WinPlayer(Playlist *playlist, int start)
    : QVideoWidget(nullptr)
    , m_player(new QMediaPlayer)
    , m_playlist(new QMediaPlaylist) {
    m_player->setVideoOutput(this);
    m_player->setPlaylist(m_playlist);
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);
    connect(m_playlist, &QMediaPlaylist::currentIndexChanged, [=](int index) {
        setWindowTitle(Playlist::display(playlist->videos()[index], '\t'));
    });
    setWindowIcon(QIcon(":/icons/icon.png"));
    showMaximized();
    raise();
    m_playlist->clear();
    for (auto &clip : playlist->videos())
        m_playlist->addMedia(QUrl::fromLocalFile(clip.video->videoFile(clip.page)));
    m_playlist->setCurrentIndex(start);
    m_player->play();
}

WinPlayer::~WinPlayer() {
    delete m_player;
    delete m_playlist;
}

void WinPlayer::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Escape:
            setFullScreen(false);
            break;
        case Qt::Key_F:
            setFullScreen(!isFullScreen());
            break;
        case Qt::Key_Space:
            m_player->state() == QMediaPlayer::PlayingState ? m_player->pause() : m_player->play();
            break;
        case Qt::Key_Left:
            m_player->setPosition(m_player->position() - 5000);
            break;
        case Qt::Key_Right:
            m_player->setPosition(m_player->position() + 5000);
            break;
        case Qt::Key_Up:
            m_player->setVolume(m_player->volume() + 5);
            break;
        case Qt::Key_Down:
            m_player->setVolume(m_player->volume() - 5);
            break;
        default:
            QWidget::keyPressEvent(event);
    }
}

void WinPlayer::closeEvent(QCloseEvent *event) {
    deleteLater();
    m_player->stop();
    QWidget::closeEvent(event);
}

