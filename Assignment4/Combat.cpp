///
/***********************************************
 * Combat.cpp
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Creature.h"
#include "Character.h"
#include "Barbarian.h"
#include "Goblin.h"
#include "Reptile.h"
#include "BlueMen.h"
#include "Shadow.h"
#include "Combat.h"
#include "Queue.h"
#include "Stack.h"


/*  Combat class  */

Combat::Combat()
{
    
}

void Combat::battle(Queue* p1, Queue* p2, Stack* losers, string team1, string team2)
{
    
    bool isOver = false;
    
    if (p1->isEmpty() || p2->isEmpty())
    {
        cout << "The battle is already over!" << endl;
        return;
    }
    
    do
    {
        Creature* fighter1 = p1->getFront();
        Creature* fighter2 = p2->getFront();
        p1->removeFront();
        p2->removeFront();
        
        // flip a coin to see which player will strike first
        int goFirst = (rand()%2)+1; // coin flip
        
        // introduce the next matchup
        cout << "Next up is " << "The " << fighter1->getCreatureType() << " from ";
        cout << fighter1->getTeam() << " named " << fighter1->getName() << endl;
        cout << "versus ";
        cout << "the " << fighter2->getCreatureType() << " from ";
        cout << fighter2->getTeam() << " named " << fighter2->getName() << endl << endl;
        
        
        //coin flip = 1
        if(goFirst == 1)
        {
            
            //loop until one creature is defeated
            do
            {
                //team1 fighter attacks team2 fighter
                fighter1Attack(fighter1, fighter2);
                
                //team2 fighter attacks team1 fighter
                fighter2Attack(fighter1, fighter2);
                
            }while(fighter1->getStrength() > 0 && fighter2->getStrength() > 0);
            
            //fighter1 was defeated
            if(fighter1->getStrength() == 0)
            {
                fighter1Defeated(fighter1, fighter2, losers, p1, p2);
            }
            
            //fighter2 was defeated
            if(fighter2->getStrength() == 0)
            {
                fighter2Defeated(fighter1, fighter2, losers, p1, p2);
            }
        }
        
        //coin flip = 2
        if(goFirst == 2)
        {
            //loop until one creature is defeated
            do
            {
                //team2 fighter attacks team1 fighter
                fighter2Attack(fighter1, fighter2);
                
                //team1 fighter attacks team2 fighter
                fighter1Attack(fighter1, fighter2);
                
            }while(fighter1->getStrength() > 0 && fighter2->getStrength() > 0);
            
            //fighter1 was defeated
            if(fighter1->getStrength() == 0)
            {
                fighter1Defeated(fighter1, fighter2, losers, p1, p2);
            }
            
            //fighter2 was defeated
            if(fighter2->getStrength() == 0)
            {
                fighter2Defeated(fighter1, fighter2, losers, p1, p2);
            }
        }
        
        
        // Check if p1 queue is empty
        if(p1->getFront() == NULL && p2->getFront() != NULL)
        {
            cout << team2 << " has won the battle!" << endl;
            isOver = true;
        }
        
        // Check if p1 queue is empty
        if(p2->getFront() == NULL && p1->getFront() != NULL)
        {
            cout << team1 << " has won the battle!" << endl;
            isOver = true;
        }
        
        
    }while(isOver != true);
    
    cout << endl;
    
    //the tournament is over
    cout << "What an epic tournament!" << endl;
}

int Combat::damage(int atk, int def, int arm)
{
    int a = atk;
    int d = def;
    int ar = arm;
    
    int dmg = a - d - ar;
    
    if (dmg < 0)
    {
        dmg = 0;
    }
    
    return dmg;
}

void Combat::fighter1Attack(Creature* fighter1, Creature* fighter2)
{
    
    int attackPts = 0;
    int defendPts = 0;
    int armPts = 0;
    int dmg = 0;
    
    attackPts = fighter1->attack();
    
    // Check if player2 had their dice cut in half
    if(fighter1->getGoblin12() == true)
    {
        fighter2->setAchilles();
    }
    defendPts = fighter2->defend();
    armPts = fighter2->getArmor();
    dmg = damage(attackPts, defendPts, armPts);
    // Check if the Shadow mesmerized the attacker
    if(defendPts == -1)
    {
        cout << fighter2->getName() << " the Shadow has mesmerized " << fighter1->getName() << " the " << fighter1->getCreatureType() << "." << endl;
        cout << "No damage was incured by " << fighter2->getName() <<  " the Shadow." << endl;
        dmg = 0;
    }
    else
    {
        cout << fighter1->getName() << " strikes " << fighter2->getName() << endl;
        fighter2->setStrength(dmg);
        cout << "The strike caused " << dmg << " damage to " << fighter2->getName() << endl;
        
        // Add damage points to the fighter1's score
        fighter1->setScore(dmg);
    }
}

