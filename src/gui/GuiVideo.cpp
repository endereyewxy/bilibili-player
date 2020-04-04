//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#include "GuiVideo.h"

#include "entity/Playlist.h"

GuiVideo::GuiVideo(QListWidget *parent, Video *video, int page)
    : QListWidgetItem(parent)
    , m_video(video)
    , m_page(page) {
    connect(video, &Video::updated, [=]() {
        if (!m_video->info().image.isNull())
            setIcon(m_video->info().image);
        if (page == -1)
            setText(m_video->info().name);
        else
            setText(Playlist::display({ m_video, page }, '\n'));
    });
    emit video->updated(false);
}

Video *GuiVideo::inner() const noexcept {
    return m_video;
}

int GuiVideo::page() const noexcept {
    return m_page;
}
