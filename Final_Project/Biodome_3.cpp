///
/***********************************************
 * Biodome_3.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include "Biodome_3.h"
#include "Player.h"

Biodome_3::Biodome_3()
{
    roomName = "Biodome_3";
}


void Biodome_3::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "Inside Biodome_3 it is filled with rows of tall trees, towering over you." << endl;
    cout << "You look up and see that the trees are fruit trees of many different" << endl;
    cout << "varieties.  Apples, oranges and limes hang from their branches.  Above" << endl;
    cout << "the trees there are massive LED lights that illuminate each tree.  You" << endl;
    cout << "look around the room and see that there is a door that leads into another" << endl;
    cout << "room.  As you approach the room you hear a computerized voice proclaim:" << endl << endl;
    cout << "'OXYGEN LEVELS DANGEROUSLY LOW! ---  OXYGEN LEVELS DANGEROUSLY LOW!" << endl << endl;
}