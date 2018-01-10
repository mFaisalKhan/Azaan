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

//////////////////////////////////////////////
void Timer::GetCurrentDate(int& year, int& month, int& day)
{
    time_t timeStruct;

    timeStruct = time(NULL);

    tm* localTime = localtime(&timeStruct);

    year = localTime->tm_year+1900;
    month = localTime->tm_mon+1;
    day = localTime->tm_mday;


}
