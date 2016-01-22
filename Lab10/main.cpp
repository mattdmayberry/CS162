///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 6/1/15
 * CS162_400_S2015_Lab10
 ***********************************************/
///




#include <iostream>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <vector>
using namespace std;


int fibR(int n);  // function prototype for the recursive function
int fibNR(int n); // function prototype for the non-recursive function

const char separator = ' ';
const int width = 28;

int main()
{
    cout << "In mathematics, the Fibonacci numbers or Fibonacci sequence " << endl;
    cout << "are the numbers in the following integer sequence: " << endl;
    cout << "0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ... " << endl << endl;
    
    int selection = 0;
    clock_t startR, finishR, startNR, finishNR; // clock_t variables for recursive and iterative algorithms
    int index = 0; // number of Fibonacci numbers to print
    double runTime = 0; // time to run each sequence
    double recursiveTime = 0; // recursive runTime in milliseconds
    double NonRecursiveTime = 0; // iterative runTime in milliseconds
    vector <double> recursiveResults; // vector to hold recursive runTime in milliseconds
    vector <double> NonRecursiveResults; // vector to hold iterative runTime in milliseconds
    vector <int> numbersGenerated; // vector to hold the numbers generated on each cycle
    
    do
    {
        cout << "Make a selection:" << endl;
        cout << "1) Generate a recursive and iterative Fibonacci sequence." << endl;
        cout << "2) Print measured times for Fibonacci sequence generation." << endl;
        cout << "3) Quit." << endl;
        cin >> selection;
        
        switch(selection)
        {
            case 1:
                cout << "How many numbers from the Fibonacci sequence would you like to calculate?:" << endl;
                
               
                cin >> index;
                
                cout << "The first " << index << " Fibonacci numbers, Fn for n = 0, ... " << (index - 1) << " are: "  << endl;
                
                // call recursive function
                cout << endl;
                startR = clock();
                cout << "Calculating the sequence recursively." << endl;
                for(int j = 0; j < index; j++)
                {
                    cout << fibR(j) << ", ";
                }
                cout << "..." << endl;
                finishR = clock();
                runTime = ((double)(finishR - startR));
                cout << "Recursive sequence generation time elapsed (milliseconds): ";
                recursiveTime = runTime / ((double)(CLOCKS_PER_SEC / 1000));
                cout << recursiveTime << endl;
                recursiveResults.push_back(recursiveTime); // send recursive time to recursiveResults vector
                cout << endl;
                runTime = 0; // reset runTime to 0
                
                // call iterative function
                startNR = clock();
                cout << "Calculating the sequence iteratively." << endl;
                for(int j = 0; j < index; j++)
                {
                    cout << fibNR(j) << ", ";
                }
                cout << "..." << endl;
                finishNR = clock();
                runTime = ((double)(finishNR - startNR));
                cout << "Iterative sequence generation time elapsed (milliseconds): ";
                NonRecursiveTime = runTime / ((double)(CLOCKS_PER_SEC / 1000));
                cout << NonRecursiveTime << endl;
                NonRecursiveResults.push_back(NonRecursiveTime); // send non-recursive time to nonRecursiveResults vector
                numbersGenerated.push_back(index);
                cout << endl;
                
                break;
                
            case 2:
                
                // print table headers
                cout << left;
                cout << setw(width) << setfill(separator) << "Analysis Number:";
                cout << setw(width) << setfill(separator) << "Numbers Generated:";
                cout << setw(width) << setfill(separator) << "Recursive Time (millisec):";
                cout << setw(width) << setfill(separator) << "Iterative Time (millisec)";
                cout << endl;
                
                int num = 1;
                
                // print results
                for(int i = 0; i < numbersGenerated.size(); i++)
                {
                    cout << left;
                    cout << setw(width) << setfill(separator) << num;
                    cout << setw(width) << setfill(separator) << numbersGenerated[i];
                    cout << setw(width) << setfill(separator) << recursiveResults[i];
                    cout << setw(width) << setfill(separator) << NonRecursiveResults[i];
                    cout << endl;
                    
                    num++; // increment number
                    
                }
                
                break;
        }
        
    }while(selection != 3);
    
    

    
    return 0;
}

//*********************************************
// Function fibR. Accepts an int argument *
// in n. This function returns the nth *
// Fibonacci number, calculated recursively*
//
//
// Gaddis, Tony; Walters, Judy; Muganda, Godfrey (2013-02-22).
// Starting Out with C++: Early Objects (8th Edition)
// (Page 910, Program 14-6). Pearson HE, Inc.. Kindle Edition.
//*********************************************

int fibR(int n)
{
    // n = 0 base case
    if (n == 0)
    {
        return 0;
    }
    
    // n = 1 base case
    else if (n == 1)
    {
        return 1;
    }
    
    // all other cases of n
    else
        return fibR(n - 1) + fibR(n - 2);
}


//*********************************************
// Function fibNR. Accepts an int argument *
// in n. This function returns the nth *
// Fibonacci number, calculated iteratively *
//*********************************************

int fibNR(int n)
{
    if ( n == 0 || n == 1 )
    {
        return n;
    }
    else
    {
        int f2 = 0;
        int f1 = 1;
        int curr = 0;
        
        for ( int i = 2; i <= n; i++ )
        {
            curr = f1 + f2;
            f2 = f1;
            f1 = curr;
        }
        
        return curr;
    }
}

