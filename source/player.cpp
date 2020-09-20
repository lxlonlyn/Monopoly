#ifndef _PLAYER_CPP_
#define _PLAYER_CPP_
#include "../class/player.h"
#include "alldefine.cpp"
using namespace std;
CPlayer::CPlayer(int _Money, int _Position, string _Name){
    Money = _Money; 
    Position = _Position;
    Name = _Name;
}
int CPlayer::GetPosition(){
    return Position;
}
int CPlayer::GetMoney(){
    return Money;
}
void CPlayer::ModifyMoney(int _a){
    Money += _a;
}
void CPlayer::ModifyPosition(int _a){
    Position += _a;
    if (Position >= MapSize) Position -= MapSize;
}
bool CPlayer::AbleToBuy(){
	return false;   
}
#endif