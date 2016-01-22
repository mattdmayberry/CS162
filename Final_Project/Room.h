///
/***********************************************
 * Room.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef ROOM_H
#define ROOM_H

#include "Player.h"
#include "Item.h"
#include "Timer.h"
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

class Player; // forward declaration
class Item; // forward declaration

class Room
{
    
protected:
    string roomName;
    Room* ptrEast;
    Room* ptrWest;
    Room* ptrNorth;
    Room* ptrSouth;
    Item* item;
    bool roomHasItem;
    bool promptCheck;
    
public:
    Room();
    string getRoomName();
    void setEast(Room* e);
    Room* getEast();
    void setWest(Room* w);
    Room* getWest();
    void setNorth(Room* n);
    Room* getNorth();
    void setSouth(Room* s);
    Room* getSouth();
    void setRoomItem(Item* roomItem);
    Item* getRoomItem();
    string getRoomItemName();
    void setPlayerTakesItem(Item* takeItem);
    bool getPlayerTakesItem();
    bool getPromptCheck();
    void newItem(Item* dropItem);
    bool getRoomHasItem();
    void removeRoomItem(Item* roomItem);
    virtual void printRoomPrompt(Player* player, Timer* t, double seconds) = 0;
    
};
#endif
