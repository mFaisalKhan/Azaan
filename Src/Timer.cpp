#include "Timer.h"
#include <ctime>

using namespace std;

//////////////////////////////////////////////
Timer::Timer()
{

}

//////////////////////////////////////////////
Timer::~Timer()
{

}

//////////////////////////////////////////////
void Timer::GetCurrentTime(int&h, int&m, int&s, int& mSec)
{
    time_t timeStruct;

    timeStruct = time(NULL);

    tm* localTime = localtime(&timeStruct);

    h = localTime->tm_hour;
    m = localTime->tm_min;
    s = localTime->tm_sec;
    mSec =0;

}
