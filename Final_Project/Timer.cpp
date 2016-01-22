///
/***********************************************
 * Timer.cpp
 * Created by Matthew D Mayberry on 6/3/15
 * CS162_400_S2015_FinalProject_MarsOne
 ***********************************************/
///

#include "Timer.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
using namespace std;


Timer::Timer()
{
    begTime = 0;
}

void Timer::start()
{
    begTime = time(0);
}

double Timer::getTimeLeft(double seconds)
{
    double seconds_since_start = difftime( time(0), begTime);
    return seconds - seconds_since_start;
}

