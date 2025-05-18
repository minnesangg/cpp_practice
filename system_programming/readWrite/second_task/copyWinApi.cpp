#include <windows.h>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input file> <output file>\n";
        return 1;
    }

    const char* sourcePath = argv[1];
    const char* destPath = argv[2];

    HANDLE hSource = CreateFileA(
        sourcePath,
        GENERIC_READ,
        FILE_SHARE_READ,
        nullptr,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (hSource == INVALID_HANDLE_VALUE) {
        std::cerr << "Error opening source file.\n";
        return 2;
    }

    HANDLE hDest = CreateFileA( 
        destPath,
        GENERIC_WRITE,
        0,
        nullptr,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        nullptr
    );

    if (hDest == INVALID_HANDLE_VALUE) {
        std::cerr << "Error opening destination file.\n";
        CloseHandle(hSource);
        return 3;
    }

    const DWORD bufferSize = 4096;
    std::vector<char> buffer(bufferSize);
    DWORD bytesRead = 0, bytesWritten = 0;

    while (ReadFile(hSource, buffer.data(), bufferSize, &bytesRead, nullptr) && bytesRead > 0) {
        if (!WriteFile(hDest, buffer.data(), bytesRead, &bytesWritten, nullptr) || bytesRead != bytesWritten) {
            std::cerr << "Error writing to destination file.\n";
            CloseHandle(hSource);
            CloseHandle(hDest);
            return 4;
        }
    }

    std::cout << "File successfully copied via WinAPI in C++!\n";

    CloseHandle(hSource);
    CloseHandle(hDest);
    return 0;
}
