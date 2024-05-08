cmake_minimum_required(VERSION 3.27)
project(projekt)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 10.2.1
)

FetchContent_MakeAvailable(fmt)

add_executable(projekt main.cpp
        Database.cpp
        Database.h
        Table.cpp
        Table.h
        Column.cpp
        Column.h
)
target_link_libraries(projekt fmt)

