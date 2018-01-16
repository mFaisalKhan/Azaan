project(AzaanLib)
cmake_minimum_required(VERSION 2.8.12)

add_definitions(-fPIC)

#set(CMAKE_PREFIX_PATH "Qt5Core")
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_AUTOMOC ON)

include_directories(/usr/include/x86_64-linux-gnu/qt5/)
include_directories(/usr/include/x86_64-linux-gnu/qt5/QtCore)

find_package(Qt5Core REQUIRED)

#project type and source files
add_library(${PROJECT_NAME} Runner.cpp TimeChecker.cpp TimerInterface.h Timer.cpp TimeLoader.cpp)

target_link_libraries(${PROJECT_NAME} Qt5Core)
