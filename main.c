#include"headfunc.h"
#include"welcome.h"
int main()
{
    int choice;
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
    else //tansfer(choice);
    return 0;
}
