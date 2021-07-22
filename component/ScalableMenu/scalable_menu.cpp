//
// Created by zyx on 2021/7/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ScalableMenu.h" resolved

#include "scalable_menu.h"
#include "ui_Scalable_Menu.h"


ScalableMenu::ScalableMenu(int rMin, int rMax, int btnW, int btnH, int handleW, QWidget *main, QWidget *menu,
                           QWidget *parent) :
        QWidget(parent), ui(new Ui::ScalableMenu),
        m_minWidth(rMin), m_maxWidth(rMax), m_handleWidth(handleW),
        m_btnWidth(btnW), m_btnHeight(btnH),
        m_mainWidget(main), m_menuWidget(menu) {
    ui->setupUi(this);
    _Init();
}

ScalableMenu::~ScalableMenu() {
    delete ui;
}

void ScalableMenu::_Init() {
    if (m_mainWidget != nullptr && m_menuWidget != nullptr) {
        ui->main_content->addWidget(m_mainWidget);
        ui->menu_content->addWidget(m_menuWidget);
    }
    connect(ui->splitter, SIGNAL(splitterMoved(int, int)), this, SLOT(SplitterMoved(int, int)));
    ui->splitter->setHandleWidth(m_handleWidth);
    m_button = new QPushButton(this);
    ui->menu->setMaximumWidth(m_maxWidth);
    m_button->setFixedSize(m_btnWidth, m_btnHeight);
    m_button->setIconSize(QSize(m_btnWidth - 10, m_btnHeight - 10));
    m_button->setStyleSheet(
            "QPushButton{background-color: #008cba;border:none;border-top-left-radius:6px;border-bottom-left-radius:6px;}QPushButton:hover{background-color: rgb(56, 115, 254);}QPushButton:pressed{background-color: rgb(56, 115, 254);}");
    connect(m_button, &QPushButton::clicked, this, [=]() {
        BtnClicked();
    });
}

void ScalableMenu::BtnClicked() {
    QList<int> sizeList;
    if (ui->menu->width() > 0) {
        sizeList.append(ui->splitter->width());
        sizeList.append(0);
    } else {
        sizeList.append(ui->splitter->width() - ui->menu->maximumWidth());
        sizeList.append(ui->menu->maximumWidth());
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
    if (ui->menu->width() != 0) {
        m_button->setIcon(QIcon(":/SMenu/res/mClose_.png"));
    } else {
        m_button->setIcon(QIcon(":/SMenu/res/mOpen_.png"));
    }
}

void ScalableMenu::_SetBtnPos() {
    m_button->move(this->width() - ui->menu->width() - m_button->width() - 11,
                   (ui->splitter->height() - m_button->height()) / 2);
}

void ScalableMenu::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);
    _SetBtnPos();
    _SetBtnIcon();
}

void ScalableMenu::resizeEvent(QResizeEvent *event) {
    _SetBtnPos();
    QWidget::resizeEvent(event);
}

