//////
/***********************************************
 * ClubItem.cpp
 * Created by Matthew D Mayberry on 4/15/15
 * CS162_400_S2015_Assignment2
 ***********************************************/
//////

#include <iostream>
#include <stdio.h>
#include <vector>
#include "List.h"
#include "Item.h"
#include "ClubItem.h"
using namespace std;


ClubItem::ClubItem()
{
    name = "";
    unit = "";
    qty = 0;
    cost = 0;
    idNum = 0;
    subtotal = 0;
    clubDiscount = 0.1;
}


ClubItem::ClubItem(string nameCI, string unitCI, int qtyCI, double costCI, int idNumCI)
{
    double adjCost = 0;
    clubDiscount = 0.1;
    name = nameCI;
    unit = unitCI;
    qty = qtyCI;
    adjCost = costCI * (1 -clubDiscount);
    cost = adjCost;
    idNum = idNumCI;
    itemSubtotal(qtyCI, adjCost);
}




