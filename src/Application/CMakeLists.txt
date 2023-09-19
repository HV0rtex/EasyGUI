# Copyright © 2022 David Bogdan

# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files 
# (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, 
# publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do 
# so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
# FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


cmake_minimum_required(VERSION 3.11...3.22)

# ----- Defining library sets -----

set(APPLICATION_SOURCES
    src/Application.cpp
    src/Routine.cpp
    src/Menu.cpp
)

set(APPLICATION_HEADERS
    inc/Application.hpp
    inc/Menu.hpp
    inc/Routine.hpp
    inc/Exceptions/ApplicationException.hpp
    inc/Exceptions/MenuException.hpp
)

build_library(
    TARGET "easyGUI-application"
    VERSION "3.0.0"
    MACRO_NAME "EASYGUI_APPLICATION"
    SOURCES "${APPLICATION_SOURCES}"
    HEADERS "${APPLICATION_HEADERS}"
    DEPENDENCIES "sfml-graphics;sfml-window;sfml-system"
)

if(${BUILD_SHARED_LIBRARIES})
    target_link_libraries(
        easyGUI-application
    PRIVATE
        easyGUI-assets
    )
else()
    target_link_libraries(
        easyGUI-application-s
    PRIVATE
        easyGUI-assets-s
    )
endif()