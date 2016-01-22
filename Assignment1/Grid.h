//////
/***********************************************
 * Grid.h
 * Created by Matthew D Mayberry on 4/8/15
 * CS162_400_S2015_Assignment1.1
 ***********************************************/
//////

#include <stdio.h>
#include <vector>

#ifndef __GRID_H
#define __GRID_H



class Grid
{
    
private:
    const static int width = 80;
    const static int height = 60;
    bool grid[height][width];
    bool tempGrid[height][width];
    
public:
    Grid();
    int uPlace(int selection);
    void matchGrids();
    void placeOSC(int location);
    void placeGLR(int location);
    void placeGLRgun(int location);
    void generate();
    void print2Console();
    void playGame();
    
};

#endif