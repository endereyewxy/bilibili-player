/********************************************************************************
** Form generated from reading UI file 'WinInfoRMUxGT.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WININFORMUXGT_H
#define WININFORMUXGT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_WinInfo
{
public:
    QFormLayout *layout;
    QLabel *labelName;
    QLabel *txtName;
    QLabel *labelBVID;
    QHBoxLayout *layoutBVID;
    QLabel *txtBVID;
    QPushButton *btnBVID;
    QLabel *labelAuth;
    QHBoxLayout *layoutAuth;
    QLabel *txtAuth;
    QPushButton *btnAuth;
    QLabel *labelDesc;
    QTextBrowser *txtDesc;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WinInfo)
    {
        if (WinInfo->objectName().isEmpty())
            WinInfo->setObjectName(QString::fromUtf8("WinInfo"));
        WinInfo->resize(790, 565);
        layout = new QFormLayout(WinInfo);
        layout->setObjectName(QString::fromUtf8("layout"));
        labelName = new QLabel(WinInfo);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        layout->setWidget(0, QFormLayout::LabelRole, labelName);

        txtName = new QLabel(WinInfo);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setWordWrap(true);

        layout->setWidget(0, QFormLayout::FieldRole, txtName);

        labelBVID = new QLabel(WinInfo);
        labelBVID->setObjectName(QString::fromUtf8("labelBVID"));

        layout->setWidget(1, QFormLayout::LabelRole, labelBVID);

        layoutBVID = new QHBoxLayout();
        layoutBVID->setObjectName(QString::fromUtf8("layoutBVID"));
        txtBVID = new QLabel(WinInfo);
        txtBVID->setObjectName(QString::fromUtf8("txtBVID"));

        layoutBVID->addWidget(txtBVID);

        btnBVID = new QPushButton(WinInfo);
        btnBVID->setObjectName(QString::fromUtf8("btnBVID"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnBVID->sizePolicy().hasHeightForWidth());
        btnBVID->setSizePolicy(sizePolicy);

        layoutBVID->addWidget(btnBVID);


        layout->setLayout(1, QFormLayout::FieldRole, layoutBVID);

        labelAuth = new QLabel(WinInfo);
        labelAuth->setObjectName(QString::fromUtf8("labelAuth"));

        layout->setWidget(2, QFormLayout::LabelRole, labelAuth);

        layoutAuth = new QHBoxLayout();
        layoutAuth->setObjectName(QString::fromUtf8("layoutAuth"));
        txtAuth = new QLabel(WinInfo);
        txtAuth->setObjectName(QString::fromUtf8("txtAuth"));

        layoutAuth->addWidget(txtAuth);

        btnAuth = new QPushButton(WinInfo);
        btnAuth->setObjectName(QString::fromUtf8("btnAuth"));
        sizePolicy.setHeightForWidth(btnAuth->sizePolicy().hasHeightForWidth());
        btnAuth->setSizePolicy(sizePolicy);

        layoutAuth->addWidget(btnAuth);


        layout->setLayout(2, QFormLayout::FieldRole, layoutAuth);

        labelDesc = new QLabel(WinInfo);
        labelDesc->setObjectName(QString::fromUtf8("labelDesc"));

        layout->setWidget(3, QFormLayout::LabelRole, labelDesc);

        txtDesc = new QTextBrowser(WinInfo);
        txtDesc->setObjectName(QString::fromUtf8("txtDesc"));

        layout->setWidget(3, QFormLayout::FieldRole, txtDesc);

        buttonBox = new QDialogButtonBox(WinInfo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        layout->setWidget(4, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(WinInfo);
        QObject::connect(buttonBox, SIGNAL(accepted()), WinInfo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WinInfo, SLOT(reject()));

        QMetaObject::connectSlotsByName(WinInfo);
    } // setupUi

    void retranslateUi(QDialog *WinInfo)
    {
        WinInfo->setWindowTitle(QCoreApplication::translate("WinInfo", "Information", nullptr));
        labelName->setText(QCoreApplication::translate("WinInfo", "Title", nullptr));
        txtName->setText(QString());
        labelBVID->setText(QCoreApplication::translate("WinInfo", "BVID", nullptr));
        txtBVID->setText(QString());
        btnBVID->setText(QCoreApplication::translate("WinInfo", "...", nullptr));
        labelAuth->setText(QCoreApplication::translate("WinInfo", "Author", nullptr));
        txtAuth->setText(QString());
        btnAuth->setText(QCoreApplication::translate("WinInfo", "...", nullptr));
        labelDesc->setText(QCoreApplication::translate("WinInfo", "Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinInfo: public Ui_WinInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WININFORMUXGT_H
