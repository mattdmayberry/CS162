///
/***********************************************
 * LoadedDice.h
 * Created by Matthew D Mayberry on 2/7/15
 * CS161_400_W2015_Assignment5
 ***********************************************/
///

#include "Dice.h"

class Dice; // forward declaration

#ifndef LOADEDDICE_H
#define LOADEDDICE_H

class LoadedDice : public Dice
{
    
private:
    
    
protected:

    
public:
    LoadedDice();
    LoadedDice(int nS);
    int rollDice();
};

#endif