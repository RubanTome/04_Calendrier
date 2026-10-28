cmake_minimum_required(VERSION 4.3)
project(04_Calendrier)

set(CMAKE_CXX_STANDARD 20)

add_executable(04_Calendrier main.cpp
        Calendar.h
        Calendar.cpp
        User.cpp
        User.h)
