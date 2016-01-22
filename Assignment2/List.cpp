//////
/***********************************************
 * List.cpp
 * Created by Matthew D Mayberry on 4/15/15
 * CS162_400_S2015_Assignment2
 ***********************************************/
//////

#include <iostream>
#include <stdio.h>
#include <vector>
#include <iomanip>
#include "List.h"
#include "Item.h"
#include "ClubItem.h"
using namespace std;


List::List()
{
    clubMember = false;
    memberCheck = false;
    idNum = 1;
}

/***********************************************
 *                  add2List                   *
 *  Allows user to add new item to their list  *
 ***********************************************/

void List::add2List()
{
    string name;
    string unit;
    cin.ignore();
    
    int qty;
    double cost;
    char club;
    char status;
    double subtotal;
    
    
    cout << "Enter the name of the item: " << endl;
    getline(cin,name);
    cout << "Enter the unit you intend to purchase (i.e. 'can' or 'pound'):" << endl;
    getline(cin,unit);
    cout << "Enter the quantity you intend to purchase:" << endl;
    cin >> qty;
    cout << "Enter the cost of the item ($/unit):" << endl;
    cin >> cost;
   

    if(clubMember == false && memberCheck == false)
    {
        cout << "Are you a Club member (Y / N):" << endl;
        cin >> club;
    }
    
    if (club == 'Y' || club == 'y' || clubMember == true)
    {
        clubMember = true;
        memberCheck = true;
        cout << "Is the item you intend to purchase eligible for Club discount (Y / N):" << endl;
        cin >> status;
        if (status == 'Y' || status == 'y')
        {
            ClubItem newClubItem; // create new ClubItem object
            newClubItem = ClubItem(name, unit, qty, cost, idNum); // assign item to new ClubItem object
            items.push_back(newClubItem); // send new ClubItem object to items vector
            idNum++;
        }
        else
        {
            Item newItem; // create new Item object
            newItem = Item(name, unit, qty, cost, idNum); // assign item to new Item object
            items.push_back(newItem); // send new Item object to itemList vector
            idNum++;
        }
    }
    
    if (club == 'N' || club == 'n')
    {
        memberCheck = true;
        Item newItem; // create new Item object
        subtotal = qty * cost;
        newItem = Item(name, unit, qty, cost, idNum); // assign item to new Item object
        items.push_back(newItem); // send new Item object to itemList vector
        idNum++;
    }
}

/***********************************************
 *               removeFromList                *
 * Allows user to remove item from their list  *
 ***********************************************/

void List::removeFromList()  // removes an item from the  appropriate vector
{
    int idInput;
    cout << "Enter the item's ID number that you would like to remove:" << endl;
    cin >> idInput;
    
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i].getIDNum() == idInput)
        {
            items.erase(items.begin()+i);
            return;
        }
    }
}

/***********************************************
 *               print2console                 *
 *    Allows user to print list to console     *
 ***********************************************/

void List::print2console() // prints list to console
{
    
    
    double costSum = 0;
    double total = 0;
    const char separator = ' ';
    const int width = 18;
    
    
    cout << left << setw(width) << setfill(separator) << "Num:";
    cout << left << setw(width) << setfill(separator) << "Item Name:";
    cout << left << setw(width) << setfill(separator) << "Item Unit:";
    cout << left << setw(width) << setfill(separator) << "Quantity:";
    cout << left << setw(width) << setfill(separator) << "$/Unit:";
    cout << left << setw(width) << setfill(separator) << "Subtotal:" << endl;
    
    for(int i = 0; i < items.size(); i++)
    {
        cout << left << setw(width) << setfill(separator) << items[i].getIDNum();
        cout << left << setw(width) << setfill(separator) << items[i].getName();
        cout << left << setw(width) << setfill(separator) << items[i].getUnit();
        cout << left << setw(width) << setfill(separator) << items[i].getQty();
        cout << left << setw(width) << setfill(separator) << fixed << setprecision(2) << items[i].getCost();
        cout << left << setw(width) << setfill(separator) << fixed << setprecision(2) << items[i].getSubtotal() << endl;
        
        costSum += items[i].getSubtotal();
    }
    
    total = costSum;
    cout << endl;
    cout << "Shopping list total: $" << total << endl;
    cout << endl;
}