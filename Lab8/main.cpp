///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 5/17/15
 * CS162_400_S2015_Lab8
 ***********************************************/
///

#include <iostream>
#include "Stack.h"
#include "Queue.h"
using namespace std;

void printSLNodes(SLNode* myTop); // function prototype
void printDLNodes(DLNode* myFront); // function prototype

int main()
{
    int listChoice = 0; // user choice for type of linked list to create
    int selection = 0; // user selection for next action
    int myInt = 0; // user input integer
    
    cout << "What type of list would you like to create?:" << endl;
    cout << "1) Stack" << endl;
    cout << "2) Queue" << endl;
    cin >> listChoice;
    
    if(listChoice == 1)
    {
        Stack myStack;
        SLNode* myTop;
        
        do
        {
            cout << "Menu: " << endl;
            cout << "1) Add an item to the list" << endl;
            cout << "2) Remove an item from the list" << endl;
            cout << "3) Show the list" << endl;
            cout << "4) Quit" << endl;
            cin >> selection;
            
            switch (selection)
            {
                case 1:
                    cout << "Enter a number:" << endl;
                    cin >> myInt;
                    myStack.push(myInt);
                    break;
                    
                case 2:
                    if(myStack.isEmpty() == true)
                    {
                        cout << "This list is already empty." << endl;
                    }
                    else
                    {
                        myStack.pop();
                    }
                    break;
                    
                case 3:
                    myTop = myStack.getTop();
                    printSLNodes(myTop);
                    break;
            }
        }while(selection != 4);
    }
    
    if(listChoice == 2)
    {
        Queue myQueue;
        DLNode* myFront;
        
        do
        {
            cout << "Menu: " << endl;
            cout << "1) Add an item to the list" << endl;
            cout << "2) Remove an item from the list" << endl;
            cout << "3) Show the list" << endl;
            cout << "4) Quit" << endl;
            cin >> selection;
            
            switch (selection)
            {
                case 1:
                    cout << "Enter a number:" << endl;
                    cin >> myInt;
                    myQueue.addBack(myInt);
                    break;
                    
                case 2:
                    if(myQueue.isEmpty() == true)
                    {
                        cout << "This list is already empty." << endl;
                    }
                    else
                    {
                        myQueue.removeFront();
                    }
                    break;
                    
                case 3:
                    myFront = myQueue.getFront();
                    printDLNodes(myFront);
                    break;
            }
        }while(selection != 4);
    }
    cout << "Program has ended" << endl;
    return 0;
}



/***********************************************
 *                printSLNodes                 *
 *  if list is empty, prints empty to console  *
 *   otherwise prints list to console          *
 ***********************************************/

void printSLNodes(SLNode* current)
{
    if(current == NULL)
    {
        cout << "The list is empty. " << endl;
    }
    else
    {
        cout << "The list contains: " << endl;
        while (current != NULL)
        {
            cout << current->peek() << endl;
            current = current->getNextNode();
        }
    }
}

/***********************************************
 *                printDLNodes                 *
 *  if list is empty, prints empty to console  *
 *   otherwise prints list to console          *
 ***********************************************/

void printDLNodes(DLNode* current)
{
    if(current == NULL)
    {
        cout << "The list is empty. " << endl;
    }
    else
    {
        cout << "The list contains: " << endl;
        while (current != NULL)
        {
            cout << current->getData() << endl;
            current = current->getPrevNode();
        }
    }
}