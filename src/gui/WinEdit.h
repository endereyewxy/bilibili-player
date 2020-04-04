//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#ifndef BILIBILI_PLAYER_WINEDIT_H
#define BILIBILI_PLAYER_WINEDIT_H


#include <QtWidgets/QDialog>

#include "entity/Playlist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WinEdit; }
QT_END_NAMESPACE

class WinEdit final : public QDialog {
    Q_OBJECT

public:
    explicit WinEdit(QWidget *parent);
    ~WinEdit() override;

    void open(const Playlist::Info &info);

signals:
    void confirmed(const Playlist::Info &info);

private:
    Ui::WinEdit *ui;
};


#endif //BILIBILI_PLAYER_WINEDIT_H
