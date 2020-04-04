//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#include "WinTasks.h"
#include "ui_WinTasks.h"

#include "util/Network.h"

const QString FORMAT = "%1 MB / %2 MB"; // NOLINT(cert-err58-cpp)

WinTasks::WinTasks(QWidget *parent) : QDialog(parent), ui(new Ui::WinTasks) {
    ui->setupUi(this);
    connect(&Network::instance(),
            &Network::newDownloadTask,
            ui->listQueue,
            QOverload<const QString&>::of(&QListWidget::addItem));
    connect(&Network::instance(), &Network::currentTaskDone, [=]() {
        delete ui->listQueue->takeItem(0);
    });
    connect(&Network::instance(), &Network::progressChanged, [=](qint64 cur, qint64 tot) {
        ui->progress->setMaximum(tot);
        ui->progress->setValue(cur);
        if (tot) {
            ui->label->setText(
                    FORMAT
                    .arg(cur / 1048576.0)
                    .arg(tot / 1048576.0));
        } else {
            ui->label->setText(tr("Nothing to do"));
        }
    });
}

WinTasks::~WinTasks() {
    delete ui;
}
