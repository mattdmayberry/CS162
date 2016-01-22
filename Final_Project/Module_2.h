///
/***********************************************
 * Module_2.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef MODULE_2_H
#define MODULE_2_H
#include "Room.h"
#include "Module.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Module_2 : public Module
{
    
protected:
    bool pack;
    
public:
    Module_2();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
};
#endif