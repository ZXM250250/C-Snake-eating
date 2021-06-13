#include<stdio.h>
#include<windows.h>
//绘制说明界面和退出游戏的界面
void complain()
{
    int i = 0;
	int j = 0;

	//清屏
	system("cls");

	//输出标题
	setColor(13);
	gotoXY(44, 3);
	printf("游戏说明");

	//绘制上下左右边框
	//控制行
	for (i = 6; i <= 22; i++)
	{
		//控制列
		for (j = 20; j <= 75; j++)
		{
			//上下边框 =
			if (i == 6 || i == 22)
			{
				gotoXY(j, i);
				printf("=");
			}
			else if (j == 20 || j == 75)
			{
				gotoXY(j, i);
				printf("|");
			}
			else
			{

			}
		}
	}

	//输出菜单选项
	setColor(3);
	gotoXY(30, 8);
	printf("☆ 1. 不能撞到墙，不能咬到自己");

	setColor(5);
	gotoXY(30, 11);
	printf("☆ 2. F1加速前进，F2减速前进");

	setColor(11);
	gotoXY(30, 14);
	printf("☆ 3. 使用空格暂停游戏或者继续游戏");

	setColor(13);
	gotoXY(30, 17);
	printf("☆ 4. 使用方向键控制前进的方向");

	setColor(14);
	gotoXY(30, 20);
	printf("☆ 5. 按下ESC键退出游戏");

	//输出提示信息
	setColor(12);
	gotoXY(20, 24);
	printf("按下任意键返回主界面，");

}
void transfer(int c)
{
    if (c == 3)
    {
        exit(0);
    }
    else if (c == 2)
    {
        complain();
        system("pause");
    }
}
