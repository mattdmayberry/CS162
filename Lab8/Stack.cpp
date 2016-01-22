
///
/***********************************************
 * Stack.cpp
 * Created by Matthew D Mayberry on 5/22/15
 * CS162_400_S2015_Lab8
 ***********************************************/
///

#include "Stack.h"
using namespace std;

/* SLNode class */

SLNode::SLNode(int inputData)
{
    nextNode = NULL;
    setData(inputData);
}
void SLNode::setData(int d)
{
    data = d;
}
int SLNode::peek()
{
    return data;
}
void SLNode::setNextNode(SLNode *next)
{
    nextNode = next;
}
SLNode* SLNode::getNextNode()
{
    return nextNode;
}

/* Stack class */

Stack::Stack()
{
    top = NULL;
    stackCheck = true;
}

Stack::~Stack()
{
    SLNode* curr = top;
    
    while(curr!= NULL)
    {
        SLNode* next = curr->getNextNode();
        delete curr;
        curr = next;
    }
}

void Stack::setTop(SLNode* t)
{
    top = t;
}

SLNode* Stack::getTop()
{
    return top;
}

void Stack::push(int data)
{
    stackCheck = false;
    SLNode* newNode = new SLNode(data);
    
    if(top == NULL)
    {
        top = newNode;
        newNode->setNextNode(NULL);
    }
    else
    {
        //make the "next" attribute of "newNode" equal to top
        newNode->setNextNode(top);
        top = newNode;
    }
}

void Stack::pop()
{
    int tempData = top->peek(); // store the data for the top
    cout << tempData << " was removed from the stack." << endl;
    SLNode* temp = top; // make a temp object to hold the top
    top = top->getNextNode(); // top equals 2nd item in list
    delete temp; // delete the previous top
}

bool Stack::isEmpty()
{
    if(top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }

}