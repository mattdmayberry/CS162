///
/***********************************************
 * Module_4.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include "Module_4.h"
#include "Player.h"
#include <iostream>


Module_4::Module_4()
{
    roomName = "Module_4";
}

void Module_4::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "Inside Module_4 equipment racks with oxygen tanks. This room" << endl;
    cout << "has four doors.  To the west there is a door to Module_3 and to" << endl;
    cout << "the north you can see an open door that leads to a biodome. To" << endl;
    cout << "the south you see a door that leads outiside. To the east there" << endl;
    cout << "is a door to another room." << endl << endl;
}