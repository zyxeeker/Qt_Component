//
// Created by zyx on 2021/7/22.
//

#include "memory_thread.h"
#include <QDebug>

double MemoryThread::_GetMemOccupy() {
    MEMORYSTATUSEX stat;
    stat.dwLength = sizeof(stat);
    if (!GlobalMemoryStatusEx(&stat)) {
        return false;
    }
    double nMemFree = stat.ullAvailPhys / (1024.0 * 1024.0);
    auto nMemTotal = stat.ullTotalPhys / (1024.0 * 1024.0);
    auto nMemUsed = nMemTotal - nMemFree;
    m_event = CreateEvent(NULL, FALSE, FALSE, NULL);
    WaitForSingleObject(m_event, 1000);
    return (nMemUsed / nMemTotal);
}

void MemoryThread::run() {
    while (1)
            emit SendMemNum(_GetMemOccupy());
}