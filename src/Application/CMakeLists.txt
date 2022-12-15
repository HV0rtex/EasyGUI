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


# ----- Defining library sets -----

add_library(
    EasyGUI-application-s STATIC
    ./src/Application.cpp
    ./src/Routine.cpp
    ./src/Menu.cpp
)

if(NOT WIN32)
    add_library(
        EasyGUI-application SHARED
        ./src/Application.cpp
        ./src/Routine.cpp
        ./src/Menu.cpp
    )
endif()

# ----- Defining includes -----

target_include_directories(
    EasyGUI-application-s PUBLIC

    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:lib/EasyGUI>
)

if(NOT WIN32)
    target_include_directories(
        EasyGUI-application PUBLIC

        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:lib/EasyGUI>
    )
endif()

# ----- Linking dependencies -----

target_link_libraries(
    EasyGUI-application-s
    EasyGUI-assets-s
    EasyGUI-exceptions-s
    sfml-graphics
    sfml-window
    sfml-system
)
if(NOT WIN32)
    target_link_libraries(
        EasyGUI-application
        EasyGUI-assets
        EasyGUI-exceptions
        sfml-graphics
        sfml-window
        sfml-system
    )
endif()

# ----- Installing library -----

install( TARGETS EasyGUI-application-s DESTINATION ${PROJECT_LIBRARY_DIR} EXPORT EasyGUI)

if(NOT WIN32)
    install( TARGETS EasyGUI-application DESTINATION ${PROJECT_RUNTIME_DIR} EXPORT EasyGUI)
endif()

install( DIRECTORY inc/ DESTINATION ${PROJECT_INCLUDE_DIR}/ )