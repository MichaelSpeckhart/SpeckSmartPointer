cmake_minimum_required(VERSION 3.20)
project(speck_pointer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug, Release, etc)" FORCE)
endif()

add_subdirectory(src)

