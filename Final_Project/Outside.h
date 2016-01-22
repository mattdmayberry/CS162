///
/***********************************************
 * Outside.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef OUTSIDE_H
#define OUTSIDE_H
#include "Room.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Outside : public Room
{
    
protected:
    bool isOutside;
    
public:
    Outside();
    void printRoomPrompt(Player* player, Timer* t, double seconds);


};
#endif