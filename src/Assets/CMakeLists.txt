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
    assets STATIC

    ${CMAKE_CURRENT_SOURCE_DIR}/src/Label.cpp
)

add_library(
    assets-shared SHARED

    ${CMAKE_CURRENT_SOURCE_DIR}/src/Label.cpp
)

# ----- Defining includes -----

target_include_directories(
    assets PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_include_directories(
    assets-shared PUBLIC

    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

# ----- Linking dependencies -----

target_link_libraries(
    assets
    sfml-graphics
    sfml-window
    sfml-system
)

target_link_libraries(
    assets-shared
    sfml-graphics
    sfml-window
    sfml-system
)

# ----- Installing library -----

install( TARGETS assets DESTINATION ${PROJECT_LIBRARY_DIR} )
install( TARGETS assets-shared DESTINATION ${PROJECT_RUNTIME_DIR} )
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/inc/ DESTINATION ${PROJECT_INCLUDE_DIR} )