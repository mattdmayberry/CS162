///
/***********************************************
 * Goblin.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef GOBLIN_H
#define GOBLIN_H

#include <stdio.h>
#include <string>
#include "Character.h"
#include "Creature.h"
using namespace std;



/*   Goblin class  */


class Goblin : public Creature
{
    
protected:

    
    
public:
    Goblin();
    int attack();
    int defend();
};


#endif