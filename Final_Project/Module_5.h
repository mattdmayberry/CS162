///
/***********************************************
 * Module_5.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef MODULE_5_H
#define MODULE_5_H
#include "Room.h"
#include "Module.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Module_5 : public Module
{
    
protected:
    bool helmet;
    
public:
    Module_5();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
};
#endif