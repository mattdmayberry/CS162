//////
/***********************************************
 * Grid.cpp
 * Created by Matthew D Mayberry on 4/8/15
 * CS162_400_S2015_Assignment1.1
 ***********************************************/
/////

#include "Grid.h"
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

/***********************************************
 *                Grid()                       *
 *   Constructor that initializes all cells    *
 *   in the array to "false"                   *
 ***********************************************/

Grid::Grid()
{
    for (int i = 0 ; i < height ; i++ )
    {
        for (int j = 0 ; j < width ; j++ )
        {
            tempGrid[i][j] = false;
            grid[i][j] = tempGrid[i][j];
        }
    }
}

/***********************************************
 *                uPlace()                     *
 *   Allows user to place selected pattern     *
 *   on grid                                   *
 ***********************************************/

int Grid::uPlace(int selection)
{
    int uSelect = 0;
    
    if(selection == 1 || selection == 2)
    {
        cout << "Where would you like to place the pattern?" << endl;
        cout << "1) Upper left quadrant" << endl;
        cout << "2) Upper right quadrant" << endl;
        cout << "3) Lower left quadrant" << endl;
        cout << "4) Lower right quadrant" << endl;
        cout << "5) Center" << endl;
        cin >> uSelect;
    }
    else
    {
        cout << "Glider gun has been sent to the grid!" << endl << endl << endl;
        uSelect = 1;
    }
    
    return uSelect;
}

/***********************************************
 *                placeOSC()                   *
 *      Allows user to place oscillator(s)     *
 *                 on grid                     *
 ***********************************************/
void Grid::placeOSC(int location)
{
    //upper left quadrant
    if(location == 1)
    {
        tempGrid[25][30] = true;
        tempGrid[26][30] = true;
        tempGrid[27][30] = true;
    }
    //upper right quadrant
    if(location == 2)
    {
        tempGrid[25][50] =true;
        tempGrid[26][50] = true;
        tempGrid[27][50]=true;
    }
    //lower left quadrant
    if(location == 3)
    {
        tempGrid[34][30] = true;
        tempGrid[35][30] = true;
        tempGrid[36][30]= true;
    }
    //lower right quadrant
    if(location == 4)
    {
        tempGrid[34][50] = true;
        tempGrid[35][50] = true;
        tempGrid[36][50]= true;
    }
    //center
    if(location == 5)
    {
        tempGrid[29][40] = true;
        tempGrid[30][40] = true;
        tempGrid[31][40]= true;
    }
    //call matchGrids
    matchGrids();
}

/***********************************************
 *                placeGLR()                   *
 *       Allows user to place glider(s)        *
 *                on grid                      *
 ***********************************************/
void Grid::placeGLR(int location)
{
    //upper left quadrant
    if(location == 1)
    {
        tempGrid[24][30] = true;
        tempGrid[25][31] = true;
        tempGrid[26][31] = true;
        tempGrid[26][30] = true;
        tempGrid[26][29] = true;
    }
    //upper right quadrant
    if(location == 2)
    {
        tempGrid[24][50] = true;
        tempGrid[25][51] = true;
        tempGrid[26][51] = true;
        tempGrid[26][50] = true;
        tempGrid[26][49] = true;
    }
    //lower left quadrant
    if(location == 3)
    {
        tempGrid[34][30] = true;
        tempGrid[35][31] = true;
        tempGrid[36][31] = true;
        tempGrid[36][30] = true;
        tempGrid[36][29] = true;
    }
    //lower right quadrant
    if(location == 4)
    {
        tempGrid[34][50] = true;
        tempGrid[35][51] = true;
        tempGrid[36][51] = true;
        tempGrid[36][50] = true;
        tempGrid[36][49] = true;
    }
    //center
    if(location == 5)
    {
        tempGrid[29][40] = true;
        tempGrid[30][41] = true;
        tempGrid[31][41] = true;
        tempGrid[31][40] = true;
        tempGrid[31][39] = true;
    }
    //call matchGrids
    matchGrids();
}

/***********************************************
 *             placeGLRgun()                   *
 *        Populates glider gun on grid         *
 ***********************************************/
