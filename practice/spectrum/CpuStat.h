#pragma once
#include <string>

using ulong = unsigned long;

class CpuStat {
public:
    std::string label;
    ulong user = 0, nice = 0, system = 0, idle = 0, iowait = 0, irq = 0, softirq = 0, steal = 0;

    bool readFromLine(const std::string& line);
    ulong getIdleTime() const;
    ulong getTotalTime() const;
};
