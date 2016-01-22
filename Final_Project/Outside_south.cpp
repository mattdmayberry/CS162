///
/***********************************************
 * Outside_south.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include "Outside_south.h"
#include "Player.h"

Outside_south::Outside_south()
{
    roomName = "Outside";
    roomHasItem = false;
}


void Outside_south::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "You arrive outside of the Southern Outpost and see Biodome_3 to" << endl;
    cout << "the east.  Attached to Biodome_3 you see the Control_Room." << endl;
}