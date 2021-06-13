#include <windows.h>

#include <stdio.h>
//改变光标的位置函数
void gotoXY(int x,int y)
{
    HANDLE handle;
    COORD coord;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(handle,coord);
}
//改变终端的颜色函数
void setColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

