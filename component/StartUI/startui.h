//
// Created by zyx on 2021/7/20.
//

#ifndef QT_COMPONENT_STARTUI_H
#define QT_COMPONENT_STARTUI_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class StartUI; }
QT_END_NAMESPACE

class StartUI : public QWidget {
Q_OBJECT

public:
    explicit StartUI(QWidget *parent = nullptr);

    ~StartUI() override;

private:
    Ui::StartUI *ui;
};


#endif //QT_COMPONENT_STARTUI_H
