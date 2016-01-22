///
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 5/8/15
 * CS162_400_S2015_Assignment3
 ***********************************************/
///

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Character.h"
#include "Combat.h"

using namespace std;

int main()
{
    
    Creature *battle[2]; // array of creature objects
    
    Combat fight; // combat object
    
    Barbarian barb; // goblin object
    Goblin gob; // goblin object
    Reptile rept; // reptile person object
    Blue blu; // blue men object
    Shadow shad; // shadow object

    int attack = 0;
    int defend = 0;
    int armor = 0;
    int dam = 0;
    int selection = 0;
    
    cout << "Welcome to the world of GameHenge." << endl << endl;
    cout << "In GameHenge there are a variety of creatures and heros." << endl;
    cout << "Let's begin our adventure" << endl << endl;

    cout << "Select the first character to battle" << endl;
    cout << "1) Goblin" << endl;
    cout << "2) Barbarian" << endl;
    cout << "3) Shadow" << endl;
    cout << "4) Blue Men" << endl;
    cout << "5) Reptile person" << endl;
    cout << "6) Quit" << endl;
    cin >> selection;
        
        
    switch(selection)
    {
        case 1:
            battle[0] = &gob;
            cout << "Adding " << battle[0]->getName() << " to the fight!" << endl << endl;
            break;
                
        case 2:
            battle[0] = &barb;
            cout << "Adding " << battle[0]->getName() << " to the fight!" << endl << endl;
            break;
                
        case 3:
            battle[0] = &shad;
            cout << "Adding " << battle[0]->getName() << " to the fight!" << endl << endl;
            break;
                
        case 4:
            battle[0] = &blu;
            cout << "Adding " << battle[0]->getName() << " to the fight!" << endl << endl;
            break;
                
        case 5:
            battle[0] = &rept;
            cout << "Adding " << battle[0]->getName() << " to the fight!" << endl << endl;
            break;
        }

    cout << "Select the second character to battle" << endl;
    cout << "1) Goblin" << endl;
    cout << "2) Barbarian" << endl;
    cout << "3) Shadow" << endl;
    cout << "4) Blue Men" << endl;
    cout << "5) Reptile person" << endl;
    cout << "6) Quit" << endl;
    cin >> selection;
    
    
    switch(selection)
    {
        case 1:
            battle[1] = &gob;
            cout << "Adding " << battle[1]->getName() << " to the fight!" << endl << endl;
            break;
            
        case 2:
            battle[1] = &barb;
            cout << "Adding " << battle[1]->getName() << " to the fight!" << endl << endl;
            break;
            
        case 3:
            battle[1] = &shad;
            cout << "Adding " << battle[1]->getName() << " to the fight!" << endl << endl;
            break;
            
        case 4:
            battle[1] = &blu;
            cout << "Adding " << battle[1]->getName() << " to the fight!" << endl << endl;
            break;
            
        case 5:
            battle[1] = &rept;
            cout << "Adding " << battle[1]->getName() << " to the fight!" << endl << endl;
            break;
    }

    do
    {
        attack = 0;
        defend = 0;
        armor = 0;
        dam = 0;
        selection = 0;
        cout << "Select how to proceed!" << endl;
        cout << "1) " << battle[0]->getName() << " attacks the " << battle[1]->getName() << endl;
        cout << "2) " << battle[1]->getName() << " attacks the " << battle[0]->getName() << endl;
        cout << "3) Show charactor information " << endl;
        cin >> selection;
    
        if(selection == 1)
        {
            cout << battle[0]->getName() << " strikes at the " << battle[1]->getName() << endl;
            
            // char1 attacks char2
            attack = battle[0]->attack();
            
            // if the attacker is a goblin and he rolls 12, defender rolls half attack remainder of game
            if((attack == 12 && battle[0]->getName() == "Goblin") && battle[1]->getName() != "Goblin")
            {
                int d = (battle[1]->getDice() / 2);
                battle[1]->setDice(d);
            }
            
            //char2 defends
            defend = battle[1]->defend();
            

            
            //Determin if the Shadow was able to mesmerize the attacker
            if(battle[1]->getName() == "Shadow")
            {
                int odds = (rand()%10)+1;
                if(odds != 1)
                {
                    cout << "The " << battle[1]->getName() << " has mesmerized the " <<  battle[0]->getName() << endl;
                    cout << "No damage was incurred by the " << battle[1]->getName() << endl;
                }
            }

            
            sound
        }
        
    
        if(selection == 2)
        {
            cout << battle[1]->getName() << " strikes at the " << battle[0]->getName() << endl;
            
            // char2 attacks char1
            attack = battle[1]->attack();
        
            // if the attacker is a goblin and he rolls 12, defneder rolls half attack remainder of game
            if((attack == 12 && battle[1]->getName() == "Goblin") && battle[0]->getName() != "Goblin")
            {
                int d = (battle[0]->getDice() / 2);
                battle[0]->setDice(d);
            }
        
            //char1 defends
            defend = battle[0]->defend();
            armor = battle[0]->getArmor();
        

            
            //Determin if the Shadow was able to mesmerize the attacker
            if(battle[0]->getName() == "Shadow")
            {
                int odds = (rand()%10)+1;
                if(odds != 1)
                {
                    cout << "The " << battle[0]->getName() << " has mesmerized the " <<  battle[1]->getName() << endl;
                    cout << "No damage was incurred by the " << battle[0]->getName() << endl;
                }
            }

            //apply damage
            dam = fight.damage(attack, defend, armor);
            if(dam == 0)
            {
                cout << "No damage was incurred by the " << battle[0]->getName() << endl;
            }
            else
            {
                cout << battle[0]->getName() << " has incurred a strike by the " << battle[1]->getName() << endl;
                cout << dam << " strength points have been deducted from the " << battle[0]->getName() << endl;
                battle[0]->setStrength(dam);
            }
        }
        
        if(selection == 3)
        {
            cout << battle[0]->getName() << ":" << endl;
            cout << "Strength: " << battle[0]->getStrength() << endl;
            cout << "Armor: " << battle[0]->getArmor() << endl << endl;
            
            cout << battle[1]->getName() << ":" << endl;
            cout << "Strength: " << battle[1]->getStrength() << endl;
            cout << "Armor: " << battle[1]->getArmor() << endl << endl;
        }
        
    }while (battle[0]->getStrength() > 0 && battle[1]->getStrength() > 0);
    
    if(battle[0]->getStrength() <= 0)
    {
        cout << battle[0]->getName() << " has been slain by the " << battle[1]->getName() << "!" << endl;
    }
    
    if(battle[1]->getStrength() <= 0)
    {
        cout << battle[1]->getName() << " has been slain by the " << battle[0]->getName() << "!" << endl;
    }
    
    return 0;
    
}