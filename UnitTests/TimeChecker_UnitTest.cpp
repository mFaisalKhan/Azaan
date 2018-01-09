#include <TimeChecker.h>
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
TEST(WhenTimeIsCorrect, ThenIsTimeToPlayReturnsTrue)
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
            .WillOnce(DoAll(SetArgReferee<0>(12), SetArgReferee<1>(15), SetArgReferee<2>(0), SetArgReferee<3>(0)));

    EXPECT_TRUE(timeChecker.IsTimeToPlay());

}
