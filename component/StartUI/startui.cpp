//
// Created by zyx on 2021/7/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_StartUI.h" resolved

#include "startui.h"
#include "ui_StartUI.h"


StartUI::StartUI(QWidget *parent) :
        QWidget(parent), ui(new Ui::StartUI) {
    setWindowFlag(Qt::FramelessWindowHint);
    ui->setupUi(this);
}

StartUI::~StartUI() {
    delete ui;
}

