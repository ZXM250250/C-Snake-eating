
//这是一个游戏逻辑具体执行的模块

//方向  上下左右
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
//链表节点类型声明  也就是蛇身
typedef struct _snake_t {
    //数据域
    int x;
    int y;

    struct _snake_t *next;//指针域
}snake_t;

//初始化蛇身和蛇头
int initSnake(void)
{
	int i = 0;

	snake_t *new = NULL;
	snake_t *tmp = NULL;


	//循环创建四个节点
	for (i = 0; i < 4; i++)
	{
		//分配空间 防止内存不够
		new = malloc(sizeof(snake_t));
		if (NULL == new)
		{
			printf("malloc initSnake failed....\n");
			return -1;
		}
		memset(new, 0, sizeof(snake_t));

		//赋值
		new->x = 24 + i * 2;
		new->y = 5;

		//头插法
		new->next = gethead();
		sethead(new);
	}


	//遍历链表
	tmp = gethead();
	while (NULL != tmp)
	{
		//设置蛇的颜色 14 黄色  达到
		setColor(14);
		//定位光标
		gotoXY(tmp->x, tmp->y);

		//第一个节点就是我们的蛇头节点
		if (gethead() == tmp)
		{
			printf("●");
		}
		else
		{
			printf("★");
		}

		tmp = tmp->next;
	}


	return 0;
}






//随机食物
int randFood(void)
{
	snake_t *tmp = NULL;

	//随机的食物不能够出现在墙壁上
	//随机的食物不能够出现在蛇身上
	//随机的食物x坐标一定是偶数

	//分配空间
	setfoodNode(malloc(sizeof(snake_t)));
	snake_t *foodNode =getfoodNode();
	if (NULL == foodNode)
	{
		gotoXY(1, 28);
		printf("malloc failed...\n");
		return -1;
	}
	memset(foodNode, 0, sizeof(snake_t));

	while (1)
	{
		while (1)
		{
			//保证X坐标是偶数 同时不应该出现在墙上(2, 54)
			foodNode->x = rand() % 53 + 3;

			if (0 == foodNode->x % 2)
			{
				break;
			}
		}

		//y坐标是（1,25）
		foodNode->y = rand() % 25 + 1;  //(0,24) --> (1, 25)

		//判断食物不能够在蛇身上
		tmp = gethead();

		while (NULL != tmp)
		{
			if ((foodNode->x == tmp->x) && (foodNode->y == tmp->y))
			{
				break;
			}

			tmp = tmp->next;
		}

		//食物没有在蛇的身上
		if (NULL == tmp)
		{
			gotoXY(foodNode->x, foodNode->y);
			setColor(12);
			printf("●");
			break;
		}
		else
		{
			continue;
		}

	}

	return 0;
}




//通过方向键控制蛇的移动
int moveKeyControl(void)
{
	//默认方向就是向右
	setdirection (RIGHT);

	while (1)
	{
		//显示右侧的小提示
		showScoreTips();

		//向上
		if (GetAsyncKeyState(VK_UP) && getdirection() != DOWN)
		{
			setdirection(UP);
		}

		//向下
		if (GetAsyncKeyState(VK_DOWN) && getdirection() != UP)
		{
			setdirection(DOWN);
		}


		//向左
		if (GetAsyncKeyState(VK_LEFT) && getdirection() != RIGHT)
		{
			setdirection(LEFT);
		}

		//向右
		if (GetAsyncKeyState(VK_RIGHT) && getdirection() != LEFT)
		{
			setdirection (RIGHT);
		}

		//按下空格暂停游戏或者继续游戏
		if (GetAsyncKeyState(VK_SPACE))
		{
			while (1)
			{
				Sleep(300);
				if (GetAsyncKeyState(VK_SPACE))
				{
					break;
				}
			}
		}



		//按下F8加速
		if (GetAsyncKeyState(VK_F8))
		{
			//减少睡眠时间  但是睡眠的时间不能小于50ms
			speedUp();
		}



		//按下F9减速
		if (GetAsyncKeyState(VK_F9))
		{
			//增加睡眠的时间
			speedDown();
		}



		//按下ESC键 结束游戏
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			//表示用户按下ESC键结束游戏
			setendStatus (3);

			endGame();

			//exit(1);
			break;
		}


		Sleep(getsleepTime());

		moveSnake();

		//判断是否撞到墙壁
		if (isHitWall())
		{
			setendStatus (1);
			endGame();
			break;
		}

		//判断是否咬到自己
		if (isBitSelf())
		{

			setendStatus (2);
			endGame();
			break;
		}
	}

	return 0;
}



