//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#include "WinPlayer.h"

#include <QtGui/QGuiApplication>
#include <QtGui/QKeyEvent>
#include <QtGui/QIcon>
#include <QtMultimedia/QMediaPlaylist>
#include <QtMultimediaWidgets/QGraphicsVideoItem>

#include "util/Config.h"

WinPlayer::WinPlayer(Playlist *playlist, int start)
    : m_player(new QMediaPlayer)
    , m_playlist(new QMediaPlaylist)
    , m_scene(new QGraphicsScene(this))
    , m_video(new QGraphicsVideoItem)
    , m_cursor(new QGraphicsTextItem)
    , m_volume(new QGraphicsTextItem) {

    // Configure this window.
    auto font = QGuiApplication::font();
    font.setBold(true);
    font.setPointSize(30);
    m_cursor->setFont(font);
    m_volume->setFont(font);
    m_cursor->setDefaultTextColor(QColor(255, 255, 255));
    m_volume->setDefaultTextColor(QColor(255, 255, 255));
    m_cursor->hide();
    m_volume->hide();
    m_scene->addItem(m_video);
    m_scene->addItem(m_cursor);
    m_scene->addItem(m_volume);
    setScene(m_scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowIcon(QIcon(":/icons/icon.png"));
    setWindowTitle(Playlist::display(playlist->videos()[0], '\t'));
    showNormal();
    if (Config::automaticFullscreen)
        showFullScreen();
    raise();

    // Add videos to playlist.
    connect(m_playlist, &QMediaPlaylist::currentIndexChanged, [=](int index) {
        setWindowTitle(Playlist::display(playlist->videos()[index], '\t'));
        reconfigure_sizes();
    });
    m_playlist->clear();
    for (auto &clip : playlist->videos())
        m_playlist->addMedia(QUrl::fromLocalFile(clip.video->videoFile(clip.page)));
    m_playlist->setPlaybackMode(QMediaPlaylist::Loop);

    // Configure media player
    connect(m_player, &QMediaPlayer::positionChanged, [=](qint64 position) {
        m_cursor->setPlainText(format_time_(position));
    });
    connect(m_player, &QMediaPlayer::volumeChanged, [=](int volume) {
        m_volume->setPlainText(QString::number(volume));
        reconfigure_sizes();
    });
    connect(m_player, &QMediaPlayer::mediaStatusChanged, [=](QMediaPlayer::MediaStatus status) {
        reconfigure_sizes();
    });
    m_player->setVideoOutput(m_video);
    m_player->setPlaylist(m_playlist);
    m_player->setVolume(Config::volume);
    m_playlist->setCurrentIndex(start);
    m_player->play();
}

WinPlayer::~WinPlayer() {
    delete m_player;
    delete m_playlist;
    Config::save();
}

void WinPlayer::closeEvent(QCloseEvent *event) {
    deleteLater();
    m_player->stop();
    QWidget::closeEvent(event);
}

void WinPlayer::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_Escape:
            if (isFullScreen())
                showNormal();
            break;
        case Qt::Key_F:
            isFullScreen() ? showNormal() : showFullScreen();
            break;
        case Qt::Key_Z:
            if (m_video->nativeSize().width() != -1)
                resize(m_video->nativeSize().width(), m_video->nativeSize().height());
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
        case Qt::Key_BracketLeft:
            m_playlist->previous();
            break;
        case Qt::Key_BracketRight:
            m_playlist->next();
    }
    switch (event->key()) {
        case Qt::Key_Left:
        case Qt::Key_Right:
        case Qt::Key_P:
            m_cursor->show();
            m_cursorTimer = startTimer(3000);
            break;
        case Qt::Key_Up:
        case Qt::Key_Down:
        case Qt::Key_V:
            Config::volume = m_player->volume();
            m_volume->show();
            m_volumeTimer = startTimer(3000);
    }
    QGraphicsView::keyPressEvent(event);
}

void WinPlayer::resizeEvent(QResizeEvent *event) {
    reconfigure_sizes();
    QGraphicsView::resizeEvent(event);
}

void WinPlayer::timerEvent(QTimerEvent *event) {
    if (event->timerId() == m_cursorTimer)
        m_cursor->hide();
    if (event->timerId() == m_volumeTimer)
        m_volume->hide();
    killTimer(event->timerId());
    QObject::timerEvent(event);
}

void WinPlayer::reconfigure_sizes() {
    m_video->setSize(size());
    m_cursor->setPos(m_video->boundingRect().topLeft());
    QFontMetrics fm(m_volume->font());
    auto vp = m_video->boundingRect().center();
    vp.setX(vp.x() - fm.horizontalAdvance(m_volume->toPlainText()) / 2.0);
    vp.setY(vp.y() - fm.height() / 2.0);
    m_volume->setPos(vp);
}

QString WinPlayer::format_time_(qint64 position) {
    return QString("%1:%2")
        .arg(position / 60000, 2, 10, QLatin1Char('0'))
        .arg(position / 1000 % 60, 2, 10, QLatin1Char('0'));
}

