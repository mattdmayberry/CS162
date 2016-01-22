///
/***********************************************
 * List.cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "List.h"
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

List::List()
{
    
}

int List::createLineUp(string teamInput, Queue* playerQueue, Stack* playerStack, int qty, vector<Creature*> &allCombatants)
{
    string team = teamInput;
    // Queue playerQueue = playerQueue;
    int creatureQty = qty; // qty of creatures to add to queue
    cout << "Creature qty: " << creatureQty << "/" << qty <<endl;
    int selection = 0; // holds int for user selected creature to add to queue
    int creatureCtr = 0; // counts do/while menu loop iterations
    
    do
    {
        string creatureName = "";
        cout << team << " select a character to add to the battle:" << endl;
        cout << "1) Goblin" << endl;
        cout << "2) Barbarian" << endl;
        cout << "3) Shadow" << endl;
        cout << "4) Blue Men" << endl;
        cout << "5) Reptile person" << endl;
        cout << "6) Quit" << endl;
        cin >> selection;
        cin.ignore();
        
        //ignore stuff in buffer stream
        
        
        Creature *creature = NULL;
        
        switch(selection)
        {
            case 1:
                cout << "Enter a name for the Goblin:" << endl;
                getline(cin, creatureName);
                creature = new Goblin();
                creature->setName(creatureName);
                cout << "Adding " << creature->getName() << " the " << creature->getCreatureType() << " to " << team << "'s lineup." << endl;
                break;
                
            case 2:
                cout << "Enter a name for the Barbarian:" << endl;
                getline(cin, creatureName);
                creature = new Barbarian();
                creature->setName(creatureName);
                cout << "Adding " << creature->getName() << " the " << creature->getCreatureType() << " to " << team << "'s lineup." << endl;
                break;
                
            case 3:
                cout << "Enter a name for the Shadow:" << endl;
                getline(cin, creatureName);
                creature = new Shadow();
                creature->setName(creatureName);
                cout << "Adding " << creature->getName() << " the " << creature->getCreatureType() << " to " << team << "'s lineup." << endl;
                break;
                
            case 4:
                cout << "Enter a name for the Blue Men group:" << endl;
                getline(cin, creatureName);
                creature = new Blue();
                creature->setName(creatureName);
                cout << "Adding " << creature->getName() << " the " << creature->getCreatureType() << " group to " << team << "'s lineup." << endl;
                break;
                
            case 5:
                cout << "Enter a name for the Reptile Person:" << endl;
                getline(cin, creatureName);
                creature = new Reptile();
                creature->setName(creatureName);
                cout << "Adding " << creature->getName() << " the " << creature->getCreatureType() << " to " << team << "'s lineup." << endl;
                break;
                
            case 6:
                return 0;
                break;
                
        }
        //cin.ignore();
        creature->setTeam(team);
        playerQueue->addBack(creature);
        allCombatants.push_back(creature);
        creatureCtr++; // increment creature counter
        
    }while(creatureCtr <  creatureQty);
    
    creatureCtr = 0; // reset creature counter
    return 1;
}






