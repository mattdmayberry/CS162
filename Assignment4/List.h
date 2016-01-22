///
/***********************************************
 * List.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <iostream>
#include "Character.h"
#include "Combat.h"
#include "Barbarian.h"
#include "Goblin.h"
#include "Reptile.h"
#include "BlueMen.h"
#include "Shadow.h"
#include "Stack.h"
#include "Queue.h"
using namespace std;



/*   List class  */

class List
{
    
private:

    
    
public:
    List();
    int createLineUp(string teamInput, Queue* playerQueue, Stack* playerStack, int qty, vector<Creature*> &allCombatants);
    
};


#endif