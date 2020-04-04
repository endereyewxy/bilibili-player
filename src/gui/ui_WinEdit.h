/********************************************************************************
** Form generated from reading UI file 'WinEditiYmueI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINEDITIYMUEI_H
#define WINEDITIYMUEI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_WinEdit
{
public:
    QFormLayout *formLayout;
    QLabel *labelName;
    QLabel *LabelDesc;
    QLineEdit *txtName;
    QTextEdit *txtDesc;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WinEdit)
    {
        if (WinEdit->objectName().isEmpty())
            WinEdit->setObjectName(QString::fromUtf8("WinEdit"));
        WinEdit->resize(577, 317);
        formLayout = new QFormLayout(WinEdit);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelName = new QLabel(WinEdit);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelName);

        LabelDesc = new QLabel(WinEdit);
        LabelDesc->setObjectName(QString::fromUtf8("LabelDesc"));

        formLayout->setWidget(1, QFormLayout::LabelRole, LabelDesc);

        txtName = new QLineEdit(WinEdit);
        txtName->setObjectName(QString::fromUtf8("txtName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, txtName);

        txtDesc = new QTextEdit(WinEdit);
        txtDesc->setObjectName(QString::fromUtf8("txtDesc"));

        formLayout->setWidget(1, QFormLayout::FieldRole, txtDesc);

        buttonBox = new QDialogButtonBox(WinEdit);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(WinEdit);
        QObject::connect(buttonBox, SIGNAL(accepted()), WinEdit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WinEdit, SLOT(reject()));

        QMetaObject::connectSlotsByName(WinEdit);
    } // setupUi

    void retranslateUi(QDialog *WinEdit)
    {
        WinEdit->setWindowTitle(QString());
        labelName->setText(QCoreApplication::translate("WinEdit", "Name", nullptr));
        LabelDesc->setText(QCoreApplication::translate("WinEdit", "Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinEdit: public Ui_WinEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINEDITIYMUEI_H
