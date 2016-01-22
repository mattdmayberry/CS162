///
/***********************************************
 * Biodome_1.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef BIODOME_1_H
#define BIODOME_1_H
#include "Room.h"
#include "Biodome.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Biodome_1 : public Biodome
{
    
protected:
    bool peas;
    
public:
    Biodome_1();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
};
#endif