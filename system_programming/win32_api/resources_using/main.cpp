#include <windows.h>
#include <shellapi.h>
#include "resource.h"

HINSTANCE hInst;
HBITMAP hBitmap = nullptr;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);

void ShowClickedOption(LPCWSTR text) {
    MessageBoxW(NULL, text, L"Menu", MB_OK | MB_ICONINFORMATION);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR lpCmdLine, int nCmdShow) { 
    hInst = hInstance;

    WNDCLASS wc = { };
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"WinApiTaskClass";  
    wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON));
    wc.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_MYCURSOR));
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindow(L"WinApiTaskClass", L"WinAPI Task", WS_OVERLAPPEDWINDOW,  
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 400, NULL, NULL, hInstance, NULL);

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);

    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        {
            HMENU hMenu = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MYMENU));
            SetMenu(hwnd, hMenu);
        }
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDM_FILE_OPEN:
            ShowClickedOption(L"You clicked File -> Open");  
            break;
        case IDM_FILE_EXIT:
            PostQuitMessage(0);
            break;
        case IDM_HELP_ABOUT:
            ShellAbout(hwnd, L"WinAPI App", L"Created by Vlad", LoadIcon(hInst, MAKEINTRESOURCE(IDI_MYICON)));
            break;
        case IDM_CUSTOM_MESSAGE:
            {
                int result = MessageBox(hwnd, L"Do you like WinAPI?", L"Question", MB_YESNOCANCEL | MB_ICONQUESTION);
                switch (result) {
                    case IDYES:
                        MessageBox(hwnd, L"You pressed YES!", L"Result", MB_OK);
                        break;
                    case IDNO:
                        MessageBox(hwnd, L"You pressed NO!", L"Result", MB_OK);
                        break;
                    case IDCANCEL:
                        MessageBox(hwnd, L"You pressed CANCEL!", L"Result", MB_OK);
                        break;
                }
            }
            break;
        case IDOK:
        case IDCANCEL:
            break;
        }

        break;
    case WM_RBUTTONUP:
        DialogBox(hInst, MAKEINTRESOURCE(IDD_MYDIALOG), hwnd, DialogProc);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK DialogProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_INITDIALOG:
        {
            HBITMAP hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_MYBITMAP));
            SendDlgItemMessage(hDlg, IDC_STATIC_IMAGE, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmp);
        }
        return TRUE;
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDOK:
            EndDialog(hDlg, IDOK);
            MessageBox(hDlg, L"You pressed OK in the dialog.", L"Dialog", MB_OK);  
            return TRUE;
        case IDCANCEL:
            EndDialog(hDlg, IDCANCEL);
            MessageBox(hDlg, L"You pressed Cancel in the dialog.", L"Dialog", MB_OK);  
            return TRUE;
        }
        break;
    }
    return FALSE;
}
