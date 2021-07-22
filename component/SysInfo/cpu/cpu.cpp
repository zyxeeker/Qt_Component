//
// Created by zyx on 2021/7/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SysCPU.h" resolved

#include "cpu.h"
#include "ui_Sys_CPU.h"


SysCPU::SysCPU(QWidget *parent) :
        QWidget(parent), ui(new Ui::SysCPU) {
    ui->setupUi(this);
    connect(&thread, SIGNAL(SendCPUNum(int)), this, SLOT(_SetDisplay(int)));
    thread.start();
}

SysCPU::~SysCPU() {
    thread.terminate();
    delete ui;
}

void SysCPU::_SetDisplay(int data) {
    _SetStyle(data);
    ui->progressBar->setValue(data);
}

void SysCPU::_SetStyle(int num) {
    if (num > 60)
        ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: #ffaa00;}");
    else if (num > 80)
        ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: #d60000;}");
    else
        ui->progressBar->setStyleSheet("QProgressBar::chunk{background-color: #05b8cc;}");
}