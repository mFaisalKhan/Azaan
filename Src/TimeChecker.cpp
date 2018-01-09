#include "TimeChecker.h"


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
bool TimeChecker::IsTimeToPlay()
{

    for(int i=0; i<TimeList.size(); i++)
    {
        int hour = 0;
        int min = 0;
        int sec = 0;
        int mSec = 0;

        ThisTime.GetCurrentTime(hour, min, sec, mSec);

        if(TimeList[i].IsEqual(hour,min,sec,mSec))
        {
            return true;
        }
    }

  return false;
}

///////////////////////////////////////////////////////////
void TimeChecker::AddTime(TimeFields &newTime)
{
    TimeList.push_back(newTime);
}
