#include "TimeChecker.h"
#include <iostream>

///////////////////////////////////////////////////////////
TimeChecker::TimeChecker(TimerInterface &timer)
    : ThisTime(timer)
    , TimeList()
{

}

///////////////////////////////////////////////////////////
TimeChecker::~TimeChecker()
{

}

///////////////////////////////////////////////////////////
/// \brief TimeChecker::IsTimeToPlay
/// \return
/// When to play
/// Hour should be same
/// minute should be equal or within +5
/// no more than 5 minutes delayed
/// seconds dont care
/// mSec dont care
///
bool TimeChecker::IsTimeToPlay()
{

    for(int i=0; i<TimeList.size(); i++)
    {
        int hour = 0;
        int min = 0;
        int sec = 0;
        int mSec = 0;

        ThisTime.GetCurrentTime(hour, min, sec, mSec);
        std::cout << "Time: "<< hour <<":"<<min<<":"<<sec ;
         std::cout << "\tMatching With: "<< TimeList[i].hour() <<":"<< TimeList[i].minute()<<":"<< TimeList[i].second() << std::endl;

        if(hour == TimeList[i].hour() &&
           (min >= TimeList[i].minute() && min <= TimeList[i].minute() +5))
        {
            return true;
        }
    }

  return false;
}

///////////////////////////////////////////////////////////
void TimeChecker::AddTime(QTime &newTime)
{
    TimeList.push_back(newTime);
}
