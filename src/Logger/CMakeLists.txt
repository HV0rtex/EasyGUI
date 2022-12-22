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

if(${BUILD_SHARED_LIBRARIES})
    add_library(
        easyGUI-exceptions SHARED

        src/AssetException.cpp
        src/ApplicationException.cpp
    )
else()
    add_library(
        easyGUI-exceptions-s STATIC

        src/AssetException.cpp
        src/ApplicationException.cpp
    )
endif()

# ----- Defining includes -----

if(${BUILD_SHARED_LIBRARIES})
    target_include_directories(
        easyGUI-exceptions PUBLIC

        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:lib/easyGUI>
    )
    if(WIN32)
        GENERATE_EXPORT_HEADER(
            easyGUI-exceptions
            EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/inc/exceptions-export.hpp
            EXPORT_MACRO_NAME EXCEPTIONS_EXPORTS
        )
    endif()
else()
    target_include_directories(
        easyGUI-exceptions-s PUBLIC

        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:lib/easyGUI>
    )
endif()

# ----- Installing library -----

if(${BUILD_SHARED_LIBRARIES})
    install( TARGETS easyGUI-exceptions
        EXPORT easyGUI
        RUNTIME DESTINATION ${PROJECT_RUNTIME_DIR}
        LIBRARY DESTINATION ${PROJECT_RUNTIME_DIR} 
        ARCHIVE DESTINATION ${PROJECT_LIBRARY_DIR}
    )
else()
    install( TARGETS easyGUI-exceptions-s 
        EXPORT easyGUI-static
        DESTINATION ${PROJECT_LIBRARY_DIR}
    )
endif()

install( DIRECTORY inc/ DESTINATION ${PROJECT_INCLUDE_DIR}/ )