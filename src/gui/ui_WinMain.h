/********************************************************************************
** Form generated from reading UI file 'WinMainXEdrYc.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINMAINXEDRYC_H
#define WINMAINXEDRYC_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WinMain
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionAdd;
    QAction *actionLogs;
    QAction *actionTasks;
    QAction *actionDownload;
    QAction *actionUpdate;
    QAction *actionInformation;
    QAction *actionPlay;
    QAction *actionRemove;
    QAction *actionEdit;
    QAction *actionMoveUp;
    QAction *actionMoveDown;
    QAction *actionNew;
    QAction *actionSettings;
    QAction *actionAbout;
    QAction *actionAboutQt;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QListWidget *playlist;
    QMenuBar *menubar;
    QMenu *menuPlayList;
    QMenu *menuView;
    QMenu *menuVideo;

    void setupUi(QMainWindow *WinMain)
    {
        if (WinMain->objectName().isEmpty())
            WinMain->setObjectName(QString::fromUtf8("WinMain"));
        WinMain->resize(957, 665);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        WinMain->setWindowIcon(icon);
        actionOpen = new QAction(WinMain);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(WinMain);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionAdd = new QAction(WinMain);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        actionLogs = new QAction(WinMain);
        actionLogs->setObjectName(QString::fromUtf8("actionLogs"));
        actionTasks = new QAction(WinMain);
        actionTasks->setObjectName(QString::fromUtf8("actionTasks"));
        actionDownload = new QAction(WinMain);
        actionDownload->setObjectName(QString::fromUtf8("actionDownload"));
        actionUpdate = new QAction(WinMain);
        actionUpdate->setObjectName(QString::fromUtf8("actionUpdate"));
        actionInformation = new QAction(WinMain);
        actionInformation->setObjectName(QString::fromUtf8("actionInformation"));
        actionPlay = new QAction(WinMain);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        actionRemove = new QAction(WinMain);
        actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
        actionEdit = new QAction(WinMain);
        actionEdit->setObjectName(QString::fromUtf8("actionEdit"));
        actionMoveUp = new QAction(WinMain);
        actionMoveUp->setObjectName(QString::fromUtf8("actionMoveUp"));
        actionMoveDown = new QAction(WinMain);
        actionMoveDown->setObjectName(QString::fromUtf8("actionMoveDown"));
        actionNew = new QAction(WinMain);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSettings = new QAction(WinMain);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionAbout = new QAction(WinMain);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAboutQt = new QAction(WinMain);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        centralwidget = new QWidget(WinMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        playlist = new QListWidget(centralwidget);
        playlist->setObjectName(QString::fromUtf8("playlist"));
        playlist->setIconSize(QSize(160, 100));
        playlist->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        playlist->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        gridLayout->addWidget(playlist, 0, 0, 1, 1);

        WinMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WinMain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 957, 35));
        menuPlayList = new QMenu(menubar);
        menuPlayList->setObjectName(QString::fromUtf8("menuPlayList"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuVideo = new QMenu(menubar);
        menuVideo->setObjectName(QString::fromUtf8("menuVideo"));
        WinMain->setMenuBar(menubar);

        menubar->addAction(menuPlayList->menuAction());
        menubar->addAction(menuVideo->menuAction());
        menubar->addAction(menuView->menuAction());
        menuPlayList->addAction(actionOpen);
        menuPlayList->addAction(actionNew);
        menuPlayList->addAction(actionSave);
        menuPlayList->addAction(actionEdit);
        menuPlayList->addAction(actionAdd);
        menuView->addAction(actionLogs);
        menuView->addAction(actionTasks);
        menuView->addAction(actionSettings);
        menuView->addAction(actionAbout);
        menuView->addAction(actionAboutQt);
        menuVideo->addAction(actionPlay);
        menuVideo->addAction(actionInformation);
        menuVideo->addAction(actionUpdate);
        menuVideo->addAction(actionDownload);
        menuVideo->addAction(actionMoveUp);
        menuVideo->addAction(actionMoveDown);
        menuVideo->addAction(actionRemove);

        retranslateUi(WinMain);
        QObject::connect(playlist, SIGNAL(doubleClicked(QModelIndex)), actionPlay, SLOT(trigger()));

        QMetaObject::connectSlotsByName(WinMain);
    } // setupUi

    void retranslateUi(QMainWindow *WinMain)
    {
        WinMain->setWindowTitle(QString());
        actionOpen->setText(QCoreApplication::translate("WinMain", "Open", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("WinMain", "Open a playlist", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("WinMain", "Save", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("WinMain", "Save all changes", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAdd->setText(QCoreApplication::translate("WinMain", "Add", nullptr));
#if QT_CONFIG(tooltip)
        actionAdd->setToolTip(QCoreApplication::translate("WinMain", "Add a new video", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAdd->setShortcut(QCoreApplication::translate("WinMain", "Ins", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLogs->setText(QCoreApplication::translate("WinMain", "Logs", nullptr));
#if QT_CONFIG(tooltip)
        actionLogs->setToolTip(QCoreApplication::translate("WinMain", " Show logs", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionLogs->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionTasks->setText(QCoreApplication::translate("WinMain", "Tasks", nullptr));
#if QT_CONFIG(tooltip)
        actionTasks->setToolTip(QCoreApplication::translate("WinMain", " Show download tasks", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionTasks->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDownload->setText(QCoreApplication::translate("WinMain", "Download", nullptr));
#if QT_CONFIG(tooltip)
        actionDownload->setToolTip(QCoreApplication::translate("WinMain", "Download all clips for current video", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionDownload->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUpdate->setText(QCoreApplication::translate("WinMain", "Update", nullptr));
#if QT_CONFIG(tooltip)
        actionUpdate->setToolTip(QCoreApplication::translate("WinMain", "Update current video", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionUpdate->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        actionInformation->setText(QCoreApplication::translate("WinMain", "Information", nullptr));
#if QT_CONFIG(tooltip)
        actionInformation->setToolTip(QCoreApplication::translate("WinMain", "View video information", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionInformation->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPlay->setText(QCoreApplication::translate("WinMain", "Play", nullptr));
#if QT_CONFIG(tooltip)
        actionPlay->setToolTip(QCoreApplication::translate("WinMain", "Play current video", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPlay->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRemove->setText(QCoreApplication::translate("WinMain", "Remove", nullptr));
#if QT_CONFIG(tooltip)
        actionRemove->setToolTip(QCoreApplication::translate("WinMain", "Remove current video", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionRemove->setShortcut(QCoreApplication::translate("WinMain", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEdit->setText(QCoreApplication::translate("WinMain", "Edit", nullptr));
#if QT_CONFIG(shortcut)
        actionEdit->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionMoveUp->setText(QCoreApplication::translate("WinMain", "Move Up", nullptr));
#if QT_CONFIG(tooltip)
        actionMoveUp->setToolTip(QCoreApplication::translate("WinMain", "Move current video up", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionMoveUp->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+Up", nullptr));
#endif // QT_CONFIG(shortcut)
        actionMoveDown->setText(QCoreApplication::translate("WinMain", "Move Down", nullptr));
#if QT_CONFIG(tooltip)
        actionMoveDown->setToolTip(QCoreApplication::translate("WinMain", "Move current video down", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionMoveDown->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+Down", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("WinMain", "New", nullptr));
#if QT_CONFIG(tooltip)
        actionNew->setToolTip(QCoreApplication::translate("WinMain", "Create a new playlist", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSettings->setText(QCoreApplication::translate("WinMain", "Settings", nullptr));
#if QT_CONFIG(tooltip)
        actionSettings->setToolTip(QCoreApplication::translate("WinMain", "Open settings and configurations", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSettings->setShortcut(QCoreApplication::translate("WinMain", "Ctrl+,", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("WinMain", "About", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("WinMain", "About this program", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("WinMain", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAboutQt->setText(QCoreApplication::translate("WinMain", "About Qt", nullptr));
        menuPlayList->setTitle(QCoreApplication::translate("WinMain", "Play List", nullptr));
        menuView->setTitle(QCoreApplication::translate("WinMain", "View", nullptr));
        menuVideo->setTitle(QCoreApplication::translate("WinMain", "Video", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinMain: public Ui_WinMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINMAINXEDRYC_H
