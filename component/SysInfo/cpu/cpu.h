//
// Created by zyx on 2021/7/22.
//

#ifndef QT_COMPONENT_CPU_H
#define QT_COMPONENT_CPU_H

#include <QWidget>
#include "model/cpu_thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SysCPU; }
QT_END_NAMESPACE

class SysCPU : public QWidget {
Q_OBJECT

public:
    explicit SysCPU(QWidget *parent = nullptr);

    ~SysCPU() override;

private:
    Ui::SysCPU *ui;
    CPUThread thread;
private:
    void _SetStyle(int data);

private slots:

    void _SetDisplay(int data);

};


#endif //QT_COMPONENT_CPU_H
