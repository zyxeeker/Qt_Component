//
// Created by zyx on 2021/7/26.
//

#ifndef QT_COMPONENT_TOAST_H
#define QT_COMPONENT_TOAST_H

#include <QWidget>
#include <QPropertyAnimation>


QT_BEGIN_NAMESPACE
namespace Ui { class Toast; }
QT_END_NAMESPACE

class Toast : public QWidget {
Q_OBJECT
public:
    explicit Toast(QWidget *parent = nullptr);

    ~Toast() override;

    void Init(int aSpeed, int sTime);

    void SetMsg(const QString &text);

    void SetWarnMsg(const QString &text);

    void SetInfoMsg(const QString &text);

    void SetAlertMsg(const QString &text);

    void Animation();

public:
    static Toast *Create(QWidget *parent);

    static void Show(Toast *toast);

    static void Empty(const QString &text, QWidget *parent = nullptr);

    static void Info(const QString &text, QWidget *parent = nullptr);

    static void Warn(const QString &text, QWidget *parent = nullptr);

    static void Alert(const QString &text, QWidget *parent = nullptr);


protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::Toast *ui;
    QPropertyAnimation *m_inAnimation;
    QPropertyAnimation *m_outAnimation;
    int m_animationSpeed = 1000;
    int m_showTime = 8000;
};


#endif //QT_COMPONENT_TOAST_H
