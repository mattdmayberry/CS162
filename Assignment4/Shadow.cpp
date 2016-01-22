///
/***********************************************
 * Shadow.cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///


#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Shadow.h"
#include "Character.h"
using namespace std;


/*   Shadow class  */


Shadow::Shadow()
{
    creatureType = "Shadow";
    armor = 0;
    strength = 12;
    name = "";
    int aD = 3;
    this->setDice(aD);
}




int Shadow::attack()
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



int Shadow::defend()
{
    int numSides = 6;
    int numDice = 1;
    int defend = 0;
    for(int i = 0; i < numDice; ++i)
    {
        defend += (rand()%numSides)+1;
    }
    
    int odds = (rand()%10)+1;
    if(odds != 1)
    {
        defend = -1; // return -1
    }
    
    return defend;
}