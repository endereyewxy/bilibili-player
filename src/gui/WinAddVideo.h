//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#ifndef BILIBILI_PLAYER_WINADDVIDEO_H
#define BILIBILI_PLAYER_WINADDVIDEO_H


#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class WinAddVideo; }
QT_END_NAMESPACE


class WinAddVideo final : public QDialog {
    Q_OBJECT

public:
    explicit WinAddVideo(QWidget *parent);
    ~WinAddVideo() override;

signals:
    void selected(const QString &bvid, int page);

private:
    Ui::WinAddVideo *ui;
};


#endif //BILIBILI_PLAYER_WINADDVIDEO_H
