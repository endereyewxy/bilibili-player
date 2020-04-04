//
// Created by endereyewxy@gmail.com on 4/4/20.
//

#include "WinSettings.h"
#include "ui_WinSettings.h"

#include "util/Config.h"

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
    });
}

WinSettings::~WinSettings() {
    delete ui;
}
