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


# ----- Configuring SFML -----

find_package(SFML REQUIRED system window graphics)

# ----- Adding sources -----

add_subdirectory(Assets)
add_subdirectory(Application)

if(${BUILD_SHARED_LIBRARIES})
    install( EXPORT easyGUI FILE easyGUI.cmake DESTINATION ${PROJECT_LIBRARY_DIR}/cmake/easyGUI )
else()
    install( EXPORT easyGUI-static FILE easyGUI-static.cmake DESTINATION ${PROJECT_LIBRARY_DIR}/cmake/easyGUI )
endif()