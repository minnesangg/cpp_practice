#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

using ulong = unsigned long;

std::pair<ulong, ulong> getCpuUsage() {
    std::ifstream file("/proc/stat");
    std::string label;
    ulong user, nice, system, idle, iowait, irq, softirq, steal;
    file >> label >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;

    ulong idle_time = idle + iowait;
    ulong total_time = user + nice + system + idle + iowait + irq + softirq + steal;

    return {idle_time, total_time};
}

double getCpuUsagePercent() {
    auto [idle1, total1] = getCpuUsage();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    auto [idle2, total2] = getCpuUsage();

    ulong totald = total2 - total1;
    ulong idled = idle2 - idle1;

    return (1.0 - (double)idled / totald) * 100.0;
}

int main() {
    double cpu = getCpuUsagePercent();
    std::cout << "CPU Usage: " << cpu << "%\n";

}
