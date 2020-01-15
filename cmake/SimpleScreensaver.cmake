#############################################################################
# Name:      SimpleScreensaver.cmake
# Purpose:   SimpleScreensaver
# Author:    Alexander Sherstnev
# Created:   2018-01-29
# Copyright: (c) 2018 Alexander Sherstnev
# Licence:   MIT
#############################################################################

include_directories(include/SimpleScreensaver)

list(APPEND Headers
    include/SimpleScreensaver/BoxEntity.h
    include/SimpleScreensaver/Application.h
)

list(APPEND Sources
    src/SimpleScreensaver/BoxEntity.cpp
    src/SimpleScreensaver/Application.cpp
)