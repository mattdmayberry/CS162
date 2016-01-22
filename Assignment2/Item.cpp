//////
/***********************************************
 * Item.cpp
 * Created by Matthew D Mayberry on 4/15/15
 * CS162_400_S2015_Assignment2
 ***********************************************/
//////

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include "List.h"
#include "Item.h"
#include "ClubItem.h"
using namespace std;

Item::Item()
{
    name = "";
    unit = "";
    qty = 0;
    cost = 0;
    idNum = 0;
    subtotal = 0;
}

Item::Item(string nameI, string unitI, int qtyI, double costI, int idNumI)
{
    name = nameI;
    unit = unitI;
    qty = qtyI;
    cost = costI;
    idNum = idNumI;
    itemSubtotal(qtyI, costI);
}

string Item::getName()
{
    return name;
}

string Item::getUnit()
{
    return unit;
}

int Item::getQty()
{
    return qty;
}

double Item::getCost()
{
    return cost;
}

int Item::getIDNum()
{
    return idNum;
}

void Item::itemSubtotal(int iQty, double iCost)
{
    double iSub = 0;
    iSub = iCost * iQty;
    setSubtotal(iSub);
}

void Item::setSubtotal(double iSub)
{
    subtotal = iSub;
}

double Item::getSubtotal()
{
    return subtotal;
}

