#include "iostream"
#include <Windows.h>

void MoveCursor()
{
    static bool EnableMove = true;
    POINT cc;
    while (true)
    {
        int ms = 0;
        while (GetAsyncKeyState(VK_LCONTROL) && EnableMove && ms < 1500) // Движение курсора по оси X
        {
            GetCursorPos(&cc);
            SetCursorPos(cc.x, cc.y + 1);
            Sleep(1);
            ms++;
        }
        ms = 0;

        while (GetAsyncKeyState(VK_LCONTROL) && EnableMove && ms < 1500) // Движение курсора по отрицательной оси Y
        {
            GetCursorPos(&cc);
            SetCursorPos(cc.x + 1, cc.y);
            Sleep(1);
            ms++;
        }
        ms = 0;
    }
}

int main()
{
    MoveCursor();
}