//
// Created by endereyewxy@gmail.com on 4/4/20.
//

#include "WinSettings.h"
#include "ui_WinSettings.h"

#include <QtWidgets/QFileDialog>

#include "util/Config.h"
#include "util/Log.h"

WinSettings::WinSettings(QWidget *parent) : QDialog(parent), ui(new Ui::WinSettings) {
    ui->setupUi(this);
    ui->lineUserAgent->setText(Config::userAgent);
    ui->lineSession->setText(Config::session);
    ui->lineLibrary->setText(Config::library);
    ui->checkDownloadWhenCreated->setChecked(Config::downloadWhenCreated);
    ui->checkAutomaticFullscreen->setChecked(Config::automaticFullscreen);
    connect(this, &QDialog::accepted, [=]() {
        Config::userAgent = ui->lineUserAgent->text();
        Config::session = ui->lineSession->text();
        Config::library = ui->lineLibrary->text();
        Config::downloadWhenCreated = ui->checkDownloadWhenCreated->isChecked();
        Config::automaticFullscreen = ui->checkAutomaticFullscreen->isChecked();
        Config::save();
        if (!QDir(Config::library).exists())
            Log::warn(Log::Settings, tr("Directory %1 does not exist").arg(Config::library));
    });
    connect(ui->btnLibrary, &QPushButton::clicked, [=]() {
        auto dir = QFileDialog::getExistingDirectory(this,
                tr("Set Video Location"),
                ui->lineLibrary->text());
        if (!dir.isEmpty())
            ui->lineLibrary->setText(dir);
    });
}

WinSettings::~WinSettings() {
    delete ui;
}
