#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Using: run <command> <iutput_file> [args...]\n";
        return 1;
    }

    HANDLE hOutputFile = CreateFile(
        argv[2],
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hOutputFile == INVALID_HANDLE_VALUE) {
        std::cerr << "Error oppening file (" << GetLastError() << ")\n";
        return 1;
    }

    std::string command;
    for (int i = 1; i < argc; ++i) {
        if (i == 2) continue; 
        command += argv[i];
        if (i < argc - 1) command += " ";
    }

    STARTUPINFO si = { sizeof(STARTUPINFO) };
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdOutput = hOutputFile;
    si.hStdError = hOutputFile;

    PROCESS_INFORMATION pi;

    if (!CreateProcess(
        NULL,
        const_cast<char*>(command.c_str()),
        NULL,
        NULL,
        TRUE, 
        0,
        NULL,
        NULL,
        &si,
        &pi
    )) {
        std::cerr << "Error launching process (" << GetLastError() << ")\n";
        CloseHandle(hOutputFile);
        return 1;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);

    std::cout << "Process ended. Result in file: " << argv[2] << "\n";

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(hOutputFile);

    return 0;
}