#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
using namespace std;
int main(){
    system("chcp 65001");
    system("cls");
    cout<<"欢迎游玩本游戏！\n";
    cout<<"请输入游玩人数（最大为 4 ）:";
    char ch=getchar(); int f=1;
    while (ch<'0'||ch>'9'){
        if (ch=='-') f=-1; ch=getchar();
    }
    int n=0; //cin>>n;
    while (ch>='0'&&ch<='9'){
        n=(n<<1)+(n<<3)+ch-'0'; ch=getchar();
    }
    while (n<=1||n>4){
        if (n<1) cout<<"你确定这里有人吗？\n";
        if (n==1) cout<<"一个人也是挺孤独的呢。\n";
        if (n>4) cout<<"最大 4 个人。\n";
        ch=getchar(); f=1;
        while (ch<'0'||ch>'9') ch=getchar();
        n=0; //cin>>n;
        while (ch>='0'&&ch<='9'){
            n=(n<<1)+(n<<3)+ch-'0'; ch=getchar();
        }
    }
    cout<<"请稍等片刻...\n";
    system("cls");
    //cout.clear();
    //cout<<"clearend";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_GREEN | COMMON_LVB_UNDERSCORE);
    for (int i=1;i<=5;++i) cout<<"| ";
    cout<<"|1";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN | COMMON_LVB_UNDERSCORE);
    for (int i=1;i<=2;++i) cout<<"| ";
    cout<<"|2";
    cout<<"|\n";
    printf("欢迎下次再来！\n");
    system("pause");
    return 0;
}
