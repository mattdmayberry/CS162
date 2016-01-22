///
/***********************************************
 * Creature.h
 * Created by Matthew D Mayberry on 5/24/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///
#ifndef CREATURE_H
#define CREATURE_H

#include "Character.h"
#include <string>
using std::string;

/*   Creature class  */

class Creature : public Character
{
    
protected:
    string creatureType;
    Creature* nextNode;
    Creature* prevNode;
    bool goblin12;
    bool achilles;
    int score;
    
public:
    Creature();
    string getCreatureType();
    int attack();
    int defend();
    void setNextNode(Creature* next);  // stack and queue node position
    Creature* getNextNode();   // stack and queue node position
    void setPrevNode(Creature* prev);  // stack and queue node position
    Creature* getPrevNode();  // stack and queue node position
    bool getGoblin12();
    void setAchilles();
    void setScore(int s);
    int getScore();
};
#endif