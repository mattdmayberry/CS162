///
/***********************************************
 * Item.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Item
{
protected:
    string name;
    bool playerHas;
    
    
public:
    Item();
    string getItemName();
    void playerNowHasItem();
    void playerDropsItem();
    bool getPlayerHasItem();
};

#endif
