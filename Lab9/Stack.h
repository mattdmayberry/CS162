///
/***********************************************
 * Stack.h
 * Created by Matthew D Mayberry on 5/28/15
 * CS162_400_S2015_Lab9
 ***********************************************/
///

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stack>
#include <vector>
#include <string>

using namespace std;



/*   Stack class  */


class Stack
{
    
private:
    stack <char> myStack; // STL stack container
    stack <char> holder; // stack to temp hold the chars
    
public:
    void generatePalindrome(int length);
    char randomChar();
    
};

#endif
