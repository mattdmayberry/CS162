//
// *  Course:  CS162_400_S2015
// *  Assignment: Lab 1-1
// *  File: lab1-1.cpp
// *  Author: Matt Mayberry
// *  Date:  4/1/15.
//

#include <iostream>
using namespace std;

// smallSort function prototype
void smallSort(int *x, int *y, int *z);

int main()
{
    // Initiate x,y,z to 0
    int x, y, z = 0;
    
    // Ask user to enter 3 integers
    cout << "Enter 3 integers: " << endl;
    cout << "Integer x: " << endl;
    cin >> x;
    cout << "Integer y: " << endl;
    cin >> y;
    cout << "Integer z: " << endl;
    cin >> z;
    
    // print integers before they are sent to the sort function
    cout << "-----------------------------" << endl;
    cout << "Before sort function: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    
    // call smallSort
    smallSort(&x, &y, &z);
    
    // print integers after they are sent to the sort function
    cout << endl;
    cout << "After sort function: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    
    return 0;
}


// Function smallSort
void smallSort(int *x, int *y, int *z)
{
    // sort int values
    do
    {
        if(*z < *y) swap(*z, *y);
        if(*y < *x) swap(*x, *y);
        
    }while (*x > *z);
}

