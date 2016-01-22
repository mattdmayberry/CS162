//////
/***********************************************
 * Item.h
 * Created by Matthew D Mayberry on 4/15/15
 * CS162_400_S2015_Assignment2
 ***********************************************/
//////

#ifndef __ITEM_H
#define __ITEM_H

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class List;  // forward declaration
class ClubItem;  // forward declaration

class Item
{
protected:
    string name;
    string unit;
    int qty;
    double cost;
    int idNum;
    double subtotal;
    
public:
    Item();
    Item(string name, string unit, int qty, double cost, int idNum);
    string getName();
    string getUnit();
    int getQty();
    double getCost();
    int getIDNum();
    void itemSubtotal(int iQty, double iCost);
    void setSubtotal(double iSub);
    double getSubtotal();
};

#endif
