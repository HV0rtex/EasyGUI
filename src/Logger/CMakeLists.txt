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

set(LIBRARY_HEADERS
    inc/Logger.hpp
    inc/Exceptions/ApplicationException.hpp
    inc/Exceptions/AssetException.hpp
    inc/Exceptions/ButtonException.hpp
    inc/Exceptions/CheckBoxException.hpp
    inc/Exceptions/ImageException.hpp
    inc/Exceptions/LabelException.hpp
    inc/Exceptions/ManagerException.hpp
    inc/Exceptions/MenuException.hpp
    inc/Exceptions/TextBoxException.hpp
)

if(WIN32)
    set(LIBRARY_HEADERS
        ${LIBRARY_HEADERS}
        inc/exceptions_export.hpp
    )
endif()


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

    ${LIBRARY_HEADERS}
)

# ----- Defining includes -----

target_include_directories(
    easyGUI-exceptions-s PUBLIC

    inc
)

target_include_directories(
    easyGUI-exceptions PUBLIC

    inc
)
# ----- Generating export headers -----

if(WIN32)
    GENERATE_EXPORT_HEADER(easyGUI-exceptions
        BASE_NAME easyGUI-exceptions
        EXPORT_MACRO_NAME EXCEPTION_EXPORTS
        EXPORT_FILE_NAME ${CMAKE_CURRENT_DIR}/inc/exception_export.hpp
        STATIC_DEFINE SHARED_EXPORTS_BUILT_AS_STATIC
    )
endif()

# ----- Installing library -----

install( TARGETS easyGUI-exceptions-s DESTINATION ${PROJECT_LIBRARY_DIR} )
install( TARGETS easyGUI-exceptions DESTINATION ${PROJECT_RUNTIME_DIR} )
install( DIRECTORY inc/ DESTINATION ${PROJECT_INCLUDE_DIR}/ )