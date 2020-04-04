//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#ifndef BILIBILI_PLAYER_WINTASKS_H
#define BILIBILI_PLAYER_WINTASKS_H


#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class WinTasks; }
QT_END_NAMESPACE

class WinTasks final : public QDialog {
    Q_OBJECT

public:
    explicit WinTasks(QWidget *parent);
    ~WinTasks() override;

private:
    Ui::WinTasks *ui;
};


#endif //BILIBILI_PLAYER_WINTASKS_H
