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

# ----- Creating demo project -----

add_executable(
    demo

    # Main
    demo.cpp
    
    # Menus
    menus/mainMenu.cpp
    menus/secondMenu.cpp

    # Routines
    routines/windowHandler.cpp

    # Buttons
    menus/buttons/backButton.cpp
    menus/buttons/demoButton.cpp
    menus/buttons/exitButton.cpp
)

target_include_directories(
    demo
    
    PUBLIC
    ../src/Application/inc/
    ../src/Assets/inc/
    ./
)

target_link_libraries(
    demo
    easyGUI-application
    easyGUI-assets
)

# ----- Installing project -----

install( TARGETS demo DESTINATION ${PROJECT_RUNTIME_DIR}/demo )
install( DIRECTORY ./res/ DESTINATION ${PROJECT_RUNTIME_DIR}/demo/res )