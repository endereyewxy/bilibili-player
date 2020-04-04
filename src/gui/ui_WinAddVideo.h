/********************************************************************************
** Form generated from reading UI file 'WinAddVideopsNgHO.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINADDVIDEOPSNGHO_H
#define WINADDVIDEOPSNGHO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WinAddVideo
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineSearch;
    QSplitter *splitter;
    QListWidget *listVideos;
    QListWidget *listClips;
    QHBoxLayout *layoutButtons;
    QPushButton *btnNew;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WinAddVideo)
    {
        if (WinAddVideo->objectName().isEmpty())
            WinAddVideo->setObjectName(QString::fromUtf8("WinAddVideo"));
        WinAddVideo->resize(1076, 685);
        verticalLayout = new QVBoxLayout(WinAddVideo);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineSearch = new QLineEdit(WinAddVideo);
        lineSearch->setObjectName(QString::fromUtf8("lineSearch"));

        verticalLayout->addWidget(lineSearch);

        splitter = new QSplitter(WinAddVideo);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        listVideos = new QListWidget(splitter);
        listVideos->setObjectName(QString::fromUtf8("listVideos"));
        listVideos->setIconSize(QSize(160, 100));
        listVideos->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listVideos->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        splitter->addWidget(listVideos);
        listClips = new QListWidget(splitter);
        listClips->setObjectName(QString::fromUtf8("listClips"));
        listClips->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listClips->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        splitter->addWidget(listClips);

        verticalLayout->addWidget(splitter);

        layoutButtons = new QHBoxLayout();
        layoutButtons->setObjectName(QString::fromUtf8("layoutButtons"));
        btnNew = new QPushButton(WinAddVideo);
        btnNew->setObjectName(QString::fromUtf8("btnNew"));

        layoutButtons->addWidget(btnNew);

        buttonBox = new QDialogButtonBox(WinAddVideo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        layoutButtons->addWidget(buttonBox);


        verticalLayout->addLayout(layoutButtons);


        retranslateUi(WinAddVideo);
        QObject::connect(buttonBox, SIGNAL(accepted()), WinAddVideo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WinAddVideo, SLOT(reject()));

        QMetaObject::connectSlotsByName(WinAddVideo);
    } // setupUi

    void retranslateUi(QDialog *WinAddVideo)
    {
        WinAddVideo->setWindowTitle(QCoreApplication::translate("WinAddVideo", "Add Video", nullptr));
        btnNew->setText(QCoreApplication::translate("WinAddVideo", "New", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinAddVideo: public Ui_WinAddVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINADDVIDEOPSNGHO_H
