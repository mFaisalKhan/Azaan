#include "Runner.h"
#include <iostream>
#include <unistd.h>

///////////////////////////////////////////////////////////
Runner::Runner(TimerInterface &timer)
    : Checker(timer)
{

    QTime time(6,0,0);

    Checker.AddTime(time);

    time.setHMS(1+12,0,0);
    Checker.AddTime(time);

    time.setHMS(3+12,0,0);
    Checker.AddTime(time);

    time.setHMS(6+12,0,0);
    Checker.AddTime(time);

    time.setHMS(9+12,3,0);
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

