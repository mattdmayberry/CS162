
///
/***********************************************
 * Stack.cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#include <stdio.h>
#include <vector>
#include <iomanip>
#include "Stack.h"
#include "Character.h"
#include "Creature.h"
using namespace std;

/* Stack class */

const char separator = ' ';
const int width = 20;

Stack::Stack()
{
    top = NULL;
    stackCheck = true;
}

Stack::~Stack()
{
    Creature* curr = top;
    
    while(curr!= NULL)
    {
        Creature* next = curr->getNextNode();
        delete curr;
        curr = next;
    }
}

void Stack::setTop(Creature* t)
{
    top = t;
}

Creature* Stack::getTop()
{
    return top;
}

void Stack::add(Creature* newCreature)
{
    stackCheck = false; // flip bool switch so it knows there are files in the stack
    
    if(top == NULL)
    {
        top = newCreature;
        top->setNextNode(NULL);
    }
    else
    {
        //make the "next" attribute of "newNode" equal to top
        newCreature->setNextNode(top);
        top = newCreature;
    }
}

void Stack::pop()
{
    Creature* temp = top; // make a temp object to hold the top
    top = top->getNextNode(); // top equals 2nd item in list
    //delete temp; // delete the previous top
    temp = NULL;
}

bool Stack::isEmpty()
{
    if(top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Stack::print()
{
    Creature* curr = top;
    
    if(curr == NULL)
    {
        cout << "No losers in the list." << endl;
    }
    else
    {
    
        // print table headers
        cout << left;
        cout << setw(width) << setfill(separator) << "Score:";
        cout << setw(width) << setfill(separator) << "Team:";
        cout << setw(width) << setfill(separator) << "Creature Type:";
        cout << setw(width) << setfill(separator) << "Name:";
        cout << setw(width) << setfill(separator) << "Stength:";
        cout << endl;
    
        while(curr!= NULL)
        {
            Creature* next = curr->getNextNode();
        
            cout << setw(width) << setfill(separator) << curr->getScore();
            cout << setw(width) << setfill(separator) << curr->getTeam();
            cout << setw(width) << setfill(separator) << curr->getCreatureType();
            cout << setw(width) << setfill(separator) << curr->getName();
            cout << setw(width) << setfill(separator) << curr->getStrength();
            cout << endl;
        
            curr = next;
        }
    }
}
