
//这是一个游戏逻辑具体执行的模块


#include <stdio.h>
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
		//分配空间
		new = malloc(sizeof(snake_t));
		if (NULL == new)
		{
			printf("malloc initSnake failed....\n");
			return -1;
		}
		memset(new, 0, sizeof(snake_t));

		//赋值
		new->x = 24 + i * 2;
		printf("蛇的绘制流程执行了吗");
		new->y = 5;

		//头插法
		new->next = gethead();
		sethead(new);
	}


	//遍历链表
	tmp = gethead();
	while (NULL != tmp)
	{
		//设置蛇的颜色 14 黄色
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
