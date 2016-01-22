///
/***********************************************
 * Rover.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include "Rover.h"
#include "Player.h"
#include <string>
#include <iostream>

Rover::Rover()
{
    roomName = "Rover";
    roomHasItem = false;
}


void Rover::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "You climb into the Rover and start the engine." << endl;
    cout << "you can see mountain ranges and volcanoes in the distance, and" << endl;
    cout << "To the south, you can see Biodome_3 and the Control_Room." << endl << endl;
    cout << "To the west you see a vast desert, with a  sand storm churning" << endl;
    cout << "in the distance. To the east you see a mountain range, plus a" << endl;
    cout << "large volcano.  To the north is the Outpost." << endl;
}