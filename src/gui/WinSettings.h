//
// Created by endereyewxy@gmail.com on 4/4/20.
//

#ifndef BILIBILI_PLAYER_WINSETTINGS_H
#define BILIBILI_PLAYER_WINSETTINGS_H


#include <QtWidgets/QDialog>

#include "entity/Playlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WinSettings; }
QT_END_NAMESPACE

class WinSettings final : public QDialog {
    Q_OBJECT

public:
    explicit WinSettings(QWidget *parent);
    ~WinSettings() override;

private:
    Ui::WinSettings *ui;
};


#endif //BILIBILI_PLAYER_WINEDIT_H
