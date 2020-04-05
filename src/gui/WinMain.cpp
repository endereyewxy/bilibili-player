//
// Created by endereyewxy@gmail.com on 4/2/20.
//

#include "WinMain.h"
#include "ui_WinMain.h"

#include <QtGui/QCloseEvent>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QMessageBox>

#include "gui/GuiVideo.h"
#include "util/Config.h"
#include "util/Log.h"
#include "util/Network.h"

WinMain::WinMain()
    : ui(new Ui::WinMain)
    , m_playlist(nullptr)
    , m_addVideo(new WinAddVideo(this))
    , m_edit(new WinEdit(this))
    , m_info(new WinInfo(this))
    , m_logs(new WinLogs(this))
    , m_settings(new WinSettings(this))
    , m_tasks(new WinTasks(this)) {

    // Initialize UI.
    ui->setupUi(this);
    show();

    // Load last playlist only when it exists and is valid.
    if (!Config::defaultPlaylist.isEmpty() && QFile::exists(Config::defaultPlaylist))
        open_playlist_(Config::defaultPlaylist);
    else
        show_playlist_(false);

    // Show warnings and errors immediately.
    connect(&Log::instance(), &Log::newLog,
            [=](const QDateTime &time, Log::Level level, Log::Cause cause, const QString &msg) {
        switch (level) {
            case Log::Warn:
                QMessageBox::warning(this, Log::cause(cause), msg);
                break;
            case Log::Error:
            case Log::Fatal:
                QMessageBox::critical(this, Log::cause(cause), msg);
            default:
                break;
        }
    });

    // Maintain validness of move up/down and remove operations for videos.
    connect(ui->playlist, &QListWidget::currentRowChanged, [=](int row) {
        Q_ASSERT(m_playlist);
        ui->actionMoveUp->setEnabled(row > 0);
        ui->actionMoveDown->setEnabled(row != -1 && row < m_playlist->videos().length() - 1);
        ui->actionRemove->setEnabled(row != -1);
    });

    // When a new video is added.
    connect(m_addVideo, &WinAddVideo::selected, [=](const QString &bvid, int page) {
        Q_ASSERT(m_playlist);
        auto video = Video::openLibrary(bvid);
        m_playlist->add(video, page);
        new GuiVideo(ui->playlist, video, page);
    });

    // When playlist information is edited.
    connect(m_edit, &WinEdit::confirmed, [=](const Playlist::Info &info) {
        m_playlist->setInfo(info);
        setWindowTitle(info.name);
    });

    // Playlist operations.
    connect(ui->actionOpen, &QAction::triggered, [=]() {
        auto file = QFileDialog::getOpenFileName(
                this,
                tr("Open Playlist"),
                m_playlist ? m_playlist->file().path() : "");
        if (!file.isEmpty())
            open_playlist_(file);
    });
    connect(ui->actionNew, &QAction::triggered, [=]() {
        auto file = QFileDialog::getSaveFileName(
                this,
                tr("New Playlist"),
                m_playlist ? m_playlist->file().path() : "");
        if (!file.isEmpty()) {
            open_playlist_(file);
            m_playlist->setInfo({ QFileInfo(file).fileName(), "" });
            m_playlist->save();
        }
    });
    connect(ui->actionEdit, &QAction::triggered, [=]() {
        m_edit->open(m_playlist->info());
    });
    connect(ui->actionSave, &QAction::triggered, [=]() {
        m_playlist->save();
    });
    connect(ui->actionAdd, &QAction::triggered, [=]() {
        m_addVideo->open();
    });

    // Video operations.
    connect(ui->actionPlay, &QAction::triggered, [=]() {
        new WinPlayer(m_playlist, ui->playlist->currentRow());
    });
    connect(ui->actionInformation, &QAction::triggered, [=]() {
        m_info->open(dynamic_cast<GuiVideo *>(ui->playlist->currentItem())->inner()->info());
    });
    connect(ui->actionUpdate, &QAction::triggered, [=]() {
        dynamic_cast<GuiVideo *>(ui->playlist->currentItem())->inner()->update();
    });
    connect(ui->actionDownload, &QAction::triggered, [=]() {
        dynamic_cast<GuiVideo *>(ui->playlist->currentItem())->inner()->download();
    });
    connect(ui->actionMoveUp, &QAction::triggered, [=]() {
        auto row = ui->playlist->currentRow();
        m_playlist->moveUp(row);
        auto item = ui->playlist->takeItem(row);
        ui->playlist->insertItem(row - 1, item);
        ui->playlist->setCurrentRow(row - 1);
    });
    connect(ui->actionMoveDown, &QAction::triggered, [=]() {
        auto row = ui->playlist->currentRow();
        m_playlist->moveDown(row);
        auto item = ui->playlist->takeItem(row);
        ui->playlist->insertItem(row + 1, item);
        ui->playlist->setCurrentRow(row + 1);
    });
    connect(ui->actionRemove, &QAction::triggered, [=]() {
        auto row = ui->playlist->currentRow();
        m_playlist->remove(row);
        delete ui->playlist->takeItem(row);
    });

    // Dialogs.
    connect(ui->actionLogs, &QAction::triggered, m_logs, &QDialog::open);
    connect(ui->actionTasks, &QAction::triggered, m_tasks, &QDialog::open);
    connect(ui->actionSettings, &QAction::triggered, m_settings, &QDialog::open);
    connect(ui->actionAbout, &QAction::triggered, [=]() {
        QString message = tr(
                "<strong>%1</strong> %2<br/>"
                "Developed by %3<br/>"
                "This program is developed under GNU GPL license.<br/><br/>"
                "This is a video manager of <a href=\"https://www.bilibili.com\">bilibili</a>, "
                "you can download videos from this website and play them.<br/><br/>"
                "see <a href=\"https://github.com/endereye/bilibili-player\">github page</a> for more information.")
                .arg(QCoreApplication::applicationName())
                .arg(QCoreApplication::applicationVersion())
                .arg(QCoreApplication::organizationName());
        QMessageBox::about(this, tr("About"), message);
    });
    connect(ui->actionAboutQt, &QAction::triggered, [=]() {
        QMessageBox::aboutQt(this);
    });
}

WinMain::~WinMain() {
    delete ui;
    // Save all changes when exit.
    if (m_playlist)
        m_playlist->save();
    delete m_playlist;
    Video::exit();
}

void WinMain::closeEvent(QCloseEvent *event) {
    if (!Network::isAllTasksFinished() && QMessageBox::question(this,
            tr("Exit"),
            tr("There are unfinished download tasks.\nAbort and exit?")) == QMessageBox::No)
        event->ignore();
    else
        QWidget::closeEvent(event);
}

void WinMain::open_playlist_(const QString &file) {
    delete m_playlist;
    m_playlist = new Playlist(this, file);
    Config::defaultPlaylist = file;
    Config::save();
    ui->playlist->blockSignals(true);
    ui->playlist->clear();
    for (auto &clip : m_playlist->videos())
        new GuiVideo(ui->playlist, clip.video, clip.page);
    ui->playlist->setCurrentRow(0);
    ui->playlist->blockSignals(false);
    show_playlist_(true);
}

void WinMain::show_playlist_(bool valid) {
    setWindowTitle(valid ? m_playlist->info().name : tr("BiliBili Player"));
    ui->playlist  ->setVisible(valid);
    ui->menuVideo ->setEnabled(valid && !m_playlist->videos().isEmpty());
    ui->actionEdit->setEnabled(valid);
    ui->actionSave->setEnabled(valid);
    ui->actionAdd ->setEnabled(valid);
}
