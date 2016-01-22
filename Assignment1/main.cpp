//////
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 4/8/15
 * CS162_400_S2015_Assignment1.1
 ***********************************************/
//////

#include <iostream>
#include <stdio.h>
#include <vector>
#include "Grid.h"
using namespace std;


int main()
{
    int selection = 0;
    Grid grid1;
    
    cout << "This is John Horton Conway's Game of Life" << endl;
    cout << "Let's begin!" << endl;
    cout << "Select what pattern(s) you want to send to the GoL grid" << endl;
    do
    {
        cout << "Make a selection (1 - 5): " << endl;
        cout << "1) Add oscillator to grid" << endl;
        cout << "2) Add glider to grid" << endl;
        cout << "3) Add glider gun to grid" << endl;
        cout << "4) Start the game of life" << endl;
        cin >> selection;
        
        switch (selection)
        {
            case 1:
                grid1.placeOSC(grid1.uPlace(selection));
                break;
                
            case 2:
                grid1.placeGLR(grid1.uPlace(selection));
                break;
                
            case 3:
                grid1.placeGLRgun(grid1.uPlace(selection));
                break;
        }
        
    }while (selection != 4);
    grid1.playGame();
    
    return 0;
}



