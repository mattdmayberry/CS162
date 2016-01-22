///
/***********************************************
 * Biodome_2.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include "Biodome_2.h"
#include "Player.h"

Biodome_2::Biodome_2()
{
    roomName = "Biodome_2";
}


void Biodome_2::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "Inside Biodome_2 there are long rows of racks, containing" << endl;
    cout << "hydroponic plants, with large LED lights suspended over the racks." << endl;
    cout << "It appers that in this biodome the current harvest is soy beans" << endl;
    cout << "and you see processing equipment for making tofu.  There are two" << endl;
    cout << "doors in this room.  One door leads to Biodome_1, and another door" << endl;
    cout << "leads to another room." << endl << endl;
}