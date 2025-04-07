#include <windows.h>
#include <stdio.h>  

using uint = unsigned int;

namespace first_task {

    void directories(HANDLE hConsole, TCHAR* output) {
        TCHAR buffer[MAX_PATH];
    
        GetSystemDirectory(buffer, MAX_PATH);
        wsprintf(output, TEXT("System Directory: %s\n"), buffer);
        WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
    
        GetWindowsDirectory(buffer, MAX_PATH);
        wsprintf(output, TEXT("Windows Directory: %s\n"), buffer);
        WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
    }
    
    void names(HANDLE hConsole, TCHAR* output) {
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
    
    void win_version(HANDLE hConsole, TCHAR* output) {
        OSVERSIONINFO osvi;
        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
        if (GetVersionEx(&osvi)) {
            wsprintf(output, TEXT("Windows Version: %d.%d (Build %d)\n"), 
                     osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);
            WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
        }
    }
}

namespace second_task {
    
    void print_system_info(HANDLE hConsole, TCHAR* output) {
        SYSTEM_INFO sys_info;      
        GetSystemInfo(&sys_info);

        wsprintf(output, TEXT("Number of processors: %u\n"), sys_info.dwNumberOfProcessors);
        WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
    
        wsprintf(output, TEXT("Page size: %u\n"), sys_info.dwPageSize);
        WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
    }

    void print_windows_color(HANDLE hConsole, TCHAR* output) {
        COLORREF color = GetSysColor(COLOR_WINDOW);
        uint red, green, blue;
        red = GetRValue(color);
        green = GetGValue(color);
        blue = GetBValue(color);

        wsprintf(output, TEXT("Window color: (%u, %u, %u)\n"), red, green, blue);
        WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
    }

    void print_metrics(HANDLE hConsole, TCHAR* output) {
        uint width = GetSystemMetrics(SM_CXSCREEN);
        uint height = GetSystemMetrics(SM_CYSCREEN);
    
        wsprintf(output, TEXT("Screen resolution: %u x %u\n"), width, height);
        WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
    }
}

namespace third_task {

    void mouse_and_keyboard_info(HANDLE hConsole) {
        TCHAR output[256];
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        SetConsoleMode(hInput, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

        INPUT_RECORD inputRecord;
        DWORD events;

        while (true) {
            ReadConsoleInput(hInput, &inputRecord, 1, &events);

            if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown) {
                KEY_EVENT_RECORD& keyEvent = inputRecord.Event.KeyEvent;

                COORD keyPos = { 0, 0 };
                SetConsoleCursorPosition(hConsole, keyPos);

                wsprintf(output, TEXT("ScanCode: %3u | ASCII: %3u\n"),
                         keyEvent.wVirtualScanCode,
                         keyEvent.uChar.AsciiChar);
                WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);

                COORD ctrlPos = { 0, 1 };
                SetConsoleCursorPosition(hConsole, ctrlPos);

                wsprintf(output, TEXT("CTRL: %s SHIFT: %s ALT: %s\n"),
                         (keyEvent.dwControlKeyState & (LEFT_CTRL_PRESSED | RIGHT_CTRL_PRESSED)) ? TEXT("Yes") : TEXT("No"),
                         (keyEvent.dwControlKeyState & SHIFT_PRESSED) ? TEXT("Yes") : TEXT("No"),
                         (keyEvent.dwControlKeyState & (LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED)) ? TEXT("Yes") : TEXT("No"));
                WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
            }
            else if (inputRecord.EventType == MOUSE_EVENT) {
                MOUSE_EVENT_RECORD& mouseEvent = inputRecord.Event.MouseEvent;

                COORD mousePos = { 0, 3 };
                SetConsoleCursorPosition(hConsole, mousePos);

                wsprintf(output, TEXT("Mouse Position - X: %3d Y: %3d\n"),
                         mouseEvent.dwMousePosition.X,
                         mouseEvent.dwMousePosition.Y);
                WriteConsole(hConsole, output, lstrlen(output), NULL, NULL);
            }
        }
    }
}


void show_menu(HANDLE hConsole, TCHAR* output) {
    const TCHAR *menu = TEXT("\n\n\n\n\n\t\tMENU\t\t\n1. First task\n2. Second task\n3. Third task\n4. Exit\n\n");
    WriteConsole(hConsole, menu, lstrlen(menu), NULL, NULL);
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    TCHAR output[512]; 
    int choice = 0;

    while (true) {
        show_menu(hConsole, output);
        WriteConsole(hConsole, TEXT("Choose option: "), 15, NULL, NULL);

        scanf_s("%d", &choice);

        switch (choice) {
            case 1:
                WriteConsole(hConsole, TEXT("\nFirst Task:\n"), 13, NULL, NULL);
                first_task::directories(hConsole, output);
                first_task::names(hConsole, output);
                first_task::win_version(hConsole, output);
                break;
            case 2:
                WriteConsole(hConsole, TEXT("\nSecond Task:\n"), 14, NULL, NULL);
                second_task::print_system_info(hConsole, output);
                second_task::print_windows_color(hConsole, output);
                second_task::print_metrics(hConsole, output);
                break;
            case 3:
                WriteConsole(hConsole, TEXT("\nThird Task:\n"), 14, NULL, NULL);
                third_task::mouse_and_keyboard_info(hConsole);
                break;
            case 4:
                WriteConsole(hConsole, TEXT("Closing program...\n"), 20, NULL, NULL);
                return 0;
            default:
                break;
        }
    }
    return 0;
}
