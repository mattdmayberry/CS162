///
/***********************************************
 * Reptile.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef REPTILE_H
#define REPTILE_H

#include <stdio.h>
#include <string>
#include "Character.h"
#include "Creature.h"
using namespace std;



/*   Reptile class  */


class Reptile : public Creature
{
    
protected:
    
    
public:
    Reptile();
    int attack();
    int defend();
};

#endif
