#ifndef TIMECHECKER_H
#define TIMECHECKER_H

#include "TimerInterface.h"
#include <vector>

class TimeChecker
{
public:
    TimeChecker(TimerInterface & timer);
    ~TimeChecker();

    bool IsTimeToPlay();
    void AddTime(QTime &newTime);

private:
    TimerInterface& ThisTime;
    std::vector<QTime> TimeList;
};

#endif // TIMECHECKER_H
