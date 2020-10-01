/****************************
 用来解决一些特殊的输出。
****************************/
#ifndef _SPECIALPRINT_CPP_
#define _SPECIALPRINT_CPP_
#include <iostream>
#include <windows.h>
using namespace std;

// 改变字体颜色
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
static void ChangeColor(int _Fore = FOREGROUND_WHITE, int _Back = BACKGROUND_BLACK, int UnderLine = 0){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 
        _Fore | _Back | (UnderLine?COMMON_LVB_UNDERSCORE:0));
}

// 缓慢输出文字
static void SlowPrint(const char* s, int WaitTime = 0){
    int len = strlen(s);
    for (int i = 0; i < len; ++i){
        cout << s[i]; Sleep(WaitTime);
    }
}

// 输出边框
// refer: http://www.unicode.org/charts/PDF/U2500.pdf
static void PrintOutline(int _up = 1, int _down = 1, int _left = 1, int _right = 1, int times = 1, int _breakline = 0){
    // only one edge
    #define ft for(int i = 1; i <= times; ++i)
    if (!_up && !_down) ft printf("\u2501");
    else if (!_left && !_right) ft printf("\u2503");
    // two edge
    else if (!_left && !_up) ft printf("\u250f");
    else if (!_right && !_up) ft printf("\u2513");
    else if (!_left && !_down) ft printf("\u2517");
    else if (!_right && !_down) ft printf("\u251b");
    // three edge
    else if (!_left) ft printf("\u2523");
    else if (!_right) ft printf("\u252b");
    else if (!_up) ft printf("\u2533");
    else if (!_down) ft printf("\u253b");
    // four edge
    else ft printf("\u254b");
    #undef ft
    if (_breakline) printf("\n");
}
#endif