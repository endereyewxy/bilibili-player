//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#include "WinAddVideo.h"
#include "ui_WinAddVideo.h"

#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>

#include "entity/Video.h"
#include "gui/GuiVideo.h"
#include "util/Config.h"

WinAddVideo::WinAddVideo(QWidget *parent) : QDialog(parent), ui(new Ui::WinAddVideo) {
    ui->setupUi(this);
    connect(ui->lineSearch, &QLineEdit::textChanged, [=](const QString &text) {
        for (int i = 0, size = ui->listVideos->count(); i < size; i++) {
            auto item = ui->listVideos->item(i);
            ui->listVideos->item(i)->setHidden(!item->text().contains(text, Qt::CaseInsensitive));
        }
    });
    connect(ui->listVideos, &QListWidget::currentItemChanged, [=](QListWidgetItem *item_) {
        auto item = dynamic_cast<GuiVideo *>(item_);
        ui->listClips->clear();
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(item);
        if (item) {
            auto &clips = item->inner()->info().clips;
            for (int i = 0, size = clips.size(); i < size; i++)
                ui->listClips->addItem(QString("P%1 ").arg(i) + clips[i].part);
            ui->listClips->setCurrentRow(0);
        }
    });
    connect(this, &QDialog::accepted, [=]() {
        emit selected(
                dynamic_cast<GuiVideo *>(ui->listVideos->currentItem())->inner()->info().bvid,
                ui->listClips->currentRow());
    });
    connect(ui->btnNew, &QPushButton::clicked, [=]() {
        auto url = QInputDialog::getText(this, tr("New Video"), tr("Video URL"));
        QRegExp reg("https?://www.bilibili.com/video/(BV\\w{10}).*");
        if (!reg.exactMatch(url)) {
            QMessageBox::critical(this, tr("Error"), tr("Invalid URL"));
            return;
        }
        auto bvid = reg.cap(1);
        if (Video::currentLoaded().contains(bvid))
            return;
        auto video = Video::openNetwork(bvid);
        if (Config::downloadWhenCreated) {
            connect(video, &Video::updated, [=](bool first) {
                if (first)
                    video->download();
            });
        }
        new GuiVideo(ui->listVideos, video);
    });
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    for (auto video : Video::currentLoaded())
        new GuiVideo(ui->listVideos, video);
    ui->listVideos->setCurrentRow(0);
}

WinAddVideo::~WinAddVideo() {
    delete ui;
}
