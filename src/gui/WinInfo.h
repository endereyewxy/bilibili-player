//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#ifndef BILIBILI_PLAYER_WININFO_H
#define BILIBILI_PLAYER_WININFO_H


#include <QtWidgets/QDialog>

#include "entity/Video.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WinInfo; }
QT_END_NAMESPACE

class WinInfo final : public QDialog {
    Q_OBJECT

public:
    explicit WinInfo(QWidget *parent);
    ~WinInfo() override;

    void open(const Video::Info &info);

private:
    Ui::WinInfo *ui;

    Video::Info m_info;
};


#endif //BILIBILI_PLAYER_WINEDIT_H
