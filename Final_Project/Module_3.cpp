///
/***********************************************
 * Module_3.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include "Module_3.h"
#include "Player.h"
#include <iostream>

Module_3::Module_3()
{
    roomName = "Module_3";
}

void Module_3::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "Inside Module_3 there lockers and a rack with hanging Mars suits." << endl;
    cout << "All astronauts must wear Mars suits when exposed to the Mars atmosphere." << endl;
    cout << "Mars suits protect astronauts from extreme temperatures and the very thin," << endl;
    cout << "non-breathable atmosphere. You notice that the hanging suits do not have" << endl;
    cout << "all of the required components, and they are missing air tanks and helmets" << endl;
    cout << "There is a door to Module_2 and you see a door to another room." << endl << endl;
}