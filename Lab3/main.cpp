///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 2/7/15
 * CS161_400_W2015_Assignment5
 ***********************************************/
///

#include "Dice.h"
#include "LoadedDice.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int sides = 0;
    int dice;
    int rolls;
    int result = 0;
    int LDresult = 0;

    cout << "Would you like to roll one or two dice?" << endl;
    cout << "1) One dice" << endl;
    cout << "2) Two dice" << endl;
    cin >> dice;

    
    cout << "Enter number of sides for the dice: " << endl;
    cin >> sides;
    Dice dice1 (sides);
    Dice dice2 (sides);
    LoadedDice Ldice1 (sides);
    LoadedDice Ldice2 (sides);
    
    cout << "How many times would you like to roll?" << endl;
    cin >> rolls;
    
    // create export file
    ofstream roll_Data;
    roll_Data.open("Roll_Data.csv");
    roll_Data << "Roll,Dice Results,Loaded Results" << endl;
    
    // print results to console and csv
    for(int i = 0; i < rolls; ++i)
    {
        if(dice == 1)
        {
            for( int i = 0; i < rolls; i++)
            result = dice1.rollDice();
            LDresult = Ldice1.rollDice();
        }
        
        else
        {
            result = dice1.rollDice() + dice2.rollDice();
            LDresult = Ldice1.rollDice() + Ldice2.rollDice();;
        }
        cout << i + 1 << ")" << result << ", " << LDresult << endl;
        roll_Data << i + 1 << "," << result << "," << LDresult << endl;
    }
    
    return 0;
}
