///
/***********************************************
 * Module_4.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef MODULE_4_H
#define MODULE_4_H
#include "Room.h"
#include "Module.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Module_4 : public Module
{
    
protected:
    bool tank;
    
public:
    Module_4();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
};
#endif