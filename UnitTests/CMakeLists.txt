project(UnitTests)
cmake_minimum_required(VERSION 2.8)

# include directory
INCLUDE_DIRECTORIES(/home/faisal/Projects/Azaan/Src)

# This project type and files
add_executable(UnitTests Runner_UnitTest.cpp TimeChecker_UnitTest.cpp Timer_UnitTest.cpp TimerMock.h main.cpp)

#link library path
LINK_DIRECTORIES(/usr/local/lib)

#libraries to link with
target_link_libraries(UnitTests gtest gmock pthread AzaanLib)
