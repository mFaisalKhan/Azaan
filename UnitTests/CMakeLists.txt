project(UnitTests)
cmake_minimum_required(VERSION 2.8)

# include directory
include_directories(/home/faisal/Projects/Azaan/Src)
include_directories(${QT5_ROOT_DIR})
include_directories(${QT5_ROOT_DIR}/QtCore)

find_package(Qt5Core REQUIRED)
find_package(Qt5Sql REQUIRED)

# This project type and files
add_executable(UnitTests Runner_UnitTest.cpp TimeChecker_UnitTest.cpp Timer_UnitTest.cpp TimeLoader_UnitTest.cpp TimerMock.h main.cpp)

#link library path
LINK_DIRECTORIES(/usr/local/lib)

#libraries to link with
target_link_libraries(UnitTests gtest gmock pthread AzaanLib Qt5Core Qt5Sql)
