///
/***********************************************
 * Queue.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <iostream>
#include "Character.h"
using namespace std;

class Stack; // forward declaration
class Creature; // forward declaration


/*   Stack class  */

class Stack
{
    
private:
    Creature* top;
    bool stackCheck;
    
    
public:
    Stack();
    ~Stack();
    void setTop(Creature* t);
    Creature* getTop();
    void add(Creature* newCreature);
    void pop();
    bool isEmpty();
    void print();
    
};


#endif