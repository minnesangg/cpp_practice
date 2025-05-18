#include <windows.h>
#include <iostream>

void printTime(const SYSTEMTIME& time, const std::string& label) {
    std::cout << label << ": "
              << time.wHour << ":" << time.wMinute << ":"
              << time.wSecond << "." << time.wMilliseconds << "\n";
}

bool copyFile(const std::string& src, const std::string& dest) {
    return CopyFileA(src.c_str(), dest.c_str(), FALSE);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <source_file> <destination_file>\n";
        return 1;
    }

    std::string sourceFile = argv[1];
    std::string destinationFile = argv[2];

    SYSTEMTIME startTime, endTime;

    GetLocalTime(&startTime);

    if (!copyFile(sourceFile, destinationFile)) {
        std::cerr << "Error copying the file.\n";
        return 1;
    }

    GetLocalTime(&endTime);

    printTime(startTime, "Start time");
    printTime(endTime, "End time");

    return 0;
}
