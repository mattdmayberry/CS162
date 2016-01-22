///
/***********************************************
 * Character.h
 * Created by Matthew D Mayberry on 5/8/15
 * CS162_400_S2015_Assignment3
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

/////////////////////////////////////////////////
/***********************************************
 *             class Character                 *
 ***********************************************/
/////////////////////////////////////////////////

class Character
{
    
protected:
    string name;
    int attackDice;
    int armor;
    int damage;
    int strength;

    
public:
    Character();
    virtual int attack() = 0;
    virtual int defend() = 0;
    string getName();
    void setDice(int d);
    int getDice();
    int getAttack();
    int getDefend();
    int getArmor();
    int getStrength();
    void setStrength(int dam);
    
};


/////////////////////////////////////////////////
/***********************************************
 *             class Creature                  *
 ***********************************************/
/////////////////////////////////////////////////

class Creature : public Character
{
    
protected:

    
public:
    Creature();
    int attack();
    int defend();
};


/////////////////////////////////////////////////
/***********************************************
 *                class Goblin                 *
 ***********************************************/
/////////////////////////////////////////////////

class Goblin : public Creature
{
    
protected:

    
public:
    Goblin();
    int attack();
    int defend();
};


/////////////////////////////////////////////////
/***********************************************
 *                class Barbarian              *
 ***********************************************/
/////////////////////////////////////////////////

class Barbarian : public Creature
{
    
protected:

    
public:
    Barbarian();
    int attack();
    int defend();
};

/////////////////////////////////////////////////
/***********************************************
 *                class Reptile                *
 ***********************************************/
/////////////////////////////////////////////////

class Reptile : public Creature
{
    
protected:

    
public:
    Reptile();
    int attack();
    int defend();
};

/////////////////////////////////////////////////
/***********************************************
 *                 class Blue                  *
 ***********************************************/
/////////////////////////////////////////////////

class Blue : public Creature
{
    
protected:

    
public:
    Blue();
    int attack();
    int defend();
};

/////////////////////////////////////////////////
/***********************************************
 *                class Shadow                 *
 ***********************************************/
/////////////////////////////////////////////////

class Shadow : public Creature
{
    
protected:

    
public:
    Shadow();
    int attack();
    int defend();
    
};




#endif
