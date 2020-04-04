//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#ifndef BILIBILI_PLAYER_GUIVIDEO_H
#define BILIBILI_PLAYER_GUIVIDEO_H


#include <QtWidgets/QListWidgetItem>

#include "entity/Video.h"

class GuiVideo final : public QObject, public QListWidgetItem {
    Q_OBJECT

public:
    GuiVideo(QListWidget *parent, Video *video, int page = -1);

    [[nodiscard]] Video *inner() const noexcept;
    [[nodiscard]] int page() const noexcept;

private:
    Video *m_video;
    int    m_page;
};


#endif //BILIBILI_PLAYER_GUIVIDEO_H
