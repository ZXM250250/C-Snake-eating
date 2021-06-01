



//这是是一个 整个游戏中 全局变量的保存模块  也就是信息模块    以及 进行文件存储功能的模块   由于不知道codeblocks怎么去设置各个模块共享的变量
//所以这里参照java 面对对象的思想  利用方法返回变量的值  外界只能调用方法  而不能访问到变量 相当于 pravite 属性  也就是一个javabean类的作用



#include <stdio.h>
//方向  上下左右
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4





//链表节点类型声明  也就是蛇身
typedef struct _snake_t {
    //数据域
    int x;
    int y;

    struct _snake_t *next;//指针域
}snake_t;


//得分
int score = 100;



//吃掉每一个食物的得分
int add = 1;

//蛇的移动方向
int direction = RIGHT;

//睡眠时间
int sleepTime = 350;

//结束的标志
int endStatus = 0;

//链表的头指针
snake_t *head = NULL;

//食物的节点指针
snake_t *foodNode = NULL;


void setsleepTime(int num){

sleepTime =num; }

int getsleepTime(){
return sleepTime;}

void setendStatus(int num){
    endStatus = num;
}

int getendStatus(){
return endStatus;}

int getadd(){
return add;
}
void setadd(int num){
    add =num;
}

int getscore(){
    return score;
}

void setscore(int num){
    score=num;
}

int getdirection(){
    return direction;
}

void setdirection(int num){
    direction =num;
}
struct _snake_t *gethead(){
return head;
};


void sethead(struct _snake_t *h){
head = h;
}

struct _snake_t *getfoodNode(){
return foodNode;
};

void setfoodNode(struct _snake_t *h){
    foodNode = h;
}
