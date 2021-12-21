#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    HWND hWND = NULL;
    bool is_going = false;
    while (true) {
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD0)) return 0;
        if (GetAsyncKeyState(VK_NUMPAD1)) {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(hWND, &p);
            cout << "x-pos: " << p.x << " | y-pos: " << p.y << endl;
            Sleep(1000);
        }
        if (GetAsyncKeyState(VK_NUMPAD2)) {
            cout << boolalpha << is_going << " ";
            if (is_going) is_going = false;
            else is_going = true;
            cout << is_going << endl;
        }
        if (is_going) {
            INPUT input = { 0 };
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &input, sizeof(input));
            ZeroMemory(&input, sizeof(input));
            input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &input, sizeof(input));
        }
        
    }
}
