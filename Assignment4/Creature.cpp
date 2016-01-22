///
/***********************************************
 * Creature..cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///


#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Character.h"
#include "Combat.h"
#include "Creature.h"
using namespace std;


/*   Creature class  */



Creature::Creature()
{
    nextNode = NULL;
    prevNode = NULL;
    armor = 0;
    strength = 0;
    damage = 0;
    attackDice = 0;
    score = 0;
    goblin12 = false;
    achilles = false;
}

string Creature::getCreatureType()
{
    return creatureType;
}

void Creature::setNextNode(Creature* next)
{
    nextNode = next;
}

Creature* Creature::getNextNode()
{
    return nextNode;
}

void Creature::setPrevNode(Creature* prev)
{
    prevNode = prev;
}

Creature* Creature::getPrevNode()
{
    return prevNode;
}

int Creature::attack()
{
    int numSides = 0;
    int numDice = this->getDice();
    int attack = 0;
    for(int i = 0; i < numDice; ++i)
    {
        attack += (rand()%numSides)+1;
    }

    return attack;
}


int Creature::defend()
{
    int numSides = 0;
    int numDice = 0;
    int defend = 0;
    for(int i = 0; i < numDice; ++i)
    {
        defend += (rand()%numSides)+1;
    }
    return defend;
}


bool Creature::getGoblin12()
{
    
    return goblin12;
}

void Creature::setAchilles()
{
    achilles = true;
}

void Creature::setScore(int s)
{
    score = s;
}

int Creature::getScore()
{
    return score;
}