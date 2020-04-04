//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#ifndef BILIBILI_PLAYER_WINLOGS_H
#define BILIBILI_PLAYER_WINLOGS_H


#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class WinLogs; }
QT_END_NAMESPACE

class WinLogs final : public QDialog {
    Q_OBJECT

public:
    explicit WinLogs(QWidget *parent);
    ~WinLogs() override;

private:
    Ui::WinLogs *ui;
};


#endif //BILIBILI_PLAYER_WINLOGS_H
