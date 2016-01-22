///
/***********************************************
 * Item.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include "Item.h"
#include <string>


Item::Item()
{
    name = "";
    playerHas = false;
}

string Item::getItemName()
{
    return name;
}

void Item::playerNowHasItem()
{
    playerHas = true;
}

void Item::playerDropsItem()
{
    playerHas = false;
}

bool Item::getPlayerHasItem()
{
    return playerHas;
}