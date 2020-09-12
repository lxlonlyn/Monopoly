/****************************
用来解决一些特殊的输出。
****************************/
#include <iostream>
#include <windows.h>
using namespace std;

//改变字体颜色
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
void ChangeColor(int _Fore, int _Back, int UnderLine){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
        _Fore | _Back | (UnderLine?COMMON_LVB_UNDERSCORE:0));
}

//缓慢输出文字
void SlowPrint(const char* s, int WaitTime = 0){
    int len = strlen(s);
    for (int i = 0; i < len; ++i){
        cout << s[i]; Sleep(WaitTime);
    }
}