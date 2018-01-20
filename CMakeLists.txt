project(Azaan)
cmake_minimum_required(VERSION 2.8.12)

add_definitions(-fPIC)

set(QT5_ROOT_DIR "/usr/include/x86_64-linux-gnu/qt5")

#add all files in this folder
aux_source_directory(. SRC_LIST)

#add subdirectories
add_subdirectory(./UnitTests)
add_subdirectory(./Src)

#include directory
include_directories(./Src)
include_directories(${QT5_ROOT_DIR})
include_directories(${QT5_ROOT_DIR}/QtCore)

#This project type and source files
add_executable(${PROJECT_NAME} ${SRC_LIST})

#libraries to link with
target_link_libraries(${PROJECT_NAME} AzaanLib)

