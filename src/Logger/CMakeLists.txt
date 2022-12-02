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
    easyGUI-exceptions-s STATIC

    src/AssetException.cpp
    src/ApplicationException.cpp
)

add_library(
    easyGUI-exceptions SHARED

    src/AssetException.cpp
    src/ApplicationException.cpp
)

# ----- Generating export headers -----

if(WIN32)
    GENERATE_EXPORT_HEADER(easyGUI-exceptions
        BASE_NAME easyGUI-exceptions
        EXPORT_MACRO_NAME EXCEPTION_EXPORTS
        EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/inc/exceptions_export.hpp
        STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC
    )
endif()


# ----- Defining includes -----

target_include_directories(
    easyGUI-exceptions-s PUBLIC

    inc
)

target_include_directories(
    easyGUI-exceptions PUBLIC

    inc
)

# ----- Installing library -----

install( TARGETS easyGUI-exceptions-s DESTINATION ${PROJECT_LIBRARY_DIR} )
install( TARGETS easyGUI-exceptions DESTINATION ${PROJECT_RUNTIME_DIR} )
install( DIRECTORY inc/ DESTINATION ${PROJECT_INCLUDE_DIR}/ )