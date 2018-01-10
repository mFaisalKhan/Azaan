#include <gtest/gtest.h>
#include <Timer.h>

///////////////////////////////////////////////////////////
TEST(WhenTimerConstructorIsCalled, ThenObjectIsConstructed)
{
    Timer timerObj;

    (void) timerObj;

    EXPECT_TRUE(1);
}


///////////////////////////////////////////////////////////
TEST(WhenGetCurrentTimeIsCalled, ThenReturnTheCorrectTime)
{
   Timer timerObj;
   time_t timeStruct;

   timeStruct = time(NULL);
   tm* localTime = localtime(&timeStruct);

   int hh,mm,ss,ms;

   timerObj.GetCurrentTime(hh,mm,ss,ms);

   EXPECT_EQ(localTime->tm_hour, hh);
   EXPECT_EQ(localTime->tm_min, mm);
   EXPECT_EQ(localTime->tm_sec, ss);
   EXPECT_EQ(0, ms);
   std::cout << " Current time in unit test is "<<hh<<":"<<mm<<":"<<ss<<":"<<ms<<std::endl;
}

///////////////////////////////////////////////////////////
TEST(WhenGetCurrentDateIsCalled, ThenReturnTheCorrectDate)
{
   Timer timerObj;
   time_t timeStruct;

   timeStruct = time(NULL);
   tm* localTime = localtime(&timeStruct);

   int year,month,day;

   timerObj.GetCurrentDate(year,month,day);

   EXPECT_EQ(localTime->tm_year+1900, year);
   EXPECT_EQ(localTime->tm_mon+1, month);
   EXPECT_EQ(localTime->tm_mday, day);

   std::cout << " Current Date in unit test is "<<month+1<<"/"<<day<<"/"<<year+1900<<std::endl;
}
