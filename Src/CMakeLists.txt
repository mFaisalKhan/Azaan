project(AzaanLib)
cmake_minimum_required(VERSION 2.8.12)

add_definitions(-fPIC)

include_directories(${QT5_ROOT_DIR})
include_directories(${QT5_ROOT_DIR}/QtCore)

find_package(Qt5Core REQUIRED)
find_package(Qt5Sql REQUIRED)

#project type and source files
add_library(${PROJECT_NAME} Runner.cpp TimeChecker.cpp TimerInterface.h Timer.cpp TimeLoader.cpp)

target_link_libraries(${PROJECT_NAME} Qt5Core Qt5Sql)
