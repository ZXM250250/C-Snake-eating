#include <stdio.h>
#include "tools.h"
#include <windows.h>
//游戏初始界面
//绘制字符画 --蛇
int printSnake(void)
{
	//清屏
	system("cls");

	gotoXY(35, 1);
	setColor(6);
	printf("/^\\/^\\");      //蛇眼睛

	gotoXY(34, 2);
	printf("|__|  O|");      //蛇眼睛

	gotoXY(33, 2);
	setColor(2);
	printf("_");

	gotoXY(25, 3);
	setColor(12);
	printf("\\/");      	//蛇信

	gotoXY(31, 3);
	setColor(2);
	printf("/");

	gotoXY(37, 3);
	setColor(6);
	printf(" \\_/");     	//蛇眼睛

	gotoXY(41, 3);
	setColor(10);
	printf(" \\");

	gotoXY(26, 4);
	setColor(12);
	printf("\\____");   	//舌头

	gotoXY(32, 4);
	printf("_________/");

	gotoXY(31, 4);
	setColor(2);
	printf("|");

	gotoXY(43, 4);
	setColor(10);
	printf("\\");

	gotoXY(32, 5);
	setColor(2);
	printf("\\_______");    //蛇嘴

	gotoXY(44, 5);
	setColor(10);
	printf("\\");

	gotoXY(39, 6);
	printf("|##**|                  \\");  //下面都是画蛇身

	gotoXY(38, 7);
	printf("/####**/                   \\");

	gotoXY(37, 8);
	printf("/####*/                    \\*\\");

	gotoXY(35, 9);
	printf("/####**/                       \\*\\");

	gotoXY(34, 10);
	printf("/####*/                          \\**\\");

	gotoXY(33, 11);
	printf("/####*/             _----_         \\***\\");

	gotoXY(32, 12);
	printf("/####*/           _-~ *****~-_         |**|");

	gotoXY(31, 13);
	printf("(#####*(        _-~****_--_****~-_     _/**|");

	gotoXY(32, 14);
	printf("\\####*~-____-~****_-~    ~-_****~-_-~****/");

	gotoXY(33, 15);
	printf("~-_##**********_-~          ~-_*******_-~");

	gotoXY(35, 16);
	printf("~--______-~                ~-___-~");

	return 0;
}
//打印菜单
int printMenu(void)
{
    int choice;

	int i = 0;
	int j = 0;

	//输出标题
	//设置文本颜色 11
	setColor(11);
	//设置光标位置(45, 18)
	gotoXY(45, 18);
	printf("贪吃蛇Plus");

	//绘制边框
	setColor(14);
	//控制行
	for (i = 19; i <= 27; i++)
	{
		//控制列
		for (j = 27; j <= 75; j++)
		{
			//输出上下边框
			if (i == 20 || i == 26 || i == 19 || i == 27)
			{
			    if (j == 27 || j == 75)//打印四角
                {
                    if(i == 20 || i == 26)
                    {
                        gotoXY(j, i);
                        printf("|");
                    }
                }
			    else if(i==20 || i == 26)//上下内边框
                {
                    gotoXY(j, i);
                    printf("-");
				}
				else if (i == 19)//上外边框
                {
                    gotoXY(j, i);
                    printf("_");
                }
                else if (i == 27)//下外边框
                {
                    gotoXY(j, i);
                    printf("^");
                }
			}
			else if (j == 27 || j == 75)
			{
				//输出左右边框(外)
				gotoXY(j, i);
				printf("|");
			}
			else if (j==28 || j== 74 )
            {
                //输出左右边框(内)
				gotoXY(j, i);
				printf("|");
            }
			else
			{
				//注意：空格字符
				printf(" ");
			}
		}
	}

	//输出菜单选项
	//设置文本的属性
	setColor(12);

	//开始游戏
	gotoXY(35, 22);
	printf("1. 开始游戏");

	//游戏说明
	gotoXY(55, 22);
	printf("2. 游戏说明");

	//退出游戏
	gotoXY(35, 24);
	printf("3. 退出游戏");

	//输出提示信息
	gotoXY(55, 24);
	printf("请选择[1 2 3]");
	gotoXY(49, 23);
	printf("[");
	gotoXY(51, 23);
	printf("]");
	gotoXY(50, 23);

	scanf("%d", &choice);

	//清除换行符  3 \n
	getchar();

	return choice;
}
int welcome()
{
    int choice;
    printSnake();
    choice = printMenu();
    return choice;
}
