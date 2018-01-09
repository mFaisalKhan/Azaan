#ifndef TIMER_H
#define TIMER_H

#include "TimerInterface.h"

class Timer: public TimerInterface
{
 public:
    Timer();
    virtual ~Timer();

    void GetCurrentTime(int &, int&, int&, int&);

};


#endif
