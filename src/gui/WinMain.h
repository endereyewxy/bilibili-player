//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#ifndef BILIBILI_PLAYER_WINMAIN_H
#define BILIBILI_PLAYER_WINMAIN_H


#include <QtWidgets/QMainWindow>

#include "gui/WinAddVideo.h"
#include "gui/WinLogs.h"
#include "gui/WinTasks.h"
#include "gui/WinPlayer.h"
#include "gui/WinEdit.h"
#include "gui/WinInfo.h"
#include "gui/WinSettings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WinMain; }
QT_END_NAMESPACE

class WinMain final : public QMainWindow {
    Q_OBJECT

public:
    explicit WinMain();
    ~WinMain() override;

    void closeEvent(QCloseEvent *event) override;

private:
    Ui::WinMain *ui;

    Playlist *m_playlist;

    WinAddVideo *m_addVideo;
    WinEdit     *m_edit;
    WinInfo     *m_info;
    WinLogs     *m_logs;
    WinSettings *m_settings;
    WinTasks    *m_tasks;

    void open_playlist_(const QString &file);
    void show_playlist_(bool valid);
};


#endif //BILIBILI_PLAYER_WINMAIN_H
