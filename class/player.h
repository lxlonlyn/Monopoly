#ifndef _PLAY_H_
#define _PLAY_H_
#include <vector>
#include <cstring>
#include <string>
using namespace std;
class CPlayer{
private:
    int Money, Position;
    string Name;
public:
    CPlayer(int _Money, int _Position, string _Name);
    int GetPosition();
    int GetMoney();
    void ModifyMoney(int _a);
    void ModifyPosition(int _a);
    bool AbleToBuy();
};
#endif