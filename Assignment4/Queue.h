///
/***********************************************
 * Queue.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdio.h>
#include "Character.h"
using namespace std;

class Queue; // forward delcaration
class Creature; // forward declaration


/*   Queue class  */

class Queue
{
    
private:
    Creature* front;
    Creature* back;
    bool queueCheck;
    
    
public:
    Queue();
    ~Queue();
    void setFront(Creature* f);
    Creature* getFront();
    void setBack(Creature* b);
    Creature* getBack();
    void addBack(Creature* newCreature);
    void removeFront();
    bool isEmpty();
    void print();
    
};

#endif