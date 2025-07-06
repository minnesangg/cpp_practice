#pragma once

#include <string>

using ulong = unsigned long;

class MemStat {
public:
    ulong total = 0;
    ulong free = 0;
    ulong available = 0;
    ulong cached = 0;
    ulong buffers = 0;
    ulong swapTotal = 0;
    ulong swapFree = 0;

    bool parseLine(const std::string& line);
    void loadFromProc();                     
    ulong getUsed() const;                  
    ulong getSwapUsed() const;               
};
