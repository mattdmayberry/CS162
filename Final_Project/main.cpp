///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include "Timer.h"
#include "Room.h"
#include "Player.h"
#include "Module_1.h"
#include "Module_2.h"
#include "Module_3.h"
#include "Module_4.h"
#include "Module_5.h"
#include "Module_6.h"
#include "Biodome_1.h"
#include "Biodome_2.h"
#include "Biodome_3.h"
#include "Control_Room.h"
#include "Rover.h"
#include "Outside.h"
#include "Outside_south.h"
#include "Item.h"
#include "Pack.h"
#include "Suit.h"
#include "Helmet.h"
#include "Hammer.h"
#include "Duct_tape.h"
#include "Screw_driver.h"
#include "Ipod.h"
#include "Tank.h"
#include "Key.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <exception>

int main()
{
    // create Timer object
    double seconds = 600;
    Timer time;
    time.start(); // start timer
    
    
    // create player object
    Player player1;
    
    
    // create room objects
    Module_1 module1;
    Module_2 module2;
    Module_3 module3;
    Module_4 module4;
    Module_5 module5;
    Module_6 module6;
    Biodome_1 biodome1;
    Biodome_2 biodome2;
    Biodome_3 biodome3;
    Control_Room controlRoom1;
    Rover rover1;
    Outside outside;
    Outside_south outsideSouth;
    
    // set current location
    player1.setCurrentLocation(&module1);
    Room* curr = player1.getCurrentLocation();
    
    // set N,S,E,W for all room objects
    module1.setWest(&module1);
    module1.setEast(&module2);
    module1.setNorth(&module1);
    module1.setSouth(&module1);
    module2.setWest(&module1);
    module2.setEast(&module3);
    module2.setNorth(&module2);
    module2.setSouth(&module2);
    module3.setWest(&module2);
    module3.setEast(&module4);
    module3.setNorth(&module3);
    module3.setSouth(&module3);
    module4.setWest(&module3);
    module4.setEast(&module5);
    module4.setNorth(&biodome1);
    module4.setSouth(&outside);
    module5.setWest(&module4);
    module5.setEast(&module6);
    module5.setNorth(&biodome2);
    module5.setSouth(&outside);
    module6.setWest(&module5);
    module6.setEast(&module6);
    module6.setNorth(&module6);
    module6.setSouth(&module6);
    biodome1.setWest(&biodome1);
    biodome1.setEast(&biodome2);
    biodome1.setNorth(&biodome1);
    biodome1.setSouth(&module4);
    biodome2.setWest(&biodome1);
    biodome2.setEast(&biodome2);
    biodome2.setNorth(&biodome2);
    biodome2.setSouth(&module5);
    biodome3.setWest(&outsideSouth);
    biodome3.setEast(&controlRoom1);
    biodome3.setNorth(&biodome3);
    biodome3.setSouth(&biodome3);
    outside.setWest(&rover1);
    outside.setEast(&outside);
    outside.setNorth(&module4);
    outside.setSouth(&outsideSouth);
    rover1.setWest(&rover1);
    rover1.setEast(&outside);
    rover1.setNorth(&rover1);
    rover1.setSouth(&outsideSouth);
    outsideSouth.setWest(&outsideSouth);
    outsideSouth.setEast(&biodome3);
    outsideSouth.setNorth(&outside);
    outsideSouth.setSouth(&outsideSouth);
    controlRoom1.setWest(&biodome3);
    controlRoom1.setEast(&controlRoom1);
    controlRoom1.setNorth(&controlRoom1);
    controlRoom1.setSouth(&controlRoom1);
    
    // create item objects
    Pack pack1;
    Helmet helmet1;
    Suit suit1;
    Hammer hammer1;
    Duct_tape duct_tape1;
    Screw_driver screw_driver1;
    Tank tank1;
    Key key1;
    Ipod ipod1;
    
    // set item locations
    module1.setRoomItem(&key1);
    module2.setRoomItem(&pack1);
    module3.setRoomItem(&suit1);
    module4.setRoomItem(&tank1);
    module5.setRoomItem(&helmet1);
    module6.setRoomItem(&ipod1);
    biodome1.setRoomItem(&duct_tape1);
    biodome2.setRoomItem(&screw_driver1);
    biodome3.setRoomItem(&hammer1);
 
    
    // Player names their charactor
    string name;
    cout << "----------------------------------------------------------" << endl;
    cout << "Mars One Outpost: Created by Matt Mayberry, June 2015" << endl;
    cout << "Oregon State University / CS162_400_S2015 / Final Project" << endl;
    cout << "----------------------------------------------------------" << endl << endl;
    cout << "Welcome to Mars!  Before we get started" << endl;
    cout << "please enter a name for your character: " << endl << endl;
    getline(cin, name);
    player1.setPlayerName(name);
    
    cout << endl;
    cout << "(* * HINT: To find items select 'look around' from the menu * *)" << endl << endl;
    
    // initial description of the scenario prints to console
    cout << endl;
    cout << "**********************************************************************************************" << endl << endl;
    cout << player1.getPlayerName() << " is an inhabitant of the Mars One Outpost, the first human habitaton on Mars." << endl;
    cout << "While sleeping in their bunk " << player1.getPlayerName() << " awakens to the sound of an alarm sounding." << endl;
    cout << player1.getPlayerName() << " gets out of bed to see what is causing the alarm and realizes they are having" << endl;
    cout << "touble breathing." << endl;
    
    int selection = 0;
    
    while(time.getTimeLeft(seconds) / CLOCKS_PER_SEC <= seconds  && player1.getSolvedProblem() == false)
    {
    
        do
        {
            cout << endl;
            cout << "You are currently in " << player1.getCurrentLocation()->getRoomName() << "." << endl;
            cout << "There are " << (time.getTimeLeft(seconds) / CLOCKS_PER_SEC) * 1000000 << " seconds of oxygen left." << endl;
            cout << endl;
        
            // Play room prompt
            player1.getCurrentLocation()->printRoomPrompt(&player1, &time, seconds);
        
            // print menu options to console
            cout << endl;
            cout << "Please select how you would like to proceed: " << endl;
            cout << "1) Look around " << player1.getCurrentLocation()->getRoomName() << "." << endl;
            cout << "2) Head east." << endl;
            cout << "3) Head west." << endl;
            cout << "4) Head north." << endl;
            cout << "5) Head south." << endl;
            cout << "6) Print pack items." << endl;
            cout << "7) Remove pack item." << endl;
            cout << "8) List current location." << endl;
            cout << "9) Give up all hope and quit." << endl << endl;
        
            cin >> selection;
            Room* newRoom = NULL;
        
            switch(selection)
            {
                case 1:
                    curr = player1.getCurrentLocation();
                    player1.lookAround(curr);
                    break;
                
                case 2:
                    curr = player1.getCurrentLocation();
                    newRoom = curr->getEast();
                    if(newRoom == player1.getCurrentLocation())
                    {
                        cout << endl;
                        cout << "There is no way to move east from here." << endl << endl;
                    }

                    if(newRoom->getRoomName() == "Outside" && player1.getHasSuitOn() == false)
                    {
                        cout << endl;
                        cout << "You will die if you go outside without wearing a Mars suit." << endl << endl;
                        player1.putOnMarsSuit();
                    }
                
                    else
                    {
                        player1.setCurrentLocation(newRoom);
                    }
                
                    break;
                
                case 3:
                    curr = player1.getCurrentLocation();
                    newRoom = curr->getWest();
                    if(newRoom == player1.getCurrentLocation())
                    {
                        cout << endl;
                        cout << "There is no way to move west from here." << endl << endl;
                    }
                
                    if(newRoom->getRoomName() == "Outside" && player1.getHasSuitOn() == false)
                    {
                        cout << endl;
                        cout << "You will die if you go outside without wearing a Mars suit." << endl << endl;
                        player1.putOnMarsSuit();
                    }
                
                    else
                    {
                        player1.setCurrentLocation(newRoom);
                    }
                
                    break;
                
                case 4:
                    curr = player1.getCurrentLocation();
                    newRoom = curr->getNorth();
                    if(newRoom == player1.getCurrentLocation())
                    {
                        cout << endl;
                        cout << "There is no way to move north from here." << endl << endl;
                    }
                
                    if(newRoom->getRoomName() == "Outside" && player1.getHasSuitOn() == false)
                    {
                        cout << endl;
                        cout << "You will die if you go outside without wearing a Mars suit." << endl << endl;
                        player1.putOnMarsSuit();
                    }
                
                    else
                    {
                        player1.setCurrentLocation(newRoom);
                    }
                
                    break;
                
                case 5:
                    curr = player1.getCurrentLocation();
                    newRoom = curr->getSouth();
                    if(newRoom == player1.getCurrentLocation())
                    {
                        cout << endl;
                        cout << "There is no way to move south." << endl << endl;
                    }
                
                    if(newRoom->getRoomName() == "Outside" && player1.getHasSuitOn() == false)
                    {
                        cout << endl;
                        cout << "You will die if you go outside without wearing a Mars suit." << endl << endl;
                        player1.putOnMarsSuit();
                    }
                
                    else
                    {
                        player1.setCurrentLocation(newRoom);
                    }
                
                    break;
                
                case 6:
                    player1.printPackItems();
                    break;
                    
                case 7:
                    player1.selectPackItem(curr);
                    break;
                
                case 8:
                    cout << endl;
                    cout << "You are currently in " << player1.getCurrentLocation()->getRoomName() << "." << endl;
                    cout << endl;
                    break;
            }
        
        }while(selection != 9);
    }
    if(time.getTimeLeft(seconds) / CLOCKS_PER_SEC > seconds)
    {
        cout << "You were unable to complete the mission before the oxygen supply was exhausted." << endl;
        cout << player1.getPlayerName() << " has been terminated." << endl;
    }
    
    if(player1.getSolvedProblem() == true)
    {

    }

    return 0;
}

