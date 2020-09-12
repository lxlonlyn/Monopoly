#include "../class/player.h"
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
void CPlayer::ModifyPosition(int _a){
    Money += _a;
}
void CPlayer::ModifyMoney(int _a){
    Position += _a;
    if (Position >= MapSize) Position -= MapSize;
}
bool CPlayer::AbleToBuy(){
    
}