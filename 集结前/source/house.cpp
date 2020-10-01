#ifndef _HOUSE_CPP_
#define _HOUSE_CPP_
#include "../class/house.h"
#include "player.cpp"
#include "SpecialPrint.cpp"

extern CHouse houseNode[41];

CHouse::CHouse(int _level = -233, Player *_Owner = NULL, int* _BuyPrize = NULL, int* _SalePrize = NULL, int* _PasserByPrize = NULL){
    level = _level; 
	Owner = _Owner; 
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
void CHouse::Update(){
	if (level < 0 || level > 4) {
		printf("ERROR: House can't be built on this position.\n");
	}
	else if (Owner == NULL) {
		printf("ERROR: This position doesn't belong to anyone. Try SetOwner first.\n");
	}
	else if (level == 4) {
		printf("ERROR: The house is at it's highest level.\n");
	}
	else {
		if (Owner -> getMoney() < BuyPrize[level]) {
			printf("ERROR: The owner has poor money.\n");
		} else {
			Owner -> modifyMoney(-BuyPrize[level]);
			level ++;
			SlowPrint("Business done. House has been upgraded.\n");
		}
	}
}
void CHouse::TakeDown(){
	if (level < 0 || level > 4) {
		printf("ERROR: This position doesn't allow house business.\n");
	}
	else if (Owner == NULL) {
		printf("ERROR: This position doesn't belong to anyone. Try SetOwner first.\n");
	}
	else if (level == 0) {
		printf("ERROR: Only a field remain.\n");
	}
	else {
		Owner -> modifyMoney(SalePrize[level]);
		level --;
		SlowPrint("Business done. A house has been taken down.\n");
	}
}
void CHouse::SetOwner(Player* _Owner) {
	Owner = _Owner;
}
int CHouse::getBelong(){
	return belong;
}

void CHouse::changeLevel(int i){
    level += i;
} 

double CHouse::getBuyPrize(){
	return BuyPrize[level];
}

double CHouse::getSalePrize(){
	return SalePrize[level];
}

void CHouse::changeBelong(int belong1){
	belong = belong1;
}

double CHouse:: getPasserByPrize() {
	return PasserByPrize[level];
}
#endif