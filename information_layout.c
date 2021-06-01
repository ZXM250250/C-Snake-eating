

//这里是一个信息的绘制模块  包括游戏过程中的提示 分数 以及游戏结束以后的结算页面绘制
//显示分数和提示信息
int showScoreTips(void)
{
	int highScore = 0;

	//从文件中读取最高分

	highScore = readFile();
	//显示最高分
	setColor(3);
	gotoXY(64, 4);
	printf("☆☆最高分记录☆☆: %d", highScore);

	//显示当前得分
	setColor(14);
	gotoXY(64, 8);
	printf("得分: %d", getscore());

	//显示温馨提示
	setColor(12);
	gotoXY(72, 11);
	printf("温 馨 提 示");

	//绘制上下边框
	setColor(10);
	gotoXY(60, 13);
	printf("==================================");

	gotoXY(60, 25);
	printf("==================================");

	//输出提示信息
	setColor(13);
	gotoXY(64, 14);
	printf("※ 吃掉每个食物得分: %d", getadd());

	gotoXY(64, 16);
	printf("※ 不能撞到墙壁，不能咬到自己");

	gotoXY(64, 18);
	printf("※ F1加速前进，F2减速前进");

	gotoXY(64, 20);
	printf("※ 使用空格暂停游戏或者继续游戏");

	gotoXY(64, 22);
	printf("※ 使用↓↑→←控制前进的方向");

	gotoXY(64, 24);
	printf("※ 按下ESC退出游戏");

	return 0;
}



//结束游戏
int endGame(void)
{
	int n = 0;
	int highScore = 0;

	while (1)
	{
		//显示游戏失败界面
		failGameUi();

		setColor(12);
		gotoXY(38, 9);

		//不同的状态 显示不同失败提示 endStatus
		switch (getendStatus())
		{
			//撞到墙壁
		case 1:
			printf("您撞到墙了，游戏结束!!!");
			break;

			//咬到自己
		case 2:
			printf("您咬到蛇身了，游戏结束!!!");
			break;

			//用户按下ESC
		case 3:
			printf("您已经结束了游戏，游戏结束!!!");
			break;

		default:
			;
		}

		//显示您的得分
		setColor(13);
		gotoXY(43, 12);
		printf("您的得分: %d", getscore());

		//显示最高分
		//从文件中读取最高分
		highScore = readFile();

		if (getscore() > highScore)
		{
			setColor(10);
			gotoXY(38, 16);
			printf("恭喜你，您已经破纪录了。");

			//将最高分写入文件
			writeFile(getscore());
		}
		else
		{
			setColor(10);
			gotoXY(38, 16);
			printf("加油哦， 离最高分还差%d分", highScore - getscore());
		}

		//输出用户选择的信息
		gotoXY(25, 23);
		setColor(12);
		printf("再玩一局请输入：1");

		gotoXY(52, 23);
		printf("直接退出请输入：2");

		gotoXY(46, 25);
		setColor(11);
		printf("请选择: ");

		scanf("%d", &n);
		getchar();

		if (1 == n)
		{
			setscore( 0);
			setsleepTime (350);
			setadd(  1);

			//销毁蛇
			destroySnake();

			break;
		}
		else if (2 == n)
		{
			exit(0);
		}
		else
		{
			gotoXY(30, 27);
			setColor(12);
			printf("您的输入有误，请重新输入，按下回车键继续");
			getchar();
		}
	}
	return 0;
}



//游戏失败界面边框
void failGameUi(void)
{
	int i = 0;

	//清屏
	system("cls");

	//显示游戏失败提示
	setColor(12);
	gotoXY(44, 3);
	printf("游 戏 失 败!!!");

	//设置边框的颜色
	setColor(11);
	gotoXY(17, 5);

	//绘制上边框
	printf("+----------------------------------------------------------------+");

	//绘制下边框
	gotoXY(17, 20);
	printf("+----------------------------------------------------------------+");

	//绘制左右边框
	for (i = 6; i < 20; i++)
	{
		gotoXY(17, i);
		printf("|");

		gotoXY(82, i);
		printf("|");
	}
}




