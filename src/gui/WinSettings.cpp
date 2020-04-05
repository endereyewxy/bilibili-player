//
// Created by endereyewxy@gmail.com on 4/4/20.
//

#include "WinSettings.h"
#include "ui_WinSettings.h"

#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>

#include "util/Config.h"
#include "util/Log.h"

WinSettings::WinSettings(QWidget *parent) : QDialog(parent), ui(new Ui::WinSettings) {
    ui->setupUi(this);
    ui->lineUserAgent->setText(Config::userAgent);
    ui->lineSession->setText(Config::session);
    ui->lineLibrary->setText(Config::library);
    ui->checkDownloadWhenCreated->setChecked(Config::downloadWhenCreated);
    ui->checkAutomaticFullscreen->setChecked(Config::automaticFullscreen);
    for (auto qm : QDir(":/lang").entryList()) {
        qm.truncate(qm.lastIndexOf('.'));
        QLocale locale(qm);
        ui->comboLanguage->addItem(locale.nativeLanguageName(), qm);
        if (qm == Config::userTranslation)
            ui->comboLanguage->setCurrentIndex(ui->comboLanguage->count() - 1);
    }
    connect(this, &QDialog::accepted, [=]() {
        bool restart =
                Config::userAgent != ui->lineUserAgent->text() ||
                Config::session != ui->lineSession->text() ||
                Config::library != ui->lineLibrary->text() ||
                Config::userTranslation != ui->comboLanguage->currentData().toString();
        Config::userAgent = ui->lineUserAgent->text();
        Config::session = ui->lineSession->text();
        Config::library = ui->lineLibrary->text();
        Config::userTranslation = ui->comboLanguage->currentData().toString();
        Config::downloadWhenCreated = ui->checkDownloadWhenCreated->isChecked();
        Config::automaticFullscreen = ui->checkAutomaticFullscreen->isChecked();
        Config::save();
        if (!QDir(Config::library).exists())
            Log::warn(Log::Settings, tr("Directory %1 does not exist").arg(Config::library));
        if (restart && QMessageBox::question(this,
                tr("Restart"),
                tr("Some settings require restart to take effect, restart now?")))
            QApplication::quit();
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
