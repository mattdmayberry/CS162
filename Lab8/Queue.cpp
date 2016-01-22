///
/***********************************************
 * Queue.cpp
 * Created by Matthew D Mayberry on 5/22/15
 * CS162_400_S2015_Lab8
 ***********************************************/
///

#include "Queue.h"
using namespace std;

/* DLNode*/

DLNode::DLNode(int inputData)
{
    nextNode = NULL;
    prevNode = NULL;
    setData(inputData);
}

void DLNode::setData(int d)
{
    data = d;
}

int DLNode::getData()
{
    return data;
}

void DLNode::setNextNode(DLNode* next)
{
    nextNode = next;
}

DLNode* DLNode::getNextNode()
{
    return nextNode;
}

void DLNode::setPrevNode(DLNode* prev)
{
    prevNode = prev;
}

DLNode* DLNode::getPrevNode()
{
    return prevNode;
}


/* Queue */

Queue::Queue()
{
    front = NULL;
    back = NULL;
}
Queue::~Queue()
{
    DLNode* curr = front;
    
    while(curr!= NULL)
    {
        DLNode* next = curr->getNextNode();
        delete curr;
        curr = next;
    }
}
void Queue::setFront(DLNode* f)
{
    front = f;
}
DLNode* Queue::getFront()
{
    return front;
}
void Queue::setBack(DLNode* b)
{
    back = b;
}
DLNode* Queue::getBack()
{
    return back;
}
void Queue::addBack(int data)
{
    queueCheck = false;
    DLNode* newNode = new DLNode(data);
    if(front == NULL)
    {
        newNode->setNextNode(NULL);
        newNode->setPrevNode(NULL);
        front = newNode;
        back = newNode;
    }
    else
    {
        newNode->setNextNode(back);
        newNode->setPrevNode(NULL);
        back->setPrevNode(newNode);
        back = newNode;
    }
}

void Queue::removeFront()
{
    int tempData;
    
    if(front == NULL)
    {
        cout << "The Queue is already empty." << endl;
    }
    else
    {
        tempData = front->getData();
        DLNode* temp = front;
        
        
        if(temp->getPrevNode() == NULL && temp->getNextNode() == NULL)
        {
            back = NULL;
        }
        
        front = front->getPrevNode();
        //check front is not null first
        if(front != NULL)
        {
            front->setNextNode(NULL);
        }
        
        delete temp; // delete the previous
        cout << tempData << " has been removed from the queue." << endl;
    }
}

bool Queue::isEmpty()
{
    if(front == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}