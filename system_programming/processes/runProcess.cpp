#include <windows.h>
#include <iostream>
#include <vector>

void runProcess(const std::string& cmd) {
    STARTUPINFO si = { sizeof(STARTUPINFO) };
    PROCESS_INFORMATION pi;

    if (!CreateProcess(
        NULL,
        const_cast<char*>(cmd.c_str()),
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    )) {
        std::cerr << "Error launching: " << cmd << " (" << GetLastError() << ")\n";
        return;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);

    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);

    std::cout << cmd << " ended with code: " << exitCode << "\n";

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

int main() {
    std::vector<std::string> commands = {
        "tasm.exe test.asm",  
        "tlink.exe test.obj"  
    };

    for (const auto& cmd : commands) {
        runProcess(cmd);
    }

    return 0;
}