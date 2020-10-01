#ifndef _PLAYER_H
#define _PLAYER_H
#include <cstring>
#include <string>
#include <cstring>
#include <iostream>
#include<vector>
#include "house.h"
class Player{
    private:
        string name;
        int stopRound;
        int totalStep;
        int belong;
        int position; //record player position
        double money;
        int state;//player statue 0,1,2
        vector<CHouse> ownedHouse;
        int mortgagedNumber; // 在抵押状态的房子数量；

    public:
        Player (int belong1,string name1,double money1 ,int state1 ,int position1, int stopRound, int totalStep, int mortgagedNumber);//构造函数
        string getName ();//返回玩家名字的函数
        //void move(int size);//移动
        int getStopRound();
        void changeStopRound(int var);
        void deductMoney ();//扣钱
        int whetherDied ();//0为正常 1为停止 2为死亡
        double getMoney ();
        double getState ();
        void changeState(int var);
        int getPosition ();
        void changePosition (int newPosition);//改变玩家位置为新址
        int getTotalStep();
        void changeTotalStep(int var);
        // void everyStepRun();
        void buyLand();
        void buyHouse();//未写 能买否？买房否？房产加数字
        void saleHouse();//
        void saleLand();
        void modifyMoney(double rich);//未写
        void buyBack();// 赎回资产函数
};
#endif