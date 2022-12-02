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
    easyGUI-application-s STATIC
    ./src/Application.cpp
    ./src/Routine.cpp
    ./src/Menu.cpp
)

add_library(
    easyGUI-application SHARED
    ./src/Application.cpp
    ./src/Routine.cpp
    ./src/Menu.cpp
)

# ----- Defining includes -----

target_include_directories(
    easyGUI-application-s PUBLIC

    inc
    ../Assets/inc
    ../Logger/inc
)

target_include_directories(
    easyGUI-application PUBLIC

    inc
    ../Assets/inc
    ../Logger/inc
)

# ----- Generating export headers -----

if(WIN32)
    GENERATE_EXPORT_HEADER(easyGUI-application
        BASE_NAME easyGUI-application
        EXPORT_MACRO_NAME APPLICATION_EXPORTS
        EXPORT_FILE_NAME ${CMAKE_CURRENT_DIR}/inc/application_export.hpp
        STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC
    )
endif()

# ----- Linking dependencies -----

target_link_libraries(
    easyGUI-application-s
    easyGUI-assets-s
    easyGUI-exceptions-s
    sfml-graphics
    sfml-window
    sfml-system
)

target_link_libraries(
    easyGUI-application
    easyGUI-assets
    easyGUI-exceptions
    sfml-graphics
    sfml-window
    sfml-system
)

# ----- Installing library -----

install( TARGETS easyGUI-application-s DESTINATION ${PROJECT_LIBRARY_DIR} )
install( TARGETS easyGUI-application DESTINATION ${PROJECT_RUNTIME_DIR} )
install( DIRECTORY inc/ DESTINATION ${PROJECT_INCLUDE_DIR}/ )