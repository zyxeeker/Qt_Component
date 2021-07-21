//
// Created by zyx on 2021/7/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ScalableMenu.h" resolved

#include "scalablemenu.h"
#include "ui_ScalableMenu.h"
#include <QDebug>

ScalableMenu::ScalableMenu(int rMin, int rMax, int btnW, int btnH, int handleW, QWidget *parent) :
        QWidget(parent), ui(new Ui::ScalableMenu),
        m_minWidth(rMin), m_maxWidth(rMax), m_handleWidth(handleW),
        m_btnWidth(btnW), m_btnHeight(btnH) {
    ui->setupUi(this);
    _Init();
}

ScalableMenu::~ScalableMenu() {
    delete ui;
}

void ScalableMenu::_Init() {
    connect(ui->splitter, SIGNAL(splitterMoved(int, int)), this, SLOT(SplitterMoved(int, int)));
    m_button = new QPushButton(this);
    ui->right_frame->setMaximumWidth(m_maxWidth);
    m_button->setFixedSize(m_btnWidth, m_btnHeight);
    m_button->setIconSize(QSize(m_btnWidth - 10, m_btnHeight - 10));
    m_button->setStyleSheet(
            "QPushButton{background-color: #008cba;border:none;border-radius:5px;}QPushButton:hover{background-color: rgb(56, 115, 254);}QPushButton:pressed{background-color: rgb(56, 115, 254);}");
    connect(m_button, &QPushButton::clicked, this, [=]() {
        BtnClicked();
    });
}

void ScalableMenu::BtnClicked() {
    QList<int> sizeList;
    if (ui->right_frame->width() > 0) {
        sizeList.append(ui->splitter->width());
        sizeList.append(0);
    } else {
        sizeList.append(ui->splitter->width() - ui->right_frame->maximumWidth());
        sizeList.append(ui->right_frame->maximumWidth());
    }
    ui->splitter->setSizes(sizeList);
    _SetBtnPos();
    _SetBtnIcon();
}

void ScalableMenu::SplitterMoved(int pos, int index) {
    _SetBtnPos();
    _SetBtnIcon();
}

void ScalableMenu::_SetBtnIcon() {
    qDebug() << ui->right_frame->width();
    if (ui->right_frame->width() != 0) {
        m_button->setIcon(QIcon(":/SMenu/res/mClose_.png"));
    } else {
        m_button->setIcon(QIcon(":/SMenu/res/mOpen_.png"));
    }
}

void ScalableMenu::_SetBtnPos() {
    m_button->move(this->width() - ui->right_frame->width() - m_button->width() - 11,
                   (ui->splitter->height() - m_button->height()) / 2);
}

void ScalableMenu::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    _SetBtnPos();
    _SetBtnIcon();
}

void ScalableMenu::resizeEvent(QResizeEvent *event) {
    _SetBtnPos();
    qDebug() << ui->right_frame->geometry();
    QWidget::resizeEvent(event);
}

