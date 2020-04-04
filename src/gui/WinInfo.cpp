//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#include "WinInfo.h"
#include "ui_WinInfo.h"

#include <QtGui/QDesktopServices>

const QString URL_BVID = "https://www.bilibili.com/video/"; // NOLINT(cert-err58-cpp)
const QString URL_AUTH = "https://space.bilibili.com/";     // NOLINT(cert-err58-cpp)

WinInfo::WinInfo(QWidget *parent) : QDialog(parent), ui(new Ui::WinInfo) {
    ui->setupUi(this);
    connect(ui->btnBVID, &QPushButton::clicked, [=]() {
        QDesktopServices::openUrl(URL_BVID + m_info.bvid);
    });
    connect(ui->btnAuth, &QPushButton::clicked, [=]() {
        QDesktopServices::openUrl(URL_AUTH + QString::number(m_info.auid));
    });
}

void WinInfo::open(const Video::Info &info) {
    ui->txtName->setText(info.name);
    ui->txtBVID->setText(info.bvid);
    ui->txtAuth->setText(info.auth);
    ui->txtDesc->setText(info.desc);
    m_info = info;
    QDialog::open();
}

WinInfo::~WinInfo() {
    delete ui;
}
