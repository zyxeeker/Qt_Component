//
// Created by zyx on 2021/7/22.
//

#ifndef QT_COMPONENT_CPU_THREAD_H
#define QT_COMPONENT_CPU_THREAD_H

#include <QThread>
#include "windows.h"

class CPUThread : public QThread {
Q_OBJECT
private:
    HANDLE m_event;
    FILETIME m_preIdleTime;
    FILETIME m_preKernelTime;
    FILETIME m_preUserTime;

    FILETIME m_idleTime;
    FILETIME m_kernelTime;
    FILETIME m_userTime;

private:
    auto _GetCPUOccupy();

    long long _FileTime2LL(const FILETIME *ft);

    long long _FileTimeSub(FILETIME preTime, FILETIME nowTime);

protected:
    void run() override;

signals:

    void SendCPUNum(int data);
};


#endif //QT_COMPONENT_CPU_THREAD_H
