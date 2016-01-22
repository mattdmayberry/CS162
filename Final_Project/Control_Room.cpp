///
/***********************************************
 * Control_Room.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include <iostream>
#include <cstdlib>
#include "Control_Room.h"
#include "Player.h"


Control_Room::Control_Room()
{
    roomName = "Control_Room";
    roomHasItem = false;
    ductFixed = false;
}


void Control_Room::printRoomPrompt(Player* player, Timer* t, double seconds)
{
    promptCheck = false;
    int selection = 0;
    
    cout << endl;
    cout << "As you enter the Control_Room you see objects whirling around" << endl;
    cout << "the room.  An air duct has come loose on the wall and is leaking" << endl;
    cout << "large amounts of pressurized air into the room.  This is surely" << endl;
    cout << "what has caused the issues with the low oxygen levels in the" << endl;
    cout << "Outpost." << endl << endl;
    cout << "There is a large control console in the center of the room, with" << endl;
    cout << "several display monitors mounted on it.  There is also communications" << endl;
    cout << "equipment for communicating with mission control. The only door in the" << endl;
    cout << "room leads back to Biodome_3" << endl << endl;
    
    while(player->getSolvedProblem() != true)
    {
        do
        {
            cout << "Select how you would like to proceed:" << endl;
            cout << "1) Walk over to busted air duct." << endl;
            cout << "2) Walk to control console." << endl;
            cout << "3) Leave control room." << endl;
            cin >> selection;
    
            switch(selection)
            {
                case 1:
                    duct(player);
                    break;
                case 2:
                    console(player);
                    break;
                
            }
        }while(selection != 3);
    }
}

void Control_Room::duct(Player* player)
{
    int repairDuctChoice = 0;
    cout << "You walk over to the air duct and you can feel the pressure of the air" << endl;
    cout << "pushing you away from the duct.  Although it will be difficult to" << endl;
    cout << "deal with the air pressure you see that the duct can be repaired" << endl;
    cout << "relatively easily by realigning the ducting and taping the duct in" << endl;
    cout << "place with duct tape." << endl << endl;
    cout << "Do you want to try and repair the duct?" << endl;
    cout << "1) Yes." << endl;
    cout << "2) No." << endl;
    cin >> repairDuctChoice;
    
    if(player->getHasDuctTape() == true)
    {
        cout << "You reconnect the separated ducting, which has an immediate impact" << endl;
        cout << "on the air that was blasting out of the duct.  You remove the duct" << endl;
        cout << "tape from your pack and secure the duct in place." << endl << endl;
        
        ductFixed = true;
        console(player);
    }
    else
    {
        cout << "You do not have the necessary items in your pack to repair the duct." << endl;
        return;
    }
    
}

void Control_Room::console(Player* player)
{
   
    if(ductFixed == true)
    {
        cout << "Now that the duct is repaired you walk over to the console to check" << endl;
        cout << "the oxygen levels in the Outpost." << endl << endl;
        
        if(player->getHasKey() == true)
        {
            player->setSolvedProblem(); // set problem solved bool
            cout << "You enter your keycard into the console and gain access to the controls." << endl;
            cout << "The air pressure gauges begin to return to a safe level and the alarm" << endl;
            cout << "stops sounding.  You have effectively solved this problem and saved the" << endl;
            cout << "Mars One Outpost mission.  NICE WORK." << endl << endl;
            cout << "You receive a personal video message from Elon Musk congratulating you" << endl;
            cout << "on your courage and resolve under pressure." << endl << endl;
            cout << "* * GAME OVER * *" << endl << endl;
            exit(0);
        }
        else
        {
            cout << "You do not have the necessary items in your pack to access the console." << endl;
            return;
        }
    }
    else
    {
        cout << "You walk over to the console and see that the console requires a key to" << endl;
        cout << "gain control over the operation of the Outpost." << endl << endl;
        
        if(player->getHasKey() == true)
        {
            cout << "You enter your keycard into the console and gain access to the controls." << endl;
            cout << "You find that you are unable to correct the airflow problem from the console" << endl;
            cout << "and instead you will need to first correct the problem mechanically." << endl;
            return;
        }
        else
        {
            cout << "You do not have the necessary items in your pack to access the console." << endl;
            return;
        }
    }
}

