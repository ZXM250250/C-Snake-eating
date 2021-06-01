

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
