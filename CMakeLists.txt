project(Azaan)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

set( SOURCE
    $(SOURCE_DIR)/Runner.cpp
    $(SOURCE_DIR)/TimeChecker.cpp
)

set( HEADER
    $(SOURCE_DIR)/Runner.h
    $(SOURCE_DIR)/TimeChecker.h
)

