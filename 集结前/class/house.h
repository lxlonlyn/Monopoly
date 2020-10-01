/*************************************
class CHouse: Nodes not to be painted on map
Refer node.h to view point to be painted
*************************************/
#ifndef _HOUSE_H_
#define _HOUSE_H_
#include "../source/player.cpp"
class Player;
class CHouse {
private:
	Player* Owner;
    int level, belong;// 这里的belong存放owner的序号
    /*  
	  -3: jail
      -2: gateOfJail
      -1: mortgaged(owned)
	   0: blank(no owner)
       1: land (owned)
       2: 1 house 
       3: 2 house
	   4: 3 house
    */
    int BuyPrize[4]; 
    int SalePrize[4];
    int PasserByPrize[4];
public:
    CHouse(int, Player*, int*, int*, int*);
    void Update();		
    void TakeDown();	
	void SetOwner(Player*);

    int getBelong();
    int getLevel();
    void changeLevel(int i);
    double getBuyPrize();
    double getSalePrize();
    void changeBelong(int belong1);
    double getPasserByPrize();
};
#endif