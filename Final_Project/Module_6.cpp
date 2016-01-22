///
/***********************************************
 * Module_6.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include "Module_6.h"
#include "Player.h"

Module_6::Module_6()
{
    roomName = "Module_6";
}

void Module_6::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "Inside Module_6 there bunk beds and  a you see a large monitor" << endl;
    cout << "mounted on the wall.  The monitor is displaying a map of the Mars" << endl;
    cout << "One Outpost.  You see that there is a portion of the Outpost that is" << endl;
    cout << "disconnected from the portion of the outpost where you are currently" << endl;
    cout << "located.  The remote section of the Outpost is where the Control_Room" << endl;
    cout << "is located, which is where the controls for the Outpost oxygen levels" << endl;
    cout << "can be controlled." << endl << endl;
}