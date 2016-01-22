///
/***********************************************
 * Goblin.cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///


#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Goblin.h"
#include "Character.h"
using namespace std;


/*   Goblin class  */

Goblin::Goblin()
{
    creatureType = "Goblin";
    armor = 3;
    strength = 8;
    name = "";
    int aD = 2;
    this->setDice(aD);
}


int Goblin::attack()
{
    int numSides = 6;
    int numDice = this->getDice();
    int attack = 0;
    for(int i = 0; i < numDice; ++i)
    {
        attack += (rand()%numSides)+1;
    }
    
    if(attack == 12)
    {
        goblin12 = true;
    }
    
    return attack;
}


int Goblin::defend()
{
    int numSides = 6;
    int numDice = 1;
    int defend = 0;
    for(int i = 0; i < numDice; ++i)
    {
        defend += (rand()%numSides)+1;
    }
    return defend;
}