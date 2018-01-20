#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include <QTime>
//#include "/usr/include/x86_64-linux-gnu/qt5/QtCore/QTime"

struct Prayers
{
   QTime Fajr;
   QTime Zuhur;
   QTime Asar;
   QTime Maghrib;
   QTime Isha;
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
