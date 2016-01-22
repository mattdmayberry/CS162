///
/***********************************************
 * Biodome_1.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include "Biodome_1.h"
#include "Player.h"

Biodome_1::Biodome_1()
{
    roomName = "Biodome_1";
}

void Biodome_1::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "Inside Biodome_1 there are long rows of racks, containing" << endl;
    cout << "hydroponic plants, with large LED lights suspended over the racks." << endl;
    cout << "It appers that in this biodome the current harvest is snow peas." << endl;
    cout << "There are two doors in this room.  One door leads to Module_4, and" << endl;
    cout << "another door leads to what appears to be another biodome." << endl << endl;
}