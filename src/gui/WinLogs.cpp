//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#include "WinLogs.h"
#include "ui_WinLogs.h"

#include <QtCore/QDateTime>

#include "util/Log.h"

WinLogs::WinLogs(QWidget *parent) : QDialog(parent), ui(new Ui::WinLogs) {
    ui->setupUi(this);
    ui->tableLogs->setColumnWidth(0, 160);
    connect(&Log::instance(), &Log::newLog,
            [=](const QDateTime &time, Log::Level level, Log::Cause cause, const QString &msg) {
        ui->tableLogs->insertRow(0);
        auto it0 = new QTableWidgetItem(time.toString("yyyy-MM-dd"));
        it0->setTextAlignment(Qt::AlignCenter);
        it0->setFlags(it0->flags() & ~Qt::ItemIsEditable);
        auto it1 = new QTableWidgetItem(Log::level(level));
        it1->setTextAlignment(Qt::AlignCenter);
        it1->setFlags(it0->flags() & ~Qt::ItemIsEditable);
        switch (level) {
            case Log::Info:
                it1->setForeground(QColor(0, 0, 0)); // black
                break;
            case Log::Warn:
                it1->setForeground(QColor(255, 140, 0)); // dark orange
                break;
            case Log::Error:
            case Log::Fatal:
                it1->setForeground(QColor(255, 0, 0)); // red
                break;
        }
        auto it2 = new QTableWidgetItem(Log::cause(cause));
        it2->setTextAlignment(Qt::AlignCenter);
        it2->setFlags(it0->flags() & ~Qt::ItemIsEditable);
        auto it3 = new QTableWidgetItem(msg);
        it3->setFlags(it0->flags() & ~Qt::ItemIsEditable);
        ui->tableLogs->setItem(0, 0, it0);
        ui->tableLogs->setItem(0, 1, it1);
        ui->tableLogs->setItem(0, 2, it2);
        ui->tableLogs->setItem(0, 3, it3);
    });
}

WinLogs::~WinLogs() {
    delete ui;
}
