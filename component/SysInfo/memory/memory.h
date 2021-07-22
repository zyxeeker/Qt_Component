//
// Created by zyx on 2021/7/22.
//

#ifndef QT_COMPONENT_MEMORY_H
#define QT_COMPONENT_MEMORY_H

#include <QWidget>
#include "model/memory_thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SysMemory; }
QT_END_NAMESPACE

class SysMemory : public QWidget {
Q_OBJECT

public:
    explicit SysMemory(QWidget *parent = nullptr);

    ~SysMemory() override;

private:
    Ui::SysMemory *ui;
    MemoryThread thread;

private:
    void _SetStyle(int num);

private slots:

    void _SetDisplay(double data);
};


#endif //QT_COMPONENT_MEMORY_H
