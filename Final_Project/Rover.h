///
/***********************************************
 * Rover.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef ROVER_H
#define ROVER_H
#include "Room.h"
#include "Player.h"
#include "Biodome.h"
#include <stdio.h>
#include <string>
using namespace std;

class Rover : public Room
{
    
protected:
    bool inRover;
    
public:
    Rover();
    void drive();
    bool roomItem();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
};
#endif