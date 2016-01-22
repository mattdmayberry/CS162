///
/***********************************************
 * Dice.h
 * Created by Matthew D Mayberry on 2/7/15
 * CS161_400_W2015_Assignment5
 ***********************************************/
///

#ifndef DICE_H
#define DICE_H
#include <vector>
using namespace std;

class Dice
{
    
private:

    
protected:
    int numDice;
    int numSides;
    
public:
    Dice();
    Dice(int nS);
    int rollDice ();
};

#endif
