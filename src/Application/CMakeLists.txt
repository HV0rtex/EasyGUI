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
    application STATIC
    ./src/Application.cpp
)

add_library(
    application-shared SHARED
    ./src/Application.cpp
)

# ----- Defining includes -----

target_include_directories(
    application PUBLIC

    ./inc
    ../Assets/inc
)

target_include_directories(
    application-shared PUBLIC

    ./inc
    ../Assets/inc
)

# ----- Linking dependencies -----

target_link_libraries(
    application
    sfml-graphics
    sfml-window
    sfml-system
)

target_link_libraries(
    application-shared
    sfml-graphics
    sfml-window
    sfml-system
)

# ----- Installing library -----

install( TARGETS application DESTINATION ${PROJECT_LIBRARY_DIR} )
install( TARGETS application-shared DESTINATION ${PROJECT_RUNTIME_DIR} )
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/inc/ DESTINATION ${PROJECT_INCLUDE_DIR} )