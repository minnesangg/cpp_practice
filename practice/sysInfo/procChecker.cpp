#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <iomanip> 

using ulong = unsigned long;
using uint = unsigned int;

std::string makeBar(double percent) {
    int bars = percent / 5;
    std::string bar;

    for (int i = 0; i < bars; ++i)
        bar += "█";

    for (int i = bars; i < 20; ++i)
        bar += "-";

    return bar;
}

void sleepFor(uint seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

std::pair<ulong, ulong> getCpuUsage() {
    std::ifstream file("/proc/stat");
    std::string label;
    ulong user, nice, system, idle, iowait, irq, softirq, steal;

    if(file.is_open()){
        file >> label >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;
        file.close();
    } else{
        std::cout << "Unable to open /proc/stat\n"; 
        return{0, 0};
    }

    ulong idle_time = idle + iowait;
    ulong total_time = user + nice + system + idle + iowait + irq + softirq + steal;

    return {idle_time, total_time};
}

double getCpuUsagePercent() {
    auto [idle1, total1] = getCpuUsage();
    sleepFor(1);
    auto [idle2, total2] = getCpuUsage();

    ulong totald = total2 - total1;
    ulong idled = idle2 - idle1;

    return (1.0 - (double)idled / totald) * 100.0;
}

std::vector<std::pair<ulong, ulong>> getAllCpuUsage() {
    std::ifstream file("/proc/stat");
    std::string line;
    std::vector<std::pair<ulong, ulong>> allStats;

    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.rfind("cpu", 0) == 0) { 
            std::istringstream iss(line);
            std::string label;
            ulong user, nice, system, idle, iowait, irq, softirq, steal;

            iss >> label >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;

            ulong idle_time = idle + iowait;
            ulong total_time = user + nice + system + idle + iowait + irq + softirq + steal;

            allStats.push_back({idle_time, total_time});
        } else {
            break; 
        }
    }

    return allStats;
}

std::vector<std::pair<std::string, double>> getAllCpuUsagePercent(){
    std::vector<std::pair<ulong, ulong>> allStats = getAllCpuUsage();
    sleepFor(1);
    std::vector<std::pair<ulong, ulong>> allStatsSecond = getAllCpuUsage();

    std::vector<std::pair<std::string, double>> allCpuPercent;

    for(size_t i = 0; i < allStats.size(); i++){
        auto idle1 = allStats[i].first;
        auto total1 = allStats[i].second;

        auto idle2 = allStatsSecond[i].first;
        auto total2 = allStatsSecond[i].second;

        ulong totald = total2 - total1;
        ulong idled = idle2 - idle1;

        double result = (1.0 - (double)idled / totald) * 100.0;  

        std::string cpuStr = "cpu" + std::to_string(i);

        allCpuPercent.push_back({cpuStr, result});
    } 

    return allCpuPercent;
}

void startProgramm(){
    std::system("clear");

    while (true) {
        std::cout << "\033[H"; 

        double cpu = getCpuUsagePercent();
        std::cout << "CPU Usage: " << std::fixed << std::setprecision(2) << cpu << "%\n\n";

        std::vector<std::pair<std::string, double>> allCpuPercent = getAllCpuUsagePercent();

        for (const auto& [label, percent] : allCpuPercent) {
            std::cout << std::left << std::setw(6) << label << " usage: "
                      << std::right << std::setw(6) << std::fixed << std::setprecision(2)
                      << percent << "%  "
                      << makeBar(percent) << "\n";
        }

        std::cout << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {

    startProgramm();
    
}
