///
/***********************************************
 * Queue.h
 * Created by Matthew D Mayberry on 5/28/15
 * CS162_400_S2015_Lab9
 ***********************************************/
///

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <queue>
#include <vector>
#include <string>

using namespace std;



/*   Queue class  */


class Queue
{
    
private:
    queue <int> myQueue; // STL queue container
    vector <unsigned long> sizeTracker; // tracks the sizes from each round
    int averageLength;
    
public:
    void buffer(int insert, int remove);
    int generateNum();
};

#endif