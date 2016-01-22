///
/***********************************************
 * Module_5.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include "Module_5.h"
#include "Player.h"

Module_5::Module_5()
{
    roomName = "Module_5";
}

void Module_5::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "Inside Module_5 there is a dining area, with a table and chairs." << endl;
    cout << "There is also a small rack with helmets for the Mars suits.  This" << endl;
    cout << "room has three doors.  One door leads back to Module_4.  To the" << endl;
    cout << "the north you see a door that leads to a biodome.  To the east you" << endl;
    cout << "see a door that leads to another room." << endl << endl;
}