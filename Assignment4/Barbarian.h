///
/***********************************************
 * Barbarian.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef BARBARIAN_H
#define BARBARIAN_H

#include <stdio.h>
#include <string>
#include "Character.h"
#include "Creature.h"
using namespace std;



 /*   Barbarian class  */


class Barbarian : public Creature
{
    
protected:

    
public:
    Barbarian();
    int attack();
    int defend();
};


#endif
