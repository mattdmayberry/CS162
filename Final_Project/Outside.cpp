///
/***********************************************
 * Outside.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include "Outside.h"
#include "Player.h"

Outside::Outside()
{
    roomName = "Outside";
    roomHasItem = false;
}


void Outside::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = true;
    
    cout << endl;
    cout << "As you exit the Mars One Outpost and step onto the surface of Mars" << endl;
    cout << "You notice that Mars has about one-third the gravity of Earth." << endl;
    cout << "Red dust covers the surface and you feel the loose sand move under" << endl;
    cout << "Your boots as you walk lightly on the surface." << endl << endl;
    cout << "You look look south and see Biodome_3 and the Control_Room.  The" << endl;
    cout << "Control_Room is connected to Biodome_3, and can only access the" << endl;
    cout << "Control_Room through Biodome_3." << endl << endl;
    cout << "To the west you see a Rover, which would greatly increase your" << endl;
    cout << "speed in traveling to the Control_Room." << endl << endl;
}
