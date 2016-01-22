///
/***********************************************
 * Dice.cpp
 * Created by Matthew D Mayberry on 2/7/15
 * CS161_400_W2015_Assignment5
 ***********************************************/
///

#include "Dice.h"
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>


using namespace std;

Dice::Dice()
{
    numDice = 1;
    numSides = 6;
}

Dice::Dice(int nS)
{
    if (nS > 0)
    {
        numSides = nS;
    }
    else
    {
        numSides = 0;
        cout << "Sides cannot be negative!" << endl;
    }
}

int Dice::rollDice()
{
    int sum = 0;
    sum = (rand()%numSides)+1;
    return sum;
}




