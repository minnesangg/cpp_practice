#pragma once
#include "CpuStat.h"
#include <vector>
#include <string>

class CpuMonitor {
private:
    std::vector<CpuStat> prevStats;
    std::vector<CpuStat> readCpuStats();

public:
    CpuMonitor();
    std::vector<std::pair<std::string, double>> getCpuUsagePercent();
    static std::string makeBar(double percent);
    void render();
    void startMonitoring();
};
