///
/***********************************************
 * Barbarian.cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///


#include <stdio.h>
#include "Barbarian.h"
#include "Character.h"
using namespace std;



/*   Barbarian class  */


Barbarian::Barbarian()
{
    creatureType = "Barbarian";
    armor = 0;
    strength = 12;
    name = "";
    int aD = 2;
    this->setDice(aD);
}



int Barbarian::attack()
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



int Barbarian::defend()
{
    int numSides = 6;
    int numDice = 2;
    int defend = 0;
    for(int i = 0; i < numDice; ++i)
    {
        defend += (rand()%numSides)+1;
    }
    return defend;
}