void Combat::fighter2Attack(Creature* fighter1, Creature* fighter2)
{
    int attackPts = 0;
    int defendPts = 0;
    int armPts = 0;
    int dmg = 0;
    
    attackPts = fighter2->attack();
    
    // Check if player1 had their dice cut in half
    if(fighter2->getGoblin12() == true)
    {
        fighter1->setAchilles();
    }
    defendPts = fighter1->defend();
    armPts = fighter1->getArmor();
    dmg = damage(attackPts, defendPts, armPts);
    
    // Check if the Shadow mesmerized the attacker
    if(defendPts == -1)
    {
        cout << fighter1->getName() << " the Shadow has mesmerized " << fighter2->getName() << " the " << fighter2->getCreatureType() << "." << endl;
        cout << "No damage was incured by " << fighter1->getName() <<  " the Shadow." << endl;
        dmg = 0;
    }
    else
    {
        cout << fighter2->getName() << " strikes " << fighter1->getName() << endl;
        fighter1->setStrength(dmg);
        cout << "The strike caused " << dmg << " damage to " << fighter1->getName() << endl;
        
        // Add damage points to the fighter1's score
        fighter2->setScore(dmg);
    }
}

void Combat::fighter1Defeated(Creature* fighter1, Creature* fighter2, Stack* losers, Queue* p1, Queue* p2)
{
    // Generate a random number to apply to the winner for regenerated strength
    int numSides = 6;
    int regenerate = 0;
    regenerate += (rand()%numSides)+1;
    
    // send loser to stack
    Creature* loser = NULL;
    
    if(fighter1->getCreatureType() == "Goblin")
    {
        loser = new Goblin();
        loser->setName(fighter1->getName());
        loser->setTeam(fighter1->getTeam());
        loser->setStrength(fighter1->getStrength());
        losers->add(loser); // sent to stack
    }
    
    if(fighter1->getCreatureType() == "Barbarian")
    {
        loser = new Barbarian();
        loser->setName(fighter1->getName());
        loser->setTeam(fighter1->getTeam());
        loser->setStrength(fighter1->getStrength());
        loser->setScore(fighter1->getScore());
        losers->add(loser); // sent to stack
    }
    
    if(fighter1->getCreatureType() == "Shadow")
    {
        loser = new Shadow();
        loser->setName(fighter1->getName());
        loser->setTeam(fighter1->getTeam());
        loser->setStrength(fighter1->getStrength());
        loser->setScore(fighter1->getScore());
        losers->add(loser); // sent to stack
    }
    
    if(fighter1->getCreatureType() == "Blue Men")
    {
        loser = new Blue();
        loser->setName(fighter1->getName());
        loser->setTeam(fighter1->getTeam());
        loser->setStrength(fighter1->getStrength());
        loser->setScore(fighter1->getScore());
        losers->add(loser); // sent to stack
    }
    
    if(fighter1->getCreatureType() == "Reptile Person")
    {
        loser = new Reptile();
        loser->setName(fighter1->getName());
        loser->setTeam(fighter1->getTeam());
        loser->setStrength(fighter1->getStrength());
        loser->setScore(fighter1->getScore());
        losers->add(loser); // sent to stack
    }
    
    cout << "The " << loser->getCreatureType() << " from team " << loser->getTeam() << ", named ";
    cout << loser->getName() << ", has been sent to the loser list." << endl;
    
    // send winner to queue
    Creature* winner = NULL;
    
    if(fighter2->getCreatureType() == "Goblin")
    {
        winner = new Goblin();
        winner->setName(fighter2->getName());
        winner->setTeam(fighter2->getTeam());
        winner->setStrength((fighter2->getStrength()) + regenerate);
        winner->setScore(fighter2->getScore());
        p2->addBack(winner); // add to back
    }
    
    if(fighter2->getCreatureType() == "Barbarian")
    {
        winner = new Barbarian();
        winner->setName(fighter2->getName());
        winner->setTeam(fighter2->getTeam());
        winner->setStrength((fighter2->getStrength()) + regenerate);
        winner->setScore(fighter2->getScore());
        p2->addBack(winner); // add to back
        
    }
    
    if(fighter2->getCreatureType() == "Shadow")
    {
        winner = new Shadow();
        winner->setName(fighter2->getName());
        winner->setTeam(fighter2->getTeam());
        winner->setStrength((fighter2->getStrength()) + regenerate);
        winner->setScore(fighter2->getScore());
        p2->addBack(winner); // add to back
    }
    
    if(fighter2->getCreatureType() == "Blue Men")
    {
        winner = new Blue();
        winner->setName(fighter2->getName());
        winner->setTeam(fighter2->getTeam());
        winner->setStrength((fighter2->getStrength()) + regenerate);
        winner->setScore(fighter2->getScore());
        p2->addBack(winner); // add to back
    }
    
    if(fighter2->getCreatureType() == "Reptile Person")
    {
        winner = new Reptile();
        winner->setName(fighter2->getName());
        winner->setTeam(fighter2->getTeam());
        winner->setStrength((fighter2->getStrength()) + regenerate);
        winner->setScore(fighter2->getScore());
        p2->addBack(winner); // add to back
    }
    
    cout << fighter2->getName() << " has been sent back to " << fighter2->getTeam() << "'s lineup." << endl;
    
    
}

