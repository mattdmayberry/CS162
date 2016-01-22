///
/***********************************************
 * Character.cpp
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
using namespace std;

/*   Character class  */


Character::Character()
{
    armor = 0;
    strength = 0;
    damage = 0;
    name = " ";
}

void Character::setName(string inputName)
{
    name = inputName;
}


string Character::getName()
{
    return name;
}


void Character::setTeam(string teamInput)
{
    team = teamInput;
}

string Character::getTeam()
{
    return team;
}


int Character::getArmor()
{
    return armor;
}


void Character::setStrength(int dam)
{
    strength = strength - dam;
    
    if(strength < 0)
    {
        strength = 0;
    }
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












