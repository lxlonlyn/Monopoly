#ifndef _HOUSE_H_
#define _HOUSE_H_
#include "node.h"
class CHouse:public CNode{
private:
    int Level, Belong;
    /* 0: node 
       1: land 
       2: 1 house 
       3: 2 house
    */
    int BoughtPrize[4]={0,0,0,0};
    int SalePrize[4]={0,0,0,0};
    int PasserByPrize[4]={0,0,0,0};
public:
    CHouse();
    void Update();
    void TakeDown();
};
#endif