cmake_minimum_required(VERSION 3.10)
project(sllist_test)


set(SOURCES
    sllist_test.cpp
    sllist.cpp
)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g")


add_executable(sllist_test ${SOURCES})