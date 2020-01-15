#############################################################################
# Name:      CMakeLists.txt
# Purpose:   Primary CMake for 3rd-party libraries
# Author:    Alexander Sherstnev
# Created:   2018-01-29
# Copyright: (c) 2018 Alexander Sherstnev
# Licence:   MIT
#############################################################################

# wxWidget
set(wxBUILD_SHARED OFF)
set(wxBUILD_PRECOMP OFF)
add_subdirectory(3rdparty/wxWidgets)
