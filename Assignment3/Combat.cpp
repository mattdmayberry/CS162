///
/***********************************************
 * Combat.cpp
 * Created by Matthew D Mayberry on 5/8/15
 * CS162_400_S2015_Assignment3
 ***********************************************/
///

#include <ctime>
#include <cstdlib>
#include "Combat.h"



/////////////////////////////////////////////////
/***********************************************
 *               class Combat                  *
 ***********************************************/
/////////////////////////////////////////////////


Combat::Combat()
{
    
}


int Combat::damage(int atk, int def, int arm)
{
    int a = atk;
    int d = def;
    int ar = arm;
    
    int dmg = a - d - ar;
    
    if (dmg < 0)
    {
        dmg = 0;
    }
    
    return dmg;
}

