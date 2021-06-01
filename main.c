<<<<<<< HEAD

=======
>>>>>>> 34d627cce1dee1f85a31d1e3d2c8f274660e3293
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
            //print_Map();
            //start_Game();
        }
        else transfer(choice);
    }
<<<<<<< HEAD
    if (choice == 1)                      //表示开始游戏
    {
        printMap();   //绘制游戏界面的地图

        showScoreTips();   //绘制游戏所得的分数和提示选项

        initSnake();   //初始化贪吃蛇
    }
    else //tansfer(choice);
=======
>>>>>>> 34d627cce1dee1f85a31d1e3d2c8f274660e3293
    return 0;
}
