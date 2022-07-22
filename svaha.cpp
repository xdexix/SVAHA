#include "includes.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);

    system("mode con cols=122 lines=50");

    menu();
}
