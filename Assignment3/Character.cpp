///
/***********************************************
 * Character.cpp
 * Created by Matthew D Mayberry on 5/8/15
 * CS162_400_S2015_Assignment3
 ***********************************************/
///

#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Character.h"
#include "Combat.h"
using namespace std;

/////////////////////////////////////////////////
/***********************************************
 *             class Character                 *
 ***********************************************/
/////////////////////////////////////////////////

Character::Character()
{
    armor = 0;
    strength = 0;
    damage = 0;
    name = " ";
}

string Character::getName()
{
    return name;
}

int Character::getArmor()
{
    return armor;
}

void Character::setStrength(int dam)
{
    strength = strength - dam;
}

int Character::getStrength()
{
    return strength;
}



void Character::setDice(int d)
{
    attackDice = d;
}

int Character::getDice()
{
    return attackDice;
}

/////////////////////////////////////////////////
/***********************************************
 *             class Creature                  *
 ***********************************************/
/////////////////////////////////////////////////


Creature::Creature()
{
    armor = 0;
    strength = 0;
    damage = 0;
    attackDice = 0;
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
    if(attack == 12)
    {
        
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


/////////////////////////////////////////////////
/***********************************************
 *                class Goblin                 *
 ***********************************************/
/////////////////////////////////////////////////


Goblin::Goblin()
{
    armor = 3;
    strength = 8;
    name = "Goblin";
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

/////////////////////////////////////////////////
/***********************************************
 *                class Barbarian              *
 ***********************************************/
/////////////////////////////////////////////////

Barbarian::Barbarian()
{
    armor = 0;
    strength = 12;
    name = "Barbarian";
    int aD = 2;
    this->setDice(aD);
}

int Barbarian::attack()
{
    int numSides = 6;
    int numDice = this->getDice();
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


/////////////////////////////////////////////////
/***********************************************
 *                class Reptile                *
 ***********************************************/
/////////////////////////////////////////////////


Reptile::Reptile()
{
    armor = 7;
    strength = 18;
    name = "Reptile Person";
    int aD = 3;
    this->setDice(aD);
}

int Reptile::attack()
{
    int numSides = 6;
    int numDice = this->getDice();
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


/////////////////////////////////////////////////
/***********************************************
 *                 class Blue                  *
 ***********************************************/
/////////////////////////////////////////////////

Blue::Blue()
{
    armor = 3;
    strength = 12;
    name = "Blue Men";
    int aD = 3;
    this->setDice(aD);
}

int Blue::attack()
{
    int numSides = 10;
    int numDice = this->getDice();
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


/////////////////////////////////////////////////
/***********************************************
 *                class Shadow                 *
 ***********************************************/
/////////////////////////////////////////////////


Shadow::Shadow()
{
    armor = 0;
    strength = 12;
    name = "Shadow";
    int aD = 3;
    this->setDice(aD);
}


int Shadow::attack()
{
    int numSides = 10;
    int numDice = this->getDice();
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
    return defend;
}






