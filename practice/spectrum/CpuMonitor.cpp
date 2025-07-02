#include "CpuMonitor.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

CpuMonitor::CpuMonitor() {
    prevStats = readCpuStats();
}

std::vector<CpuStat> CpuMonitor::readCpuStats() {
    std::ifstream file("/proc/stat");
    std::string line;
    std::vector<CpuStat> stats;

    while (std::getline(file, line)) {
        CpuStat stat;
        if (!stat.readFromLine(line)) break;
        stats.push_back(stat);
    }

    return stats;
}

std::vector<std::pair<std::string, double>> CpuMonitor::getCpuUsagePercent() {
    auto currentStats = readCpuStats();
    std::vector<std::pair<std::string, double>> result;

    if (currentStats.size() != prevStats.size()) {
        prevStats = currentStats;
        return {};
    }

    for (size_t i = 0; i < currentStats.size(); ++i) {
        auto idleDiff = currentStats[i].getIdleTime() - prevStats[i].getIdleTime();
        auto totalDiff = currentStats[i].getTotalTime() - prevStats[i].getTotalTime();

        double usage = totalDiff > 0 ? (1.0 - (double)idleDiff / totalDiff) * 100.0 : 0.0;
        result.emplace_back(currentStats[i].label, usage);
    }

    prevStats = currentStats;
    return result;
}

std::string CpuMonitor::makeBar(double percent) {
    int bars = percent / 5;
    std::string bar;

    for (int i = 0; i < bars; ++i)
        bar += "█";

    for (int i = bars; i < 20; ++i)
        bar += "-";

    return bar;
}

void CpuMonitor::render() {
    std::cout << "\033[H";
    auto usages = getCpuUsagePercent();

    if (!usages.empty()) {
        std::cout << "CPU Usage: " << std::fixed << std::setprecision(2)
                  << usages[0].second << "%  " << makeBar(usages[0].second) << "\n\n";
    }

    for (size_t i = 1; i < usages.size(); ++i) {
        std::cout << std::left << std::setw(6) << usages[i].first << " usage: "
                  << std::right << std::setw(6) << std::fixed << std::setprecision(2)
                  << usages[i].second << "%  "
                  << makeBar(usages[i].second) << "\n";
    }

    std::cout << std::endl;
}

void CpuMonitor::startMonitoring() {
    std::system("clear");
    while (true) {
        render();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
