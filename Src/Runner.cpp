#include "Runner.h"
#include <iostream>
#include <unistd.h>

///////////////////////////////////////////////////////////
Runner::Runner(TimerInterface &timer)
    : Checker(timer)
{

    TimeFields time;

    time.Hour = 6;
    time.Min = 0;
    time.Sec = 0;
    Checker.AddTime(time);

    time.Hour = 1+12;
    time.Min = 0;
    time.Sec = 0;
    Checker.AddTime(time);

    time.Hour = 3+12;
    time.Min = 0;
    time.Sec = 0;
    Checker.AddTime(time);

    time.Hour = 6+12;
    time.Min = 0;
    time.Sec = 0;
    Checker.AddTime(time);

    time.Hour = 9+12;
    time.Min = 03;
    time.Sec = 0;
    Checker.AddTime(time);

}

///////////////////////////////////////////////////////////
Runner::~Runner()
{

}

///////////////////////////////////////////////////////////
void Runner::Run()
{
    while(1)
    {
        if(Checker.IsTimeToPlay())
        {
            std::cout << "Time to play!" << std::endl;
        }
        sleep(10);
    }
}

