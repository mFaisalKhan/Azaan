#include <gtest/gtest.h>
#include <Runner.h>

///////////////////////////////////////////////////////////
TEST(WhenRunnerConstructorIsCalled, ThenObjectIsCreated)
{
  Runner runner;

  (void) runner;
  EXPECT_TRUE( 1);
}


