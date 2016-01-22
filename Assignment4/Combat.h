///
/***********************************************
 * Combat.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef __COMBAT_H
#define __COMBAT_H

#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Character.h"
#include "Queue.h"
#include "Stack.h"
using namespace std;

class Queue; // forward declaration
class Stack; // forward declaration

/*  Combat class  */

class Combat
{
    
protected:
    int regen;
    
public:
    Combat();
    void battle(Queue* p1, Queue* p2, Stack* losers, string team1, string team2);
    int damage(int atk, int def, int arm);
    void fighter1Attack(Creature* fighter1, Creature* fighter2);
    void fighter2Attack(Creature* fighter1, Creature* fighter2);
    void fighter1Defeated(Creature* fighter1, Creature* fighter2, Stack* losers, Queue* p1, Queue* p2);
    void fighter2Defeated(Creature* fighter1, Creature* fighter2, Stack* losers, Queue* p1, Queue* p2);
    int regenerate();
    
};

#endif
