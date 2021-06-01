
#include <windows.h>
#pragma comment(lib, "winmm.lib")
/*播放音乐*/
void playMusic()
{


   PlaySound ("D:\\贪吃蛇\\C-\\7895.wav",NULL,SND_FILENAME | SND_ASYNC);     //内部开了一个线程进行播放音乐

}



