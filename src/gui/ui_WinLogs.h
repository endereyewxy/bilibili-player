/********************************************************************************
** Form generated from reading UI file 'WinLogsBrgbCb.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINLOGSBRGBCB_H
#define WINLOGSBRGBCB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_WinLogs
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QTableWidget *tableLogs;

    void setupUi(QDialog *WinLogs)
    {
        if (WinLogs->objectName().isEmpty())
            WinLogs->setObjectName(QString::fromUtf8("WinLogs"));
        WinLogs->resize(980, 533);
        gridLayout = new QGridLayout(WinLogs);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonBox = new QDialogButtonBox(WinLogs);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        tableLogs = new QTableWidget(WinLogs);
        if (tableLogs->columnCount() < 4)
            tableLogs->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableLogs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableLogs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableLogs->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableLogs->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableLogs->setObjectName(QString::fromUtf8("tableLogs"));
        tableLogs->setSelectionMode(QAbstractItemView::SingleSelection);
        tableLogs->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableLogs->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableLogs->horizontalHeader()->setVisible(false);
        tableLogs->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableLogs, 0, 0, 1, 1);


        retranslateUi(WinLogs);
        QObject::connect(buttonBox, SIGNAL(accepted()), WinLogs, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WinLogs, SLOT(reject()));

        QMetaObject::connectSlotsByName(WinLogs);
    } // setupUi

    void retranslateUi(QDialog *WinLogs)
    {
        WinLogs->setWindowTitle(QCoreApplication::translate("WinLogs", "Logs", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableLogs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WinLogs", "time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableLogs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WinLogs", "level", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableLogs->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WinLogs", "cause", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableLogs->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WinLogs", "msg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinLogs: public Ui_WinLogs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINLOGSBRGBCB_H
