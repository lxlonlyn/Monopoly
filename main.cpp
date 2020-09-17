#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "source/SpecialPrint.cpp"
#include "source/ReadIn.cpp"
#include "source/player.cpp"
#include "source/house.cpp"
#include "source/alldefine.cpp"
//extern const int MapSize = 100;
using namespace std;
int GetRandom(int l,int r){
	int res = rand() % (r - l + 1);
	return res+l;
}
int main(){
    SetConsoleOutputCP(65001);
    
    PrintOutline(0,1,0,1);
    PrintOutline(0,0,1,1,3);
    PrintOutline(0,1,1,1);
    PrintOutline(0,0,1,1,3);
    PrintOutline(0,1,1,0,1,1);

    PrintOutline(1,1,0,0);
    printf("   ");
    PrintOutline(1,1,0,0);
    printf("   ");
    PrintOutline(1,1,0,0,1,1);

    PrintOutline(1,0,0,1);
    PrintOutline(0,0,1,1,3);
    PrintOutline(1,0,1,1);
    PrintOutline(0,0,1,1,3);
    PrintOutline(1,0,1,0,1,1);
    //Init
	srand((unsigned int)(time(NULL)));
    SetConsoleOutputCP(65001);
    //system("cls");
    //Welcome
    SlowPrint("\u6b22\u8fce\u6e38\u73a9\u672c\u6e38\u620f\uff01\n", 25);
    Sleep(200);
    //GameSet
    SlowPrint("\u8bf7\u8f93\u5165\u6e38\u73a9\u4eba\u6570\uff08\u6700\u5927\u4e3a 4 \uff09:", 25);
    int n = ReadNum(), InputErrorTime = 0;
    while (n <= 1 || n > 4){
        ++ InputErrorTime;
        if (InputErrorTime > 5) SlowPrint("...\n",30);
        else if (InputErrorTime == 5) SlowPrint("\u6211\u4e0d\u7406\u4f60\u4e86\uff0c\u518d\u89c1\n", 30);
        else if (InputErrorTime > 3) SlowPrint("\u4f60\u6545\u610f\u7684\u5417\uff1f...\n", 30);
        else if (n == NUM_ERROR) SlowPrint("\u6211\u4e0d\u8bc6\u5b57\uff0c\u6211\u53ea\u4f1a\u6570\u6570QAQ\n", 20);
        else if (n <= 0) SlowPrint("\u6bd4\u865a\u65e0\u8fd8\u865a\u65e0\uff0c\u83ab\u975e\u60a8\u5c31\u662f\u5927\u4ed9\uff1f\n", 20);
        else if (n == 1) SlowPrint("Poor Single Dog\n", 20);
        else if (n > 4) SlowPrint("\u8bf7\u671f\u5f85\u66f4\u9ad8\u7248\u672c\uff0c\u5982\u9700\u8981\u8bf7\u62e8\u625312315\n", 20);
        n = ReadNum();
    }
    SlowPrint("\u8bf7\u7a0d\u7b49\u7247\u523b...", 50);
    system("cls");
    //StartGame: Construct player -> print map
    //ChangeColor(FOREGROUND_BLACK, BACKGROUND_YELLOW, 1);
    ChangeColor(FOREGROUND_WHITE, BACKGROUND_BLACK, 0);
    //InGame: Player interact -> reprint map
    //EndGame: Show result -> clear memory
    //Last: One More? goto StartGame
    return 0;
}