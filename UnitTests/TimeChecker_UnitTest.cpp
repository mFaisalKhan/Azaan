#include <TimeChecker.h>
#include <QTime>
#include "TimerMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <gmock/gmock-generated-actions.h>

using namespace testing;
using ::testing::_;
using ::testing::DoAll;
using ::testing::SetArgReferee;

///////////////////////////////////////////////////////////
TEST(WhenConstrutorIsCalled, ThenObjectShouldBeCreated)
{
    testing::NiceMock<TimerMock> mockTimer;
    TimeChecker timeChecker(mockTimer);

    (void)timeChecker;

    EXPECT_TRUE(1);
}

///////////////////////////////////////////////////////////
TEST(WhenTimeExtactlyMatches, ThenIsTimeToPlayReturnsTrue)
{
    testing::NiceMock<TimerMock> mockTimer;
    TimeChecker timeChecker(mockTimer);

    QTime ExpectedTime;

    ExpectedTime.setHMS(12,15,0,0);

    timeChecker.AddTime(ExpectedTime);
    EXPECT_CALL(mockTimer, GetCurrentTime(_,_,_,_))
            .WillOnce(DoAll(SetArgReferee<0>(12), SetArgReferee<1>(15), SetArgReferee<2>(0), SetArgReferee<3>(0)));

    EXPECT_TRUE(timeChecker.IsTimeToPlay());
}

///////////////////////////////////////////////////////////
TEST(WhenTimeIsWithinOver5minutes, ThenIsTimeToPlayReturnsTrue)
{
    testing::NiceMock<TimerMock> mockTimer;
    TimeChecker timeChecker(mockTimer);

    TimeFields ExpectedTime;

    ExpectedTime.Hour = 12;
    ExpectedTime.Min = 15;
    ExpectedTime.Sec = 0;
    ExpectedTime.MSec = 0;

    timeChecker.AddTime(ExpectedTime);
    EXPECT_CALL(mockTimer, GetCurrentTime(_,_,_,_))
            .WillOnce(DoAll(SetArgReferee<0>(12), SetArgReferee<1>(16), SetArgReferee<2>(0), SetArgReferee<3>(0)));

    EXPECT_TRUE(timeChecker.IsTimeToPlay());
}

///////////////////////////////////////////////////////////
TEST(WhenHourIsSameButMinuteIsLess, ThenIsTimeToPlayReturnsFalse)
{
    testing::NiceMock<TimerMock> mockTimer;
    TimeChecker timeChecker(mockTimer);

    TimeFields ExpectedTime;

    ExpectedTime.Hour = 12;
    ExpectedTime.Min = 15;
    ExpectedTime.Sec = 0;
    ExpectedTime.MSec = 0;

    timeChecker.AddTime(ExpectedTime);
    EXPECT_CALL(mockTimer, GetCurrentTime(_,_,_,_))
            .WillOnce(DoAll(SetArgReferee<0>(12), SetArgReferee<1>(14), SetArgReferee<2>(0), SetArgReferee<3>(0)));

    EXPECT_FALSE(timeChecker.IsTimeToPlay());
}

///////////////////////////////////////////////////////////
TEST(WhenHourIsSameButMinuteIsMoreThen5, ThenIsTimeToPlayReturnsFalse)
{
    testing::NiceMock<TimerMock> mockTimer;
    TimeChecker timeChecker(mockTimer);

    TimeFields ExpectedTime;

    ExpectedTime.Hour = 12;
    ExpectedTime.Min = 15;
    ExpectedTime.Sec = 0;
    ExpectedTime.MSec = 0;

    timeChecker.AddTime(ExpectedTime);
    EXPECT_CALL(mockTimer, GetCurrentTime(_,_,_,_))
            .WillOnce(DoAll(SetArgReferee<0>(12), SetArgReferee<1>(21), SetArgReferee<2>(0), SetArgReferee<3>(0)));

    EXPECT_FALSE(timeChecker.IsTimeToPlay());
}

///////////////////////////////////////////////////////////
TEST(WhenHourIsNotSameButMinuteIsSame, ThenIsTimeToPlayReturnsFalse)
{
    testing::NiceMock<TimerMock> mockTimer;
    TimeChecker timeChecker(mockTimer);

    TimeFields ExpectedTime;

    ExpectedTime.Hour = 12;
    ExpectedTime.Min = 15;
    ExpectedTime.Sec = 0;
    ExpectedTime.MSec = 0;

    timeChecker.AddTime(ExpectedTime);
    EXPECT_CALL(mockTimer, GetCurrentTime(_,_,_,_))
            .WillOnce(DoAll(SetArgReferee<0>(13), SetArgReferee<1>(15), SetArgReferee<2>(0), SetArgReferee<3>(0)));

    EXPECT_FALSE(timeChecker.IsTimeToPlay());
}
