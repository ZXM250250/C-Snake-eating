


int main()
{
    int choice;
    while(1)
    {
        while(1)
        {
            choice = welcome();
            if (choice != 1 && choice != 2 && choice != 3);
            else break;
        }
        if (choice == 1)
        {
            printMap();   //绘制游戏界面的地图

        showScoreTips();   //绘制游戏所得的分数和提示选项

        initSnake();   //初始化贪吃蛇

        randFood();       //初始化随机的食物

        //通过方向键控制蛇的移动
			moveKeyControl();


        scanf("sdaj1");
        }
        else
            transfer(choice);
    }

    return 0;
}
