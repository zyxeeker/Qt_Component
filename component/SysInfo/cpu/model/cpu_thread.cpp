//
// Created by zyx on 2021/7/22.
//

#include "cpu_thread.h"

auto CPUThread::_GetCPUOccupy() {
    GetSystemTimes(&m_idleTime, &m_kernelTime, &m_userTime);
    m_preIdleTime = m_idleTime;
    m_preKernelTime = m_kernelTime;
    m_preUserTime = m_userTime;
    m_event = CreateEvent(NULL, FALSE, FALSE, NULL);
    WaitForSingleObject(m_event, 1000);
    GetSystemTimes(&m_idleTime, &m_kernelTime, &m_userTime);
    int idle = _FileTimeSub(m_preIdleTime, m_idleTime);
    int kernel = _FileTimeSub(m_preKernelTime, m_kernelTime);
    int user = _FileTimeSub(m_preUserTime, m_userTime);

    return (int) ceil(100.0 * (kernel + user - idle) / (kernel + user));
}

long long CPUThread::_FileTime2LL(const FILETIME *ft) {
    LARGE_INTEGER li;
    li.LowPart = ft->dwLowDateTime;
    li.HighPart = ft->dwHighDateTime;
    return li.QuadPart;
}

long long CPUThread::_FileTimeSub(FILETIME preTime, FILETIME nowTime) {
    return _FileTime2LL(&nowTime) - _FileTime2LL(&preTime);
}

void CPUThread::run() {
    while (1) {
        emit SendCPUNum(_GetCPUOccupy());
    }
}