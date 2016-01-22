///
/***********************************************
 * Biodome_3.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef BIODOME_3_H
#define BIODOME_3_H
#include "Room.h"
#include "Biodome.h"
#include "Player.h"
#include <stdio.h>
#include <string>
using namespace std;

class Biodome_3 : public Biodome
{
    
protected:
    bool apple;
    
public:
    Biodome_3();
    void printRoomPrompt(Player* player, Timer* t, double seconds);

};
#endif