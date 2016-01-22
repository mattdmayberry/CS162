///
/***********************************************
 * Module_3.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef MODULE_3_H
#define MODULE_3_H
#include "Room.h"
#include "Player.h"
#include "Player.h"
#include "Module.h"
#include <stdio.h>
#include <string>
using namespace std;

class Module_3 : public Module
{
    
protected:
    bool suit;
    
public:
    Module_3();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
};
#endif