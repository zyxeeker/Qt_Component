//
// Created by zyx on 2021/7/26.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Toast.h" resolved

#include "toast.h"
#include "ui_Toast.h"
#include <QTimer>
#include <QPropertyAnimation>
#include <QScreen>
#include <QPainter>

Toast::Toast(QWidget *parent) :
        QWidget(parent), ui(new Ui::Toast) {
    ui->setupUi(this);

    setWindowFlags(windowFlags() | Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground, true);

    m_inAnimation = new QPropertyAnimation(this, "windowOpacity");
    m_outAnimation = new QPropertyAnimation(this, "windowOpacity");
    m_inAnimation->setDuration(m_animationSpeed);
    m_inAnimation->setStartValue(0);
    m_inAnimation->setEndValue(1);
    m_outAnimation->setDuration(m_animationSpeed);
    m_outAnimation->setStartValue(1);
    m_outAnimation->setEndValue(0);
}

Toast::~Toast() {
    delete ui;
}

void Toast::Init(int aSpeed, int sTime) {
    m_animationSpeed = aSpeed;
    m_showTime = sTime;
}

void Toast::SetMsg(const QString &text) {
    ui->icon->hide();
    ui->label->setText(text);
}

void Toast::SetWarnMsg(const QString &text) {
    ui->icon->setPixmap(QPixmap(":/MessageBox/res/caution_filled.png"));
    ui->label->setText(text);
}

void Toast::SetAlertMsg(const QString &text) {
    ui->icon->setPixmap(QPixmap(":/MessageBox/res/forbidden_filled.png"));
    ui->label->setText(text);
}

void Toast::SetInfoMsg(const QString &text) {
    ui->icon->setPixmap(QPixmap(":/MessageBox/res/info_filled.png"));
    ui->label->setText(text);
}

void Toast::Animation() {
    m_inAnimation->start();
    show();
    QTimer::singleShot(m_showTime, [&] {
        m_outAnimation->start();
        connect(m_outAnimation, &QPropertyAnimation::finished, [&] {
            close();
            deleteLater();
        });
    });
}

Toast *Toast::Create(QWidget *parent) {
    Toast *toast = new Toast(parent);
    toast->setWindowFlags(toast->windowFlags() | Qt::WindowStaysOnTopHint); // 置顶
    return toast;
}

void Toast::Show(Toast *toast) {
    toast->adjustSize();
    QScreen *pScreen = QGuiApplication::primaryScreen();
    toast->move((pScreen->size().width() - toast->width()) / 2, pScreen->size().height() * 7 / 10);
    toast->Animation();
}

void Toast::Empty(const QString &text, QWidget *parent) {
    Toast *toast = Create(parent);
    toast->SetMsg(text);
    Show(toast);
}

void Toast::Info(const QString &text, QWidget *parent) {
    Toast *toast = Create(parent);
    toast->SetInfoMsg(text);
    Show(toast);
}

void Toast::Warn(const QString &text, QWidget *parent) {
    Toast *toast = Create(parent);
    toast->SetWarnMsg(text);
    Show(toast);
}

void Toast::Alert(const QString &text, QWidget *parent) {
    Toast *toast = Create(parent);
    toast->SetAlertMsg(text);
    Show(toast);
}

void Toast::paintEvent(QPaintEvent *event) {
    QPainter paint(this);
    paint.begin(this);
    auto kBackgroundColor = QColor(255, 255, 255);
    kBackgroundColor.setAlpha(0.0 * 255);// 透明度为0
    paint.setRenderHint(QPainter::Antialiasing, true);
    paint.setPen(Qt::NoPen);
    paint.setBrush(QBrush(kBackgroundColor, Qt::SolidPattern));//设置画刷形式
    paint.drawRect(0, 0, width(), height());
    paint.end();
}