#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

struct TimeFields
{
    int Hour;
    int Min;
    int Sec;
    int MSec;

    bool IsTimeEqual(int h, int m, int s, int mSec)
    {
        if( Hour == h &&
            Min == m &&
            Sec == s &&
            MSec == mSec)
        {
            return true;
        }

        return false;
    }

};

class TimerInterface
{
public:
    TimerInterface(){}
    virtual ~TimerInterface(){};

    virtual void GetCurrentTime(int &hour, int &minute, int &sec, int &mSec) = 0;
    virtual void GetCurrentDate(int& year, int& month, int& day) = 0;

};


#endif
