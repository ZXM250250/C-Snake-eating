

//这里是是一个游戏地图的绘制模块
//绘制游戏地图
int printMap(void)
{
	int i = 0;
	int j = 0;

	//清屏
	system("cls");

	//控制行
	for (i = 0; i <= 26; i++)
	{
		//控制列
		for (j = 0; j <= 56; j = j + 2)
		{
			//定位光标
			gotoXY(j, i);
			if (0 == i || 26 == i || 0 == j || 56 == j)
			{
				setColor(5);
				printf("□");
			}
			else
			{
				setColor(3);
				printf("■");
			}
		}
	}

	return 0;
}
