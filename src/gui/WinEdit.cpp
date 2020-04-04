//
// Created by endereyewxy@gmail.com on 4/3/20.
//

#include "WinEdit.h"
#include "ui_WinEdit.h"

WinEdit::WinEdit(QWidget *parent) : QDialog(parent), ui(new Ui::WinEdit) {
    ui->setupUi(this);
    connect(this, &QDialog::accepted, [=]() {
        emit confirmed({
            ui->txtName->text(),
            ui->txtDesc->toPlainText()
        });
    });
}

void WinEdit::open(const Playlist::Info &info) {
    ui->txtName->setText(info.name);
    ui->txtDesc->setText(info.desc);
    QDialog::open();
}

WinEdit::~WinEdit() {
    delete ui;
}
