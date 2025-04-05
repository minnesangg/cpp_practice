#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HICON hIcon;
HCURSOR hCursor;

void RegisterWindowClass(HINSTANCE hInstance, const TCHAR* szClassName) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = szClassName;
    wc.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE + 1); 
    wc.hCursor = LoadCursor(NULL, IDC_WAIT);         
    wc.hIcon = LoadIcon(NULL, IDI_ERROR);           
    wc.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&wc);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    const TCHAR szClassName[] = _T("MyWindowClass");

    RegisterWindowClass(hInstance, szClassName);

    HWND hwnd = CreateWindow(
        szClassName, _T("WinAPI Window Example"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 400,
        NULL, NULL, hInstance, NULL
    );

    if (!hwnd) return 0;

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

#define HANDLE_MSG(hwnd, message, fn)    \
    case (message): return (fn)((hwnd), (wParam), (lParam))

LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam) {
    int xPos = LOWORD(lParam);
    int yPos = HIWORD(lParam);

    TCHAR buf[100];
    wsprintf(buf, _T("Mouse Left Click at: %d, %d"), xPos, yPos);

    HDC hdc = GetDC(hwnd);
    TextOut(hdc, 10, 10, buf, lstrlen(buf));
    ReleaseDC(hwnd, hdc);

    return 0;
}

LRESULT OnRButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam) {
    MessageBox(hwnd, _T("Right mouse button clicked!"), _T("Info"), MB_OK | MB_ICONINFORMATION);
    return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        HANDLE_MSG(hwnd, WM_LBUTTONDOWN, OnLButtonDown);
        HANDLE_MSG(hwnd, WM_RBUTTONDOWN, OnRButtonDown);

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
