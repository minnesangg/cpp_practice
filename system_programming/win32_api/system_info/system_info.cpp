#include <windows.h>
#include <iostream>

void directories(HANDLE hConsole, TCHAR* output){
    TCHAR buffer[MAX_PATH]; 

    GetSystemDirectory(buffer, MAX_PATH);
    wsprintf(output, TEXT("System Directory: %s\n"), buffer);
    WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);

    GetWindowsDirectory(buffer, MAX_PATH);
    wsprintf(output, TEXT("Windows Directory: %s\n"), buffer);
    WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
}

void names(HANDLE hConsole, TCHAR* output){
    TCHAR nameBuffer[256];  
    DWORD size = sizeof(nameBuffer) / sizeof(TCHAR); 
    
    if (GetComputerName(nameBuffer, &size)) {
        wsprintf(output, TEXT("Computer Name: %s\n"), nameBuffer);
        WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
    }

    size = sizeof(nameBuffer) / sizeof(TCHAR); 
    if (GetUserName(nameBuffer, &size)) {
        wsprintf(output, TEXT("User Name: %s\n"), nameBuffer);
        WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
    }
}

void win_version(HANDLE hConsole, TCHAR* output){
    OSVERSIONINFO osvi;
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if (GetVersionEx(&osvi)) {
        wsprintf(output, TEXT("Windows Version: %d.%d (Build %d)\n"), 
                 osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);
        WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
    }
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    TCHAR output[512]; 

    directories(hConsole, output);
    names(hConsole, output);
    win_version(hConsole, output);

    return 0;
}