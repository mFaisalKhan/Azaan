#ifndef RUNNER_H
#define RUNNER_H

#include "TimerInterface.h"
#include "TimeChecker.h"

class Runner
{
 public:
   Runner(TimerInterface &);
   ~Runner();
   void Run();

 private:
   TimeChecker Checker;
};

#endif // RUNNER_H
