///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <vector>
#include "Character.h"
#include "List.h"
#include "Combat.h"
#include "Barbarian.h"
#include "Goblin.h"
#include "Reptile.h"
#include "BlueMen.h"
#include "Shadow.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

void printWinners(vector<Creature*> allCombatants);

int main()
{
    string team1 = ""; // team 1 name
    string team2 = ""; // team 2 name
    int creatureQty = 0; // number of creatures on each team
    
    List newList; // list object
    Combat fight; // combat object
    Stack stack; // losers
    Queue p1Queue; // player 1 creature queue
    Queue p2Queue; // player 2 creature queue
    vector<Creature*> allCombatants; // vector of Creature ptrs for all combatants
    
    cout << "Welcome to the battle!" << endl;
    cout << "Player One, enter the name for your team: " << endl;
    getline(cin,team1);
    cout << "Player Two, enter the name for your team: " << endl;
    getline(cin,team2);
    cout << "How many creatures will play on each team?:" << endl;
    cin >> creatureQty;
    cin.ignore();
    
    newList.createLineUp(team1, &p1Queue, &stack, creatureQty, allCombatants); // create player 1 lineup
    newList.createLineUp(team2, &p2Queue, &stack, creatureQty, allCombatants); // create player 2 lineup
    
    int selection = 0; // do while menu selection holder
    
    do
    {
        cout << "Make a selection:" << endl;
        cout << "1) Begin battle." << endl;
        cout << "2) Print " << team1 << " lineup." << endl;
        cout << "3) Print " << team2 << " lineup." << endl;
        cout << "4) Print loser list." << endl;
        cout << "5) Quit." << endl;
        cin >> selection;
        cin.ignore();
        
        switch(selection)
        {
            case 1:
                fight.battle(&p1Queue, &p2Queue, &stack, team1, team2);
                printWinners(allCombatants);
                break;
                
            case 2:
                p1Queue.print();
                break;
                
            case 3:
                p2Queue.print();
                break;
                
            case 4:
                stack.print();
                break;
        }
        
    }while(selection < 5);
    return 0;
}



/*  printWinners */

void printWinners(vector<Creature*> allCombatants)
{
    if(allCombatants.empty())
    {
        cout << "There are no results to show." << endl;
        return;
    }
    
    cout << "Tournament Results:" << endl;
    const char separator = ' ';
    const int width = 20;
    
    
    vector <Creature*> winners(3);
    
    for(int i=0; i < 3; i++) // winners loop
    {
        Creature* high = allCombatants[0];
        int combatantIndex = 0;
        
        for(int j = 1; j < allCombatants.size(); j++) // combatants loop
        {
            if(allCombatants[j]->getScore() > high->getScore())
            {
                high = allCombatants[j];
                combatantIndex = j;
            }
        }
        
        winners[i] = high; // add winner to winners vector
        allCombatants.erase(allCombatants.begin() + combatantIndex); // erase winner from allCombatants vector
    }
    
    // Print the winners to the console
    // print table headers
    cout << left;
    cout << setw(width) << setfill(separator) << "Score:";
    cout << setw(width) << setfill(separator) << "Team:";
    cout << setw(width) << setfill(separator) << "Creature Type:";
    cout << setw(width) << setfill(separator) << "Name:";
    cout << setw(width) << setfill(separator) << "Stength:";
    cout << endl;
    
    for(int k=0; k < 3; k++)
    {
        cout << left;
        cout << setw(width) << setfill(separator) << winners[k]->getScore();
        cout << setw(width) << setfill(separator) << winners[k]->getTeam();
        cout << setw(width) << setfill(separator) << winners[k]->getCreatureType();
        cout << setw(width) << setfill(separator) << winners[k]->getName();
        cout << setw(width) << setfill(separator) << winners[k]->getStrength();
        cout << endl;
    } //end for loop
    
} //end print winners
