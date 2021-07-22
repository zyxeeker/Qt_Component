//
// Created by zyx on 2021/7/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SysMemory.h" resolved

#include "memory.h"
#include "ui_Sys_Memory.h"
#include <QDebug>

SysMemory::SysMemory(QWidget *parent) :
        QWidget(parent), ui(new Ui::SysMemory) {
    ui->setupUi(this);
    connect(&thread, SIGNAL(SendMemNum(double)), this, SLOT(_SetDisplay(double)));
    thread.start();
}

SysMemory::~SysMemory() {
    thread.terminate();
    delete ui;
}

void SysMemory::_SetDisplay(double data) {
    int tmp = data * 100;
    _SetStyle(tmp);
    ui->progressBar->setValue(tmp);
}

void SysMemory::_SetStyle(int num) {
    if (num > 60)
        ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: #ffaa00;}");
    else if (num > 80)
        ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: #d60000;}");
    else
        ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: #05b8cc;}");
}