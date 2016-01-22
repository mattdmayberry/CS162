///
/***********************************************
 * Module_2.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include "Module_2.h"
#include "Player.h"


Module_2::Module_2()
{
    roomName = "Module_2";
    
}

void Module_2::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "Module_2 contains storage shelves, with gear and supplies." << endl;
    cout << "There is a door to Module_1 and there is a door to another" << endl;
    cout << "room." << endl << endl;
}