///
/***********************************************
 * Module_6.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef MODULE_6_H
#define MODULE_6_H
#include "Room.h"
#include "Module.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Module_6 : public Module
{
    
protected:
    bool ipod;
    
public:
    Module_6();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
};
#endif