///
/***********************************************
 * BlueMen.cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///


#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "BlueMen.h"
#include "Character.h"
using namespace std;


/*   Blue class  */

Blue::Blue()
{
    creatureType = "Blue Men";
    armor = 3;
    strength = 12;
    name = "";
    int aD = 3;
    this->setDice(aD);
}



int Blue::attack()
{
    int numSides = 10;
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



int Blue::defend()
{
    int numSides = 6;
    int numDice = 3;
    int defend = 0;
    for(int i = 0; i < numDice; ++i)
    {
        defend += (rand()%numSides)+1;
    }
    return defend;
}