/********************************************************************************
** Form generated from reading UI file 'WinDownloadingrmaRPh.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINDOWNLOADINGRMARPH_H
#define WINDOWNLOADINGRMARPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>

QT_BEGIN_NAMESPACE

class Ui_WinDownloading
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QProgressBar *progress;
    QListWidget *listQueue;

    void setupUi(QDialog *WinDownloading)
    {
        if (WinDownloading->objectName().isEmpty())
            WinDownloading->setObjectName(QString::fromUtf8("WinTasks"));
        WinDownloading->resize(616, 509);
        gridLayout = new QGridLayout(WinDownloading);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(WinDownloading);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(WinDownloading);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 1);

        progress = new QProgressBar(WinDownloading);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setMaximum(0);
        progress->setValue(0);

        gridLayout->addWidget(progress, 1, 0, 1, 1);

        listQueue = new QListWidget(WinDownloading);
        listQueue->setObjectName(QString::fromUtf8("listQueue"));

        gridLayout->addWidget(listQueue, 2, 0, 1, 1);


        retranslateUi(WinDownloading);
        QObject::connect(buttonBox, SIGNAL(accepted()), WinDownloading, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WinDownloading, SLOT(reject()));

        QMetaObject::connectSlotsByName(WinDownloading);
    } // setupUi

    void retranslateUi(QDialog *WinDownloading)
    {
        WinDownloading->setWindowTitle(QCoreApplication::translate("WinTasks", "Downloading", nullptr));
        label->setText(QCoreApplication::translate("WinTasks", "Nothing to do", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinTasks: public Ui_WinDownloading {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINDOWNLOADINGRMARPH_H
