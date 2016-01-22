///
/***********************************************
 * Queue.cpp
 * Created by Matthew D Mayberry on 5/28/15
 * CS162_400_S2015_Lab9
 ***********************************************/
///

#include "Queue.h"
#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>


/*  Queue class  */

void Queue::buffer(int insert, int remove)
{
    
    
    if(insert != 0)
    {
        int insert1in = 100 / insert; // divide 100 by the percentage to determine the 1 out of x value for insert
        int insertCheck = (rand() % insert1in + 1); // generate random number between 1 and insert1in
        if(insertCheck == insert1in) // if insertCheck is 1 add number to queue
        {
            int num = generateNum();
            myQueue.push(num);
        }
    }
    
    if(remove != 0)
    {
        int remove1in = 100 / remove; // divide 100 by the percentage to determine the 1 out of x value for remove
        int removeCheck = (rand() % remove1in + 1); // generate random number between 1 and remove1in
        if(removeCheck == remove1in) // if removeCheck is 1 add number to queue
        {
            if(myQueue.size() != 0)
            {
                myQueue.pop();
            }
        }
    }
    
    
    int currentSize = myQueue.size(); // current size of myQueue
    sizeTracker.push_back(currentSize); // push size into sizeTracker vector
    
    int queueSize = 0;
    int roundCounter = 0;
    
    // Calculate the sum the sizeTracker vector
    for(int i = 0; i < sizeTracker.size(); i++)
    {
        queueSize = queueSize + sizeTracker[i];
        roundCounter++;
    }
    
    // Calculate average queue size by divding the sum of the sizeTracker by the round counter
    int averageLength = queueSize / roundCounter;
    
    cout << "The current size of the queue is " << currentSize << " elements." << endl;
    cout << "The average length of the queue for all rounds is " << averageLength << endl;
    
}


int Queue::generateNum()
{
    int randomInt = rand() % 100;
    return randomInt;
}

