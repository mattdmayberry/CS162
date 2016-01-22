///
/***********************************************
 * BlueMen.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef BLUEMEN_H
#define BLUEMEN_H

#include <stdio.h>
#include <string>
#include "Character.h"
#include "Creature.h"
using namespace std;

/*   Blue class  */

class Blue : public Creature
{
    
protected:
    
    
public:
    Blue();
    int attack();
    int defend();
};


#endif
