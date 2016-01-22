///
/***********************************************
 * Combat.h
 * Created by Matthew D Mayberry on 5/8/15
 * CS162_400_S2015_Assignment3
 ***********************************************/
///

#ifndef __COMBAT_H
#define __COMBAT_H

#include <stdio.h>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Character.h"
using namespace std;


class Character; // forward declaration
class Creature; // forward declaration

/////////////////////////////////////////////////
/***********************************************
 *               class Combat                  *
 ***********************************************/
/////////////////////////////////////////////////

class Combat
{

protected:

    
public:
    Combat();
    int damage(int atk, int def, int arm);

};

#endif