//加速蛇的移动
int speedUp(void)
{
	//最快的速度 睡眠时间50ms
	if (getsleepTime() > 50)
	{
		setsleepTime (getsleepTime() - 20);
		setadd(getadd ()+ 2);
	}

	return 0;
}


//减速蛇的移动  增加睡眠的时间
int speedDown(void)
{
	if (getsleepTime() < 350)
	{
	    setsleepTime (getsleepTime() +20);
		//减少增加的分数
         setadd ( getadd ()- 2);


	}

	if (getadd ()<= 0)
	{
		setadd(  1);
	}

	return 0;
}





//控制蛇的移动    还没有写完 回来继续改
int moveSnake(void)
{
	snake_t *new = NULL;
	snake_t *tmp = NULL;
	snake_t *save = NULL;
    snake_t *head = gethead();


	//分配新的节点
	new = malloc(sizeof(snake_t));
	if (NULL == new)
	{
		printf("malloc failed...\n");
		return -1;
	}
	memset(new, 0, sizeof(snake_t));

	//向上
	if (UP == getdirection())
	{
		new->x = head->x;
		new->y = head->y - 1;
	}

	//向下
	if (DOWN == getdirection())
	{
		new->x = head->x;
		new->y = head->y + 1;
	}

	//向左
	if (LEFT == getdirection())
	{
		new->x = head->x - 2;
		new->y = head->y;
	}

	//向右
	if (RIGHT == getdirection())
	{
		new->x = head->x + 2;
		new->y = head->y;
	}

	//头插法
	new->next = head;
	sethead(new);

	tmp = gethead();
	setColor(14);


	snake_t *foodNode = getfoodNode();
	//判断是否为食物
	if ((new->x == foodNode->x) && (foodNode->y == new->y))
	{
		//循环画出蛇
		while (NULL != tmp)
		{
			gotoXY(tmp->x, tmp->y);
			if (gethead() == tmp)
			{
				printf("●");
			}
			else
			{
				printf("★");
			}

			tmp = tmp->next;
		}

		//吃掉一个食物 增加分数
		setscore( getscore() + getadd());

		//随机食物
		randFood();
	}
	else
	{
		while (NULL != tmp->next)
		{
			gotoXY(tmp->x, tmp->y);
			if (gethead() == tmp)
			{
				printf("●");
			}
			else
			{
				printf("★");
			}

			save = tmp;
			tmp = tmp->next;
		}

		//将最后一个节点释放
		gotoXY(tmp->x, tmp->y);
		setColor(3);
		printf("■");

		save->next = NULL;
		free(tmp);
	}

	return 0;
}




//判断是否撞到墙壁
int isHitWall(void)
{
    snake_t *head = gethead();
	//表示撞到墙壁
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
	{
		return 1;
	}

	//表示没有撞到墙壁
	return 0;
}

//判断是否咬到自己
int isBitSelf(void)
{
    snake_t *head = gethead();
	snake_t *tmp = NULL;

	//从第二个节点开始算
	tmp = head->next;

	while (NULL != tmp)
	{
		if ((head->x == tmp->x) && (head->y == tmp->y))
		{
			return 1;
		}

		//指向下一个节点
		tmp = tmp->next;
	}

	return 0;
}





//销毁蛇
int destroySnake(void)
{
	snake_t *tmp = NULL;
	snake_t *save = NULL;


	tmp = gethead();
	while (NULL != tmp)
	{
		save = tmp->next;
		free(tmp);

		tmp = save;
	}

	sethead(NULL);

	return 0;
}
