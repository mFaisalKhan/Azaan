#ifndef TIMER_MOCK_H
#define TIMER_MOCK_H

#include <TimerInterface.h>
#include <gmock/gmock.h>


class TimerMock: public TimerInterface
{
public:
    MOCK_METHOD4(GetCurrentTime, void(int&, int&, int&, int&));
};

#endif