void Grid::placeGLRgun(int location)
{
    //Lower half
    if(location == 1)
    {
        tempGrid[26][22] = true;
        tempGrid[26][23] = true;
        tempGrid[27][22] = true;
        tempGrid[27][23] = true;
        tempGrid[24][56] = true;
        tempGrid[24][57] = true;
        tempGrid[25][56] = true;
        tempGrid[25][57] = true;
        tempGrid[24][34] = true;
        tempGrid[24][35] = true;
        tempGrid[25][33] = true;
        tempGrid[26][32] = true;
        tempGrid[27][32] = true;
        tempGrid[28][32] = true;
        tempGrid[29][33] = true;
        tempGrid[30][34] = true;
        tempGrid[30][35] = true;
        tempGrid[27][36] = true;
        tempGrid[25][37] = true;
        tempGrid[29][37] = true;
        tempGrid[26][38] = true;
        tempGrid[27][38] = true;
        tempGrid[28][38] = true;
        tempGrid[27][39] = true;
        tempGrid[24][42] = true;
        tempGrid[24][43] = true;
        tempGrid[25][42] = true;
        tempGrid[25][43] = true;
        tempGrid[26][42] = true;
        tempGrid[26][43] = true;
        tempGrid[23][44] = true;
        tempGrid[27][44] = true;
        tempGrid[22][46] = true;
        tempGrid[23][46] = true;
        tempGrid[27][46] = true;
        tempGrid[28][46] = true;
        
    }
    //call matchGrids
    matchGrids();
}

/***********************************************
 *                generate()                   *
 *     Generates next "state" of the grid      *
 ***********************************************/
void Grid::generate()
{
    int cellNeighbors = 0;
    

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width ; j++)
        {
            if ((i+1) < height && grid[i + 1][j] == true)
            {
                cellNeighbors++;
            }
            if ((i-1) >= 0 && grid[i - 1][j] == true)
            {
                cellNeighbors++;
            }
            if ((j+1) < width && grid[i][j+1] == true)
            {
                cellNeighbors++;
            }
            if ((j-1) >= 0 && grid[i][j-1] == true)
            {
                cellNeighbors++;
            }
            if ((i+1) < height && (j+1) < width && grid[i+1][j+1] == true)
            {
                cellNeighbors++;
            }
            if ((i+1) < height && (j-1) >= 0 && grid[i+1][j-1] == true)
            {
                cellNeighbors++;
            }
            if ((i-1) >= 0 && (j+1) < width && grid[i-1][j+1] == true)
            {
                cellNeighbors++;
            }
            if ((i-1) >= 0 && (j-1) >= 0 && grid[i-1][j-1] == true)
            {
                cellNeighbors++;
            }
            
            if (cellNeighbors < 2 || cellNeighbors > 3)
            {
                tempGrid[i][j] = false;
            }
            else if (cellNeighbors == 2)
            {
                tempGrid[i][j] = grid[i][j];
            }
            else if (cellNeighbors == 3)
            {
                tempGrid[i][j] = true;
            }
            
            cellNeighbors = 0;
            
        }
    }
  //match tempGrid to grid
    matchGrids();

}
/***********************************************
 *                matchGrid()                  *
 *      syncs grid[][] with tempGrid[][]       *
 ***********************************************/
void Grid::matchGrids()
{
    for (int i = 0 ; i < height ; i++ )
    {
        for (int j = 0 ; j < width ; j++ )
        {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

/***********************************************
 *                print2Console()              *
 *       Prints 20x40 "window" to console      *
 ***********************************************/
void Grid::print2Console()
{
    for (int i = 20; i < 40; i++ )
    {
        for (int j = 20 ; j < 60; j++ )
        {
            if (grid[i][j] == true )
            {
                cout << "X";
            }
            else
            {
                cout << " ";
            }
            
            if ( (j + 1) >= 60)
            {
                cout << endl;
            }
        }
    }
}

/***********************************************
 *                playGame()                   *
 *       Allows the user to make game moves    *
 ***********************************************/
void Grid::playGame()
{
    int selection;
    do
    {
        matchGrids();
        print2Console();
        cout << "Make a selection: " << endl;
        cout << "1) Create generation" << endl;
        cout << "2) Quit" << endl;
        cin >> selection;
        
        if(selection == 1)
        {
            generate();
            print2Console();
        }
        cout << endl << endl;
    }while(selection != 2);

}

