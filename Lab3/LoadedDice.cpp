///
/***********************************************
 * LoadedDice.cpp
 * Created by Matthew D Mayberry on 2/7/15
 * CS161_400_W2015_Assignment5
 ***********************************************/
///

#include "Dice.h"
#include "LoadedDice.h"
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>


using namespace std;

LoadedDice::LoadedDice()
{
    numDice = 1;
    numSides = 6;
}

LoadedDice::LoadedDice(int nS)
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

int LoadedDice::rollDice()
{
    int sum = 0;
    sum = (rand()%numSides)+1;
    
    if(sum * 2 >= numSides)
    {
        sum = numSides;
    }
    else
    {
        sum = sum * 2;
    }
    
    return sum;
}

