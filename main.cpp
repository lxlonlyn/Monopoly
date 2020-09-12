#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include "source/SpecialPrint.cpp"
#include "source/ReadIn.cpp"
#define BACKGROUND_YELLOW (BACKGROUND_RED | BACKGROUND_GREEN)
#define BACKGROUND_PURPLE (BACKGROUND_RED | BACKGROUND_BLUE)
#define BACKGROUND_CYAN (BACKGROUND_GREEN | BACKGROUND_BLUE)
#define BACKGROUND_BLACK 0
#define BACKGROUND_WHITE (BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN)
#define FOREGROUND_YELLOW (FOREGROUND_RED | FOREGROUND_GREEN)
#define FOREGROUND_PURPLE (FOREGROUND_RED | FOREGROUND_BLUE)
#define FOREGROUND_CYAN (FOREGROUND_GREEN | FOREGROUND_BLUE)
#define FOREGROUND_BLACK 0
#define FOREGROUND_WHITE (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)
#define NUM_ERROR -239239239
using namespace std;
int main(){
    //Init
    SetConsoleOutputCP(65001);
    system("cls");
    //Welcome
    SlowPrint("欢迎游玩本游戏！\n", 25);
    Sleep(200);
    //GameSet
    SlowPrint("请输入游玩人数（最大为 4 ）:", 25);
    int n = ReadNum(), InputErrorTime = 0;
    while (n <= 1 || n > 4){
        ++ InputErrorTime;
        if (InputErrorTime > 5) SlowPrint("...\n",30);
        else if (InputErrorTime == 5) SlowPrint("我不理你了，再见\n", 30);
        else if (InputErrorTime > 3) SlowPrint("你故意的吗？...\n", 30);
        else if (n == NUM_ERROR) SlowPrint("我不识字，我只会数数QAQ\n", 20);
        else if (n <= 0) SlowPrint("比虚无还虚无，莫非您就是大仙？\n", 20);
        else if (n == 1) SlowPrint("Poor Single Dog\n", 20);
        else if (n > 4) SlowPrint("请期待更高版本，如需要请拨打12315\n", 20);
        n = ReadNum();
    }
    SlowPrint("请稍等片刻...", 50);
    system("cls");
    //StartGame: Construct player -> print map
    //InGame: Player interact -> reprint map
    //EndGame: Show result -> clear memory
    //Last: One More? goto StartGame
    return 0;
}