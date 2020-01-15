#############################################################################
# Name:      3rdparty.cmake
# Purpose:   Primary CMake for SimpleScreensaver
# Author:    Alexander Sherstnev
# Created:   2018-01-29
# Copyright: (c) 2018 Alexander Sherstnev
# Licence:   MIT
#############################################################################

cmake_minimum_required(VERSION 3.10)

set(PROJECT_VERSION 1.0.0)
set(PROJECT_NAME SimpleScreensaver)
set(CMAKE_CXX_STANDARD 11)

project(${PROJECT_NAME} CXX)

set(Headers)
set(Sources)
set(UseWX ON)

if (UseWX)
    add_definitions(-DUSE_WX)
endif()

include(cmake/3rdparty.cmake)
include(cmake/Engine.cmake)
include(cmake/SimpleScreensaver.cmake)

add_executable(${PROJECT_NAME} ${Sources} ${Headers})
target_link_libraries(${PROJECT_NAME} core base)
