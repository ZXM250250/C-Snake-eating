#include <windows.h>
#include <stdio.h>
void gotoXY(int x,int y)
{
    HANDLE handle;
    COORD coord;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(handle,coord);
}

void setColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

