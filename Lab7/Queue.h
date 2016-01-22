///
/***********************************************
 * Queue.h
 * Created by Matthew D Mayberry on 5/22/15
 * CS162_400_S2015_Assignment4
 ***********************************************/
///

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue; // forward declaration
class DLNode; // forward declaration

class DLNode
{
private:
    int data;
    DLNode* nextNode;
    DLNode* prevNode;
    
public:
    DLNode(int inputData);
    void setData(int d);
    int getData();
    void setNextNode(DLNode* next);
    DLNode* getNextNode();
    void setPrevNode(DLNode* prev);
    DLNode* getPrevNode();
};


class Queue
{
    
private:
    DLNode* front;
    DLNode* back;
    
    
public:
    Queue();
    ~Queue();
    void setFront(DLNode* f);
    DLNode* getFront();
    void setBack(DLNode* b);
    DLNode* getBack();
    void add(int data);
    int remove();
    
};

#endif