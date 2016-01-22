///
/***********************************************
 * Character.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Combat.h"
using namespace std;

/*   Character class  */

class Character
{
    
protected:
    string name;
    string team;
    int attackDice;
    int armor;
    int damage;
    int strength;

    
    
public:
    Character();
    virtual int attack() = 0;
    virtual int defend() = 0;
    void setName(string inputName);
    string getName();
    void setTeam(string teamInput);
    string getTeam();
    void setDice(int d);
    int getDice();
    int getAttack();
    int getDefend();
    int getArmor();
    int getStrength();
    void setStrength(int dam);
};




#endif
