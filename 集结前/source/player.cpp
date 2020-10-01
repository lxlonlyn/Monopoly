#ifndef _PLAYER_CPP_
#define _PLAYER_CPP_
#include <iostream>
#include <cstring>
#include "../class/player.h"
#include "house.cpp"
//#include"house.h"
using namespace std;

extern Player playerNode[5];

Player::Player(int belong1 = 0,string name1 = "nameless" ,double money1 = 0, int state1 = 0, int position1 = 1,
    int stopRound = 0, int totalStep = 0, int mortgagedNumber = 0):name(name1){
    cout<<"scan name,money,in sequence";
    state = state1;
    money = money1;
    position = position1;//初始化位置
    belong = belong1;
    cout<<"player created"<<endl;
}

string Player::getName(){
    return name;
}//返回玩家名字

int Player::getStopRound() {
    return stopRound;
}

void Player::changeStopRound(int var) {
    stopRound = var;
}

void Player::deductMoney(){
    money=money-houseNode[position].getPasserByPrize();
    playerNode[houseNode[position].getBelong()].modifyMoney(houseNode[position].getPasserByPrize());
}//扣钱及判断玩家是否卖房

// int Player::whetherDied(){
//     if(money < 0)
//         {
//             state=2;
//             return 2;
//         }
//     else
//         return 0;
// }//如果资产小于0则判定玩家死亡//没判断监狱

double Player::getMoney(){
    return money;
}

double Player::getState(){
    return state;
}

void Player::changePosition(int newPosition){
    position=newPosition;
}

int Player::getPosition(){
    return position;
}

int Player::getTotalStep() {
    return totalStep;
}

void Player::changeTotalStep(int var) {
    totalStep = var;
}

void Player::buyHouse(){
    int input;
    //询问是否升级房子,输入1升级，0不升级
    for(int j = 0; ; j++) {
        if(money >= houseNode[position].getBuyPrize()) {
            printf("If you want to update this house? Input 1 for yes, or 0 for No.");
            scanf("%d", &input);
            if(input == 1) {
                money -= houseNode[position].getBuyPrize();
                houseNode[position].changeLevel(1);
            } else {
                break;
            }
        } else {
            printf("Your money to update it is not enough.\n");
            break;
        }
        
    }//升级房子
}

void Player::buyLand() {
    int input;
        // 若钱够买地皮
    if(money>=houseNode[position].getBuyPrize()){
        printf("If you want to buy this land? Input 1 for yes, or 0 for No.");
        scanf("%d", &input);
        if(input == 1) {
            // 扣钱，房子过户
            money-=houseNode[position].getBuyPrize();
            ownedHouse.push_back(houseNode[position]);
            houseNode[position].SetOwner(this);
            houseNode[position].changeBelong(belong);
        }
    } else {
        printf("Your money to buy it is not enough.");
    }

}//买地皮

    

void Player::saleHouse() {
    for(; ownedHouse.size() > 0 && mortgagedNumber != ownedHouse.size();){
        int input;
        printf("Your owned houses:");
        // for(int i = 0; i <)
        printf("If you want to sell your owned houses?");
        if(input == 1) {}
    }
    
}

void Player::modifyMoney(double rich){
    money += rich;
}

void Player::buyBack() {
    // 在人物已有抵押地产
    for(; mortgagedNumber > 0; ) {
        printf("If you want to buy back the mortgaged land? Input 1 for yes or 0 for no.");
        int input, number;
        scanf("%d", &input);
        if(input == 1) { 
            printf("Your mortgaged land: ");
            for(int i = 0; i < ownedHouse.size(); i++) {
                if(ownedHouse[i].getLevel() == -1) {
                    printf("NO.%d, ", ownedHouse[i]);
                }    
            }
            printf("\nPlease input the number of the house to buy back it.");
            scanf("%d", &number);
            if(money >= houseNode[number].getBuyPrize()) {
                money -= houseNode[number].getBuyPrize();
                houseNode[number].changeLevel(1);
                mortgagedNumber--;
            } else {
                printf("Your money is not enough.");
                break;
            }
        } else {
            break;
        }
    }
    
    
}

//void Player::saleLand() {
    
//}

#endif