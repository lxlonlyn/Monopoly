#ifndef _HOUSE_CPP_
#define _HOUSE_CPP_
#include "../class/house.h"
#include "player.cpp"
CHouse::CHouse(int _Level = -233, int _Belong = -1, int* _BuyPrize = NULL, int* _SalePrize = NULL, int* _PasserByPrize = NULL){
    Level = _Level; Belong = _Belong;
    if (_BuyPrize != NULL){
        for (int i = 0; i < 4; ++i){
            BuyPrize[i] = _BuyPrize[i];
        }
    }
    if (_SalePrize != NULL){
        for (int i = 0; i < 4; ++i){
            SalePrize[i] = _SalePrize[i];
        }
    }
    if (_PasserByPrize != NULL){
        for (int i = 0; i < 4; ++i){
            PasserByPrize[i] = _PasserByPrize[i];
        }
    }
}
void CHouse::Update(CPlayer &owner){
    owner.ModifyMoney(-10);
}
void CHouse::TakeDown(){

}
#endif