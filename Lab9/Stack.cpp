///
/***********************************************
 * Stack.cpp
 * Created by Matthew D Mayberry on 5/28/15
 * CS162_400_S2015_Lab9
 ***********************************************/
///

#include "Stack.h"
#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>

/*  Stack class  */

void Stack::generatePalindrome(int length)
{
    for(int i = 0; i < (length/2); i++)
    {
        char c = randomChar();
        myStack.push(c);
    }
    
    while(!myStack.empty())
    {
        char c = myStack.top();
        cout << c;
        holder.push(c);
        myStack.pop();
    }
    
    while(!holder.empty())
    {
        char c = holder.top();
        cout << c;
        holder.pop();
    }
}

char Stack::randomChar()
{
    int randomInt = rand() % 26;
    char int2char = (char)(randomInt + 65);
    return int2char;
}