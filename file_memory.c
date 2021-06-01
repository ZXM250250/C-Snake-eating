#include <stdio.h>


//这一个模块 用于 游戏中各种文件数据的存储功能模块



//读取文件中最高分  最高分保存在sava.txt文件中
int readFile(void)
{
	int ret = -1;
	char buf[32];

	FILE *fp = NULL;

	//1. 以只读的方式打开文件
	fp = fopen("save.txt", "r");
	if (NULL == fp)
	{
		printf("fopen failed...\n");
		return 0;
	}

	//2. 读取文件内容
	memset(buf, 0, sizeof(buf));
	ret = fread(buf, sizeof(char), sizeof(buf), fp);
	if (ret <= 0)
	{
		printf("fread failed...\n");
		return 0;
	}


	//3. 关闭文件
	fclose(fp);

	//atoi --> 将字符串的数字转化为数字  "123" --> 123
	return atoi(buf);
}




//将最高分写入文件中
int writeFile(int score)
{
	FILE *fp = NULL;

	//打开文件
	fp = fopen("save.txt", "w+");
	if (NULL == fp)
	{
		printf("打开文件失败\n");
		return -1;
	}

	//将最高分写入文件中
	fprintf(fp, "%d", score);

	//关闭文件
	fclose(fp);

	return 0;
}

