//////
/***********************************************
 * main.cpp
 * Created by Matthew D Mayberry on 4/15/15
 * CS162_400_S2015_Assignment2
 ***********************************************/
//////

#include <iostream>
#include <stdio.h>
#include <vector>
#include "List.h"
#include "Item.h"
#include "ClubItem.h"
using namespace std;

int main()
{
    List list1;
    int selection = 0;
    
    cout << "Shopping list app, created by Matt Mayberry" << endl;
    do
    {
        cout << "Select an option from the list below (1 - 4):" << endl;
        cout << "1) Add an item to your shopping list" << endl;
        cout << "2) Remove an item from your shopping list" << endl;
        cout << "3) Display the contents of your list" << endl;
        cout << "4) Quit" << endl;
        cin >> selection;
        
        switch (selection)
        {
            case 1:
                list1.add2List();
                break;
            case 2:
                list1.removeFromList();
                break;
            case 3:
                list1.print2console();
                break;
        }
    }while(selection != 4);
    cout << endl;
    cout << "Happy shopping!" << endl;
    cout << endl;
    
    return 0;
}