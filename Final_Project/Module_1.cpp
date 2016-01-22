///
/***********************************************
 * Module_1.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include "Module_1.h"
#include "Room.h"
#include "Player.h"
#include "Timer.h"
#include "Player.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>


Module_1::Module_1()
{
    roomName = "Module_1";
}

void Module_1::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "Inside Module_1 there are bunk beds, a few chairs, and a" << endl;
    cout << "large monitor displaying information about the Mars One Outpost." << endl;
    cout << "You approach the monitor and see a warning message flashing," << endl;
    cout << "indicating that the oxygen levels are low in the base station" << endl;
    cout << "and they are levels are continuing to drop even further." << endl << endl;
    cout << "If oxygen levels dip to low you and the other inhabitants will" << endl;
    cout << "be terminated." << endl << endl;
    cout << "You see a door to the east that goes to another room." << endl << endl;
}