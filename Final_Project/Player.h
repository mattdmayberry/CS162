///
/***********************************************
 * Player.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include "Room.h"
#include <string> 
#include <vector>
using namespace std;

class Room; // forward declaration
class Item; // forward declaration

class Player
{
    
private:
    string playerName;
    Room* currentLocation;
    int currentPackItems;
    bool hasPack;
    bool hasKey;
    bool hasDuctTape;
    vector <Item*> packItems;
    int itemCounter;
    bool suitOn;
    bool solved;

   
public:
    Player();
    void setPlayerName(string name);
    string getPlayerName();
    void setCurrentLocation(Room* local);
    Room* getCurrentLocation();
    void lookAround(Room* ptr2room);
    void add2pack(Item* item, Room* curr);
    void removePackItem(Item* item);
    void selectPackItem(Room* curr);
    void putOnMarsSuit();
    bool getHasSuitOn();
    void setHasDuctTape(Item* itemPtr);
    void setHasKey(Item* itemPtr);
    bool getHasDuctTape();
    bool getHasKey();
    void printPackItems();
    void setSolvedProblem();
    bool getSolvedProblem();
};

#endif 
