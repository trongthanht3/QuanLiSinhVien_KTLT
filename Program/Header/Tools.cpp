//
// Created by Thanh on 6/2/2020.
//

#include "Tools.h"

void Tools::gotoxy(int x, int y)
{
    HANDLE handleConsole;
    COORD Cursor_an_pos = {x-1, y-1};
    handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handleConsole, Cursor_an_pos);
}

void Tools::color(int x)
{
    HANDLE _color;
    _color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(_color, x);
}