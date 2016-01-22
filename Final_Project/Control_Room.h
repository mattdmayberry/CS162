///
/***********************************************
 * Control_Room.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef CONTROL_ROOM_H
#define CONTROL_ROOM_H
#include "Room.h"
#include "Biodome.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Control_Room : public Room
{
    
protected:
    bool alarm;
    bool oxygen;
    bool ductFixed;
    
public:
    Control_Room();
    void console(Player* player);
    void duct(Player* player);
    void printRoomPrompt(Player* player, Timer* t, double seconds);

};
#endif