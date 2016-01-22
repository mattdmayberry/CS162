///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 5/28/15
 * CS162_400_S2015_Lab9
 ***********************************************/
///

#include <iostream>
#include <stack>
#include <queue>
#include "Stack.h"
#include "Queue.h"

int main()
{
    int selection = 0; // user menu selection input
    int selection2 = 0; // user menu selection within queue buffer case 2 in switch
    int palLength = 0; // user specified palindrome length
    int insertChance = 0; // user input probability that an integer will be removed from the queue
    int removeChance = 0; // user input probability that an integer will be added to the queue
    Stack stack1; // stack object
    Queue queue1; // queue object


    do
    {
        cout << "Please select how to proceed:" << endl;
        cout << "1) Generate and print palindrome." << endl;
        cout << "2) Generate Queue buffer." << endl;
        cout << "3) Quit" << endl;
        cin >> selection;
    
        switch(selection)
        {
            case 1:
                cout << "Specify the length of the palindrome you wish to create:" << endl;
                cin >> palLength;
                stack1.generatePalindrome(palLength);
                cout << endl << endl;
                break;
            
            
            case 2:
                cout << "Enter the probability that the number will be added to the queue:" << endl;
                cin >> insertChance;
                cout << "Enter the probability that the number will be removed from the queue:" << endl;
                cin >> removeChance;
                do
                {
                    cout << "Please select how to proceed:" << endl;
                    cout << "1) Run probability round." << endl;
                    cout << "2) Return to menu." << endl;
                    cin >> selection2;
                    queue1.buffer(insertChance, removeChance);
                    cout << endl << endl;
                }while(selection2 < 2);
                break;
        }
    
    }while(selection < 3);
    
    return 0;
} // end main


