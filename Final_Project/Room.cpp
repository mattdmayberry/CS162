///
/***********************************************
 * Room.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Item.h"
#include "Player.h"

Room::Room()
{
    roomName = "";
    roomHasItem = false;
}

string Room::getRoomName()
{
    return roomName;
}

void Room::setEast(Room* e)
{
    ptrEast = e;
}

Room* Room::getEast()
{
    return ptrEast;
}

void Room::setWest(Room* w)
{
    ptrWest = w;
}

Room* Room::getWest()
{
    return ptrWest;
}

void Room::setNorth(Room* n)
{
    ptrNorth = n;
}

Room* Room::getNorth()
{
    return ptrNorth;
}

void Room::setSouth(Room* s)
{
    ptrSouth = s;
}

Room* Room::getSouth()
{
    return ptrSouth;
}

void Room::setRoomItem(Item* roomItem)
{
    item = roomItem;
    roomHasItem = true;
}

Item* Room::getRoomItem()
{
    return item;
}

string Room::getRoomItemName()
{
    return item->getItemName();
}

void Room::setPlayerTakesItem(Item* takeItem)
{
    takeItem->playerNowHasItem(); // set player has item to true
}

bool Room::getPlayerTakesItem()
{
    return item->getPlayerHasItem(); // check if the player has the item
}

void Room::newItem(Item* dropItem)
{
    dropItem->playerDropsItem(); // set player has item to false
    roomHasItem = true; // set room has item to true
    setRoomItem(dropItem); // set the room item to item
}

bool Room::getRoomHasItem()
{
    return roomHasItem;
}

void Room::removeRoomItem(Item* roomItem)
{
    roomHasItem = false;
}

bool Room::getPromptCheck()
{
    return promptCheck; // bool check to see if the player has already seen the prompt
}