void Combat::fighter2Defeated(Creature* fighter1, Creature* fighter2, Stack* losers, Queue* p1, Queue* p2)
{
    // Generate a random number to apply to the winner for regenerated strength
    int numSides = 6;
    int regenerate = 0;
    regenerate += (rand()%numSides)+1;
    
    // send loser to stack
    Creature* loser = NULL;
    
    
    if(fighter2->getCreatureType() == "Goblin")
    {
        loser = new Goblin();
        loser->setName(fighter2->getName());
        loser->setTeam(fighter2->getTeam());
        loser->setStrength(fighter2->getStrength());
        loser->setScore(fighter2->getScore());
        losers->add(loser); // sent to stack
    }
    
    if(fighter2->getCreatureType() == "Barbarian")
    {
        loser = new Barbarian();
        loser->setName(fighter2->getName());
        loser->setTeam(fighter2->getTeam());
        loser->setStrength(fighter2->getStrength());
        loser->setScore(fighter2->getScore());
        losers->add(loser); // sent to stack
    }
    
    if(fighter2->getCreatureType() == "Shadow")
    {
        loser = new Shadow();
        loser->setName(fighter2->getName());
        loser->setTeam(fighter2->getTeam());
        loser->setStrength(fighter2->getStrength());
        loser->setScore(fighter2->getScore());
        losers->add(loser); // sent to stack
    }
    
    if(fighter2->getCreatureType() == "Blue Men")
    {
        loser = new Blue();
        loser->setName(fighter2->getName());
        loser->setTeam(fighter2->getTeam());
        loser->setStrength(fighter2->getStrength());
        loser->setScore(fighter2->getScore());
        losers->add(loser); // sent to stack
    }
    
    if(fighter2->getCreatureType() == "Reptile Person")
    {
        loser = new Reptile();
        loser->setName(fighter2->getName());
        loser->setTeam(fighter2->getTeam());
        loser->setStrength(fighter2->getStrength());
        loser->setScore(fighter2->getScore());
        losers->add(loser); // sent to stack
    }
    
    cout << "The " << loser->getCreatureType() << " from team " << loser->getTeam() << ", named ";
    cout << loser->getName() << ", has been sent to the loser list." << endl;
    
    // send winner to queue
    Creature* winner = NULL;
    
    if(fighter1->getCreatureType() == "Goblin")
    {
        winner = new Goblin();
        winner->setName(fighter1->getName());
        winner->setTeam(fighter1->getTeam());
        winner->setStrength((fighter1->getStrength()) + regenerate);
        winner->setScore(fighter1->getScore());
        p1->addBack(winner); // add to back
    }
    
    if(fighter1->getCreatureType() == "Barbarian")
    {
        winner = new Barbarian();
        winner->setName(fighter1->getName());
        winner->setTeam(fighter1->getTeam());
        winner->setStrength((fighter1->getStrength()) + regenerate);
        winner->setScore(fighter1->getScore());
        p1->addBack(winner); // add to back
    }
    
    if(fighter1->getCreatureType() == "Shadow")
    {
        winner = new Shadow();
        winner->setName(fighter1->getName());
        winner->setTeam(fighter1->getTeam());
        winner->setStrength((fighter1->getStrength()) + regenerate);
        winner->setScore(fighter1->getScore());
        p1->addBack(winner); // add to back
    }
    
    if(fighter1->getCreatureType() == "Blue Men")
    {
        winner = new Blue();
        winner->setName(fighter1->getName());
        winner->setTeam(fighter1->getTeam());
        winner->setStrength((fighter1->getStrength()) + regenerate);
        winner->setScore(fighter1->getScore());
        p1->addBack(winner); // add to back
    }
    
    if(fighter1->getCreatureType() == "Reptile Person")
    {
        winner = new Reptile();
        winner->setName(fighter1->getName());
        winner->setTeam(fighter1->getTeam());
        winner->setStrength((fighter1->getStrength()) + regenerate);
        winner->setScore(fighter1->getScore());
        p1->addBack(winner); // add to back
    }
    
    cout << fighter1->getName() << " has been sent back to " << fighter1->getTeam() << "'s lineup." << endl;
    
}






