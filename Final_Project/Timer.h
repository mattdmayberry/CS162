///
/***********************************************
 * Timer.h
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#ifndef TIMER_H
#define TIMER_H

#include <stdio.h>
#include <iostream>
#include <time.h>


class Timer
{
private:
    time_t begTime;
public:
    Timer();
    void start();
    double getTimeLeft(double seconds);
};

#endif
