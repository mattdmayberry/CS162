///
/***********************************************
 * Module_1.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef MODULE_1_H
#define MODULE_1_H
#include "Room.h"
#include "Module.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Module_1 : public Module
{
    
protected:
    bool key;
    
public:
    Module_1();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
};
#endif
