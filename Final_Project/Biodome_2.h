///
/***********************************************
 * Biodome_2.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef BIODOME_2_H
#define BIODOME_2_H
#include "Room.h"
#include "Biodome.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Biodome_2 : public Biodome
{
    
protected:
    bool tofu;
    
public:
    Biodome_2();
    void printRoomPrompt(Player* player, Timer* t, double seconds);
};
#endif