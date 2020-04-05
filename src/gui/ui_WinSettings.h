/********************************************************************************
** Form generated from reading UI file 'WinSettingsefgVWB.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WINSETTINGSEFGVWB_H
#define WINSETTINGSEFGVWB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_WinSettings
{
public:
    QFormLayout *formLayout;
    QCheckBox *checkAutomaticFullscreen;
    QCheckBox *checkDownloadWhenCreated;
    QLabel *labelUserAgent;
    QLineEdit *lineUserAgent;
    QLabel *labelSession;
    QLineEdit *lineSession;
    QLabel *labelLibrary;
    QHBoxLayout *layoutLibrary;
    QLineEdit *lineLibrary;
    QPushButton *btnLibrary;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLabel *labelLanguage;
    QComboBox *comboLanguage;

    void setupUi(QDialog *WinSettings)
    {
        if (WinSettings->objectName().isEmpty())
            WinSettings->setObjectName(QString::fromUtf8("WinSettings"));
        WinSettings->resize(594, 344);
        formLayout = new QFormLayout(WinSettings);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        checkAutomaticFullscreen = new QCheckBox(WinSettings);
        checkAutomaticFullscreen->setObjectName(QString::fromUtf8("checkAutomaticFullscreen"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, checkAutomaticFullscreen);

        checkDownloadWhenCreated = new QCheckBox(WinSettings);
        checkDownloadWhenCreated->setObjectName(QString::fromUtf8("checkDownloadWhenCreated"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, checkDownloadWhenCreated);

        labelUserAgent = new QLabel(WinSettings);
        labelUserAgent->setObjectName(QString::fromUtf8("labelUserAgent"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelUserAgent);

        lineUserAgent = new QLineEdit(WinSettings);
        lineUserAgent->setObjectName(QString::fromUtf8("lineUserAgent"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineUserAgent);

        labelSession = new QLabel(WinSettings);
        labelSession->setObjectName(QString::fromUtf8("labelSession"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelSession);

        lineSession = new QLineEdit(WinSettings);
        lineSession->setObjectName(QString::fromUtf8("lineSession"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineSession);

        labelLibrary = new QLabel(WinSettings);
        labelLibrary->setObjectName(QString::fromUtf8("labelLibrary"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelLibrary);

        layoutLibrary = new QHBoxLayout();
        layoutLibrary->setObjectName(QString::fromUtf8("layoutLibrary"));
        lineLibrary = new QLineEdit(WinSettings);
        lineLibrary->setObjectName(QString::fromUtf8("lineLibrary"));

        layoutLibrary->addWidget(lineLibrary);

        btnLibrary = new QPushButton(WinSettings);
        btnLibrary->setObjectName(QString::fromUtf8("btnLibrary"));

        layoutLibrary->addWidget(btnLibrary);


        formLayout->setLayout(4, QFormLayout::FieldRole, layoutLibrary);

        label = new QLabel(WinSettings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(6, QFormLayout::SpanningRole, label);

        buttonBox = new QDialogButtonBox(WinSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(7, QFormLayout::SpanningRole, buttonBox);

        labelLanguage = new QLabel(WinSettings);
        labelLanguage->setObjectName(QString::fromUtf8("labelLanguage"));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelLanguage);

        comboLanguage = new QComboBox(WinSettings);
        comboLanguage->setObjectName(QString::fromUtf8("comboLanguage"));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboLanguage);


        retranslateUi(WinSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), WinSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WinSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(WinSettings);
    } // setupUi

    void retranslateUi(QDialog *WinSettings)
    {
        WinSettings->setWindowTitle(QCoreApplication::translate("WinSettings", "Settings", nullptr));
        checkAutomaticFullscreen->setText(QCoreApplication::translate("WinSettings", "Automatic fullscreen", nullptr));
        checkDownloadWhenCreated->setText(QCoreApplication::translate("WinSettings", "Download videos when they are created", nullptr));
        labelUserAgent->setText(QCoreApplication::translate("WinSettings", "User agent", nullptr));
        labelSession->setText(QCoreApplication::translate("WinSettings", "Session", nullptr));
        labelLibrary->setText(QCoreApplication::translate("WinSettings", "Video location", nullptr));
        lineLibrary->setText(QString());
        btnLibrary->setText(QCoreApplication::translate("WinSettings", "...", nullptr));
        label->setText(QCoreApplication::translate("WinSettings", "Some settings require restart to take effect", nullptr));
        labelLanguage->setText(QCoreApplication::translate("WinSettings", "Language", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinSettings: public Ui_WinSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WINSETTINGSEFGVWB_H
