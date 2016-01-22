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
#include "Reptile.h"
#include "Character.h"
using namespace std;


/*   Reptile class  */

Reptile::Reptile()
{
    creatureType = "Reptile Person";
    armor = 7;
    strength = 18;
    name = "";
    int aD = 3;
    this->setDice(aD);
}



int Reptile::attack()
{
    int numSides = 6;
    int numDice = this->getDice();
    if(achilles == true)
    {
        numDice = (this->getDice())/2;
    }
    
    int attack = 0;
    for(int i = 0; i < numDice; ++i)
    {
        attack += (rand()%numSides)+1;
    }
    return attack;
}



int Reptile::defend()
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