cmake_minimum_required(VERSION 3.23)
project(advanced_ex_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(advanced_ex_4
        Distance.cpp
        Distance.h
        server.cpp
        File.h
        File.cpp
        MaxHeap.cpp
        MaxHeap.h Setting.cpp Setting.h Command.cpp)
