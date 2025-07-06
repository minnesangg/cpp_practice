#include "MemStat.h"
#include <fstream>
#include <sstream>

bool MemStat::parseLine(const std::string& line) {
    std::istringstream iss(line);
    std::string key;
    ulong value;
    std::string kb;

    if (!(iss >> key >> value >> kb))
        return false;

    if (key == "MemTotal:") total = value;
    else if (key == "MemFree:") free = value;
    else if (key == "MemAvailable:") available = value;
    else if (key == "Buffers:") buffers = value;
    else if (key == "Cached:") cached = value;
    else if (key == "SwapTotal:") swapTotal = value;
    else if (key == "SwapFree:") swapFree = value;

    return true;
}

void MemStat::loadFromProc() {
    std::ifstream file("/proc/meminfo");
    std::string line;

    while (std::getline(file, line)) {
        parseLine(line);
    }
}

ulong MemStat::getUsed() const {
    return total - free - buffers - cached;
}

ulong MemStat::getSwapUsed() const {
    return swapTotal - swapFree;
}
