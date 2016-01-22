///
/***********************************************
 * Queue.h
 * Created by Matthew D Mayberry on 5/22/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack; // forward declaration
class SLNode; // forward declaration

class SLNode
{
private:
    int data;
    SLNode* nextNode;
    
public:
    SLNode(int inputData);
    void setData(int d);
    int getData();
    void setNextNode(SLNode *next);
    SLNode* getNextNode();
};


class Stack
{
    
private:
    SLNode* top;
    
    
public:
    Stack();
    ~Stack();
    void setTop(SLNode* t);
    SLNode* getTop();
    void add(int data);
    int remove();
    
};

#endif