#include "CpuStat.h"
#include <sstream>

bool CpuStat::readFromLine(const std::string& line) {
    std::istringstream iss(line);
    if (!(iss >> label >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal))
        return false;
    return label.rfind("cpu", 0) == 0;
}

ulong CpuStat::getIdleTime() const {
    return idle + iowait;
}

ulong CpuStat::getTotalTime() const {
    return user + nice + system + idle + iowait + irq + softirq + steal;
}
