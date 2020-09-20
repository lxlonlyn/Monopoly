/*************************************
class CHouse: Nodes not to be painted on map
Refer node.h to view point to be painted
*************************************/
#ifndef _HOUSE_H_
#define _HOUSE_H_
#include "player.h"
class CHouse{
private:
    int Level, Belong;
    /*  
	  -2: jail
	  -1: blank(can't build house)
	   0: blank(can but no house)
       1: land 
       2: 1 house 
       3: 2 house
	   4: 3 house
    */
    int BuyPrize[4]; 
    int SalePrize[4];
    int PasserByPrize[4];
public:
    CHouse(int, int, int*, int*, int*);
    void Update(CPlayer&);			// change level
    void TakeDown();		// ����
};
#endif