#include <iostream>
#include <Runner.h>
#include <Timer.h>

using namespace std;



/*  Design
  Make it as a multi process application
  1st process will run a loop and check if it is time to play. and plays it.
  2nd process goes to the internet to update the data base.
  3rd process will check the live stream.

  === Data is shared using shared database
  == Signals are sent using DBus or pipes whichever is easy
  == Use locks to address synchronization issues
  == Coding will be in C++ 14

 */

int main()
{
    cout << "Staring Azaan main()" << endl;


    Timer timer;
    Runner runner(timer);

    runner.Run();
    return 0;
}



