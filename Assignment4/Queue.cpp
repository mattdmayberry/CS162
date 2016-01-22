///
/***********************************************
 * Queue.cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#include <stdio.h>
#include <iomanip>
#include "Queue.h"
#include "Character.h"
#include "Creature.h"
using namespace std;

/* Queue */

const char separator = ' ';
const int width = 20;

Queue::Queue()
{
    front = NULL;
    back = NULL;
}
Queue::~Queue()
{
    Creature* curr = front;
    
    while(curr!= NULL)
    {
        Creature* next = curr->getNextNode();
        delete curr;
        curr = next;
    }
}

void Queue::setFront(Creature* f)
{
    front = f;
}

Creature* Queue::getFront()
{
    return front;
}

void Queue::setBack(Creature* b)
{
    back = b;
}

Creature* Queue::getBack()
{
    return back;
}

void Queue::addBack(Creature* newCreature)
{
    queueCheck = false;
    if(front == NULL)
    {
        newCreature->setNextNode(NULL);
        newCreature->setPrevNode(NULL);
        front = newCreature;
        back = newCreature;
    }
    else
    {
        newCreature->setNextNode(back);
        newCreature->setPrevNode(NULL);
        back->setPrevNode(newCreature);
        back = newCreature;
    }
}

void Queue::removeFront()
{
    
    if(front == NULL)
    {
        cout << "The Queue is already empty." << endl;
    }
    else
    {
        Creature* temp = front;
        
        
        if(temp->getPrevNode() == NULL && temp->getNextNode() == NULL)
        {
            back = NULL;
        }
        
        front = front->getPrevNode();
        
        //check front is not null first
        if(front != NULL)
        {
            front->setNextNode(NULL);
            temp->setPrevNode(NULL);
        }
        
        //delete temp;
        temp = NULL;

    }
}

bool Queue::isEmpty()
{
    if(front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}



void Queue::print()
{
    Creature* curr = back;
    
    
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

