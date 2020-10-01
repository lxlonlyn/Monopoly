#include <iostream>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "source/SpecialPrint.cpp"
#include "source/ReadIn.cpp"
#include "source/player.cpp"
#include "source/house.cpp"
#include "source/node.cpp"
#include "source/alldefine.cpp"
#include "source/PrintMap.cpp"
using namespace std;


int GetRandom(int l,int r){
	int res = rand() % (r - l + 1);
	return res+l;
}

int main(){
    SetConsoleOutputCP(65001);  // 编码
    
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



    // connect Chouse to CNode
    // 9/18 17:22 
    // 现给出house和node的逻辑对应关系
    // 下面的代码不能跑
    // CHouse HouseArray[41];  // 1 to 40
    // CNode NodeArray[12][12];    // 从1，1到11，11；
    // for(int i = 1; i <= 40; i++) {
    //     if(i <= 10) HouseArray[i] = NodeArray[1][i];
    //     else if(i <= 20) HouseArray[i] = NodeArray[i-10][11];
    //     else if(i <= 30) HouseArray[i] = NodeArray[11][-i+32];
    //     else HouseArray[i] = NodeArray[-i+42][1];
    // }


    //StartGame: Construct player -> print map
    ChangeColor(FOREGROUND_WHITE, BACKGROUND_BLACK, 0);
    //InGame: Player interact -> reprint map
    int playerNum;
    // 待定：一个循环包含以下内容
    if(playerNum == 1) {
        // 待定：游戏结束界面
        system("cls");
        printf("游戏结束，最终赢家为：%d号玩家！！！\n");       // 缺少确定获胜玩家的算法
    } else {
        // 进入游戏
        // 遍历每个玩家 从0 到 max
        for(int i = 1; i <= playerNum; i++) {
            // 设置环节进行的flag
            bool freeFlag = true;
            bool mortgageFlag = false;       // 抵押环节flag
            // 检查人物状态
            if(playerNode[i].getState() == 2) {    // 玩家破产
                continue;
            } else if(playerNode[i].getState() == 1) {  // 玩家监禁
                playerNode[i].changeStopRound(playerNode[i].getStopRound() - 1);
                continue;
                // 如果stopRound结束，状态改为可移动
                if(playerNode[i].getStopRound() == 0) {
                    playerNode[i].changeState(0);
                    continue;
                }
            } else {
                // 人物可以移动，进入移动环节
                // 投骰子
                srand((unsigned int)(time(NULL)));
                int step = GetRandom(1, 6);
                playerNode[i].changePosition(playerNode[i].getPosition() + step);
                playerNode[i].changeTotalStep(playerNode[i].getTotalStep() + step);    
                // changeTotalStep()函数的参数为totalStep的新值

                // 一圈结束发固定工资
                if(playerNode[i].getTotalStep() > playerNode[i].getTotalStep() % 40) {
                    playerNode[i].modifyMoney(100/*一轮加的钱*/);    // 待定，一圈结束的工资额度，double型的增加数量
                    playerNode[i].changeTotalStep(playerNode[i].getTotalStep() % 40);
                }
                
                CHouse* currentHouse = &houseNode[playerNode[i].getPosition()];
                // 若移动至监狱传送地点
                if(currentHouse->getLevel() == -1) {
                        playerNode[i].changePosition(11);      // 11号为监狱
                        playerNode[i].changeStopRound(2);      // 监狱暂停回合数（加上本回合为3回合）
                        playerNode[i].changeTotalStep(10);
                        freeFlag = false;
                        mortgageFlag = false;
                }

                // 进入自由操作环节
                if(freeFlag == true) {
                    // 此时位置为自己的房子
                    if(currentHouse->getLevel() >= 1 && currentHouse->getLevel() < 4 && currentHouse->getBelong() == i) {
                        playerNode[i].buyHouse();
                    }
                    // 此时位置为无人拥有的地皮
                    if(currentHouse->getLevel() == 0) {
                        playerNode[i].buyLand();
                        playerNode[i].buyHouse();
                    }
                    // 此时位置为别人的地皮(不是抵押状态)
                    if(currentHouse->getBelong() != i && currentHouse->getBelong() != 0) {
                        playerNode[i].deductMoney();
                        if(playerNode[i].getMoney() < 0) {
                            mortgageFlag = true;
                        }
                    }
                    // 抵押资产回收
                    playerNode[i].buyBack();

                }

                // 进入资产抵押环节
                if(mortgageFlag == true) {
                    playerNode[i].saleHouse();
                }
                
                
            }        
        }
    }


    //EndGame: Show result -> clear memory
    //Last: One More? goto StartGame
    return 0;
}

// 日志
// 2020/9/21 9:37
// 编辑main函数connect Chouse to CNode, 增加PrintMap函数
// 增加PrintMap.cpp
// main 函数增加全局变量house
