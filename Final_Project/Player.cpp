///
/***********************************************
 * Player.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include "Player.h"
#include "Room.h"
#include "Module_1.h"
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;



Player::Player()
{
    playerName = "";
    hasPack = false;
    itemCounter = 0;
    solved = false;
}

void Player::setPlayerName(string name)
{
    playerName = name;
}

string Player::getPlayerName()
{
    return playerName;
}

void Player::setCurrentLocation(Room* local)
{
    currentLocation = local;
}

Room* Player::getCurrentLocation()
{
    return currentLocation;
}

void Player::lookAround(Room* ptr2room)
{
    int selection = 0;
    Item* item = ptr2room->getRoomItem();
    
    if(ptr2room->getRoomHasItem() == true)
    {
        cout << endl;
        cout << "You found a " << ptr2room->getRoomItemName() << "!" << endl;
        cout << "Would you like to pick it up?" << endl;
        cout << "1) Yes." << endl;
        cout << "2) No." << endl;
        cin >> selection;
        
        switch(selection)
        {
            case 1:
                // player wants to pick up an item but the player doesn't have the pack
                if(hasPack == false)
                {
                    if (item->getItemName() == "pack")
                    {
                        cout << "You have aquired the pack." << endl;
                        hasPack = true;
                        ptr2room->setPlayerTakesItem(item);
                        ptr2room->removeRoomItem(item);
                        item->playerNowHasItem(); // set that player has item
                    }
                    else
                    {
                        cout << "You must find a pack before you can pick up items" << endl;
                    }
                }
        
                // player wants to pick up an item and the player already has the pack
                else                {
                    add2pack(item, ptr2room);
                }
                break;
                
            case 2:
                return;
        }
    }
    
    else // no items found in the room
    {
        cout << endl;
        cout << "No collectable items where found in the room." << endl;
        cout << endl;
    }
}

void Player::add2pack(Item* item, Room* curr)
{
    
    if(itemCounter < 6) // check that the pack has less than 7 items
    {
        packItems.push_back(item); // add to pack
        itemCounter++; // increment item counter
        
        if(item->getItemName() != "pack") // check if the item is the pack and if not print the cout
        {
            cout << "You have aquired the " << item->getItemName() << ".";
        }
        
        curr->removeRoomItem(item); // remove item from room
        item->playerNowHasItem(); // set that player has item
        setHasDuctTape(item); // send to setHasDuctTape to set bool if item name is duct tape
        setHasKey(item); // send to setHasKey to set bool if item name is key
        
    }
    else
    {
        cout << "Your pack is full.  Please remove an item to pick up something else." << endl;
        selectPackItem(getCurrentLocation()); // send to remove pack item method
    }
}


void Player::removePackItem(Item* item)
{
    for(int i = 0; i < packItems.size(); i++)
    {
        if(item->getItemName() == packItems[i]->getItemName())
        {
            packItems.erase(packItems.begin() + i);
        }
    }
}

void Player::selectPackItem(Room* curr)
{
    int input = 0;
    
    cout << "Select the item you want to remove from your pack:" << endl;
    printPackItems(); // print pack items
   
    cin >> input;

    {
        
        if(curr->getRoomHasItem() == true)
        {
            cout << "You cannot drop an item in a room that already has an item in it." << endl;
            cout << "Please find another room to drop this item." << endl;
        }
        else
        {
            cout << "The " << packItems[input-1]->getItemName() << " has been removed from your pack." << endl;
            curr->setRoomItem(packItems[input-1]); // drop the item in the current location
            removePackItem(packItems[input-1]); // send to removePackItem to remove from the pack
        }
    }
    
}

void Player::putOnMarsSuit()
{
    int selection = 0;
    cout << "Do you want to put on your Mars suit?" << endl;
    cout << "1) Yes." << endl;
    cout << "2) No." << endl;
    cin >> selection;
    
    if(selection == 1) // player puts on Mars suit and items are removed from the pack
    {
        for(int i = 0; i < packItems.size(); i++)
        {
            if(packItems[i]->getItemName() == "suit")
            {
                removePackItem(packItems[i]);
            }
            if(packItems[i]->getItemName() == "tank")
            {
                removePackItem(packItems[i]);
            }
            if(packItems[i]->getItemName() == "helmet")
            {
                removePackItem(packItems[i]);
            }
        }
        
        suitOn = true; // set suitOn to true
        cout << "You have sucessfully put on your Mars suit." << endl;
        cout << "You are now ready to go outside." << endl << endl;
        
    }
    else // player does not want to put on Mars suit
    {
        return;
    }
}

void Player::printPackItems()
{
    int num = 1;
    
    cout << endl;
    cout << "Pack Items:" << endl;
    cout << "--------------------------" << endl;
    for(int i = 0; i < packItems.size(); i++)
    {
        if(packItems[i] != NULL)
        {
            cout << num << ") " << packItems[i]->getItemName() << endl;
            num++;
        }
    }
    cout << endl;
}

bool Player::getHasSuitOn()
{
    bool temp;
    
    if(suitOn == true)
        temp = true;
    else
    {
        temp = false;
    }
    return temp;
    
}

void Player::setHasDuctTape(Item* itemPtr)
{
    if(itemPtr->getItemName() == "duct tape")
    {
        hasDuctTape = true;
    }
    else
    {
        return;
    }
}

void Player::setHasKey(Item* itemPtr)
{
    if(itemPtr->getItemName() == "key")
    {
        hasKey = true;
    }
    else
    {
        return;
    }
}

bool Player::getHasDuctTape()
{
    return hasDuctTape;
}

bool Player::getHasKey()
{
    return hasKey;
}

void Player::setSolvedProblem()
{
    solved = true;
}

bool Player::getSolvedProblem()
{
    return solved;
}
