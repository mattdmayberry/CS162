///
/***********************************************
 * Shadow.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef SHADOW_H
#define SHADOW_H

#include <stdio.h>
#include <string>
#include "Character.h"
#include "Creature.h"
using namespace std;



/*   Shadow class  */

class Shadow : public Creature
{
    
protected:
    
    
public:
    Shadow();
    int attack();
    int defend();
    
};

#endif
