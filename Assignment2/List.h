//////
/***********************************************
 * List.h
 * Created by Matthew D Mayberry on 4/15/15
 * CS162_400_S2015_Assignment2
 ***********************************************/
//////

#ifndef __LIST_H
#define __LIST_H

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Item;  // forward declaration
class ClubItem;  // forward declaration

class List
{
private:
    int idNum;
    bool clubMember;
    bool memberCheck;
    vector<Item> items; // stores item objects
    
public:
    List();
    void add2List();
    void removeFromList();  // removes an item from the vector
    void print2console(); // prints both vectors to console
};
#endif