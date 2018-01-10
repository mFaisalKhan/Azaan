#include <Runner.h>
#include "TimerMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

///////////////////////////////////////////////////////////
TEST(WhenRunnerConstructorIsCalled, ThenObjectIsCreated)
{
  testing::NiceMock<TimerMock> mockTimer;
  Runner runner(mockTimer);

  (void) runner;
  EXPECT_TRUE( 1);
}


