///
/***********************************************
 * Outside_south.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef OUTSIDE_SOUTH_H
#define OUTSIDE_SOUTH_H
#include "Room.h"
#include "Player.h"
#include "Outside.h"
#include <stdio.h>
#include <string>
using namespace std;

class Outside_south : public Outside
{
    
protected:
    bool isOutside;
    
public:
    Outside_south();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
    
    
};
#endif