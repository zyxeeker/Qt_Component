//
// Created by zyx on 2021/7/22.
//

#ifndef QT_COMPONENT_MEMORY_THREAD_H
#define QT_COMPONENT_MEMORY_THREAD_H

#include <QThread>
#include "windows.h"

class MemoryThread : public QThread {
Q_OBJECT
private:
    double _GetMemOccupy();

private:
    HANDLE m_event;

protected:
    void run() override;

signals:

    void SendMemNum(double data);

};


#endif //QT_COMPONENT_MEMORY_THREAD_H
