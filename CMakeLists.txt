project(Azaan)
cmake_minimum_required(VERSION 2.8)

#add all files in this folder
aux_source_directory(. SRC_LIST)

#add subdirectories
add_subdirectory(./UnitTests)
add_subdirectory(./Src)

#INCLUDE_DIRECTORIES(/home/faisal/Projects/Azaan/Src)

#This project type and source files
add_executable(${PROJECT_NAME} ${SRC_LIST})

