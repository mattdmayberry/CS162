//////
/***********************************************
 * ClubItem.h
 * Created by Matthew D Mayberry on 4/15/15
 * CS162_400_S2015_Assignment2
 ***********************************************/
//////

#ifndef __CLUBITEM_H
#define __CLUBITEM_H

#include "Item.h"
#include "List.h"
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Item;  // forward declaration
class List;  // forward declaration

class ClubItem : public Item
{
    
private:
    double clubDiscount;


protected:
    
public:
    ClubItem();
    ClubItem(string nameCI, string unitCI, int qtyCI, double costCI, int idNumCI);
};
        
#endif

