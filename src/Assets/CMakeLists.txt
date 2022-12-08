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

set(LIBRARY_SOURCES
    src/Point.cpp
    src/AlignmentTool.cpp
    src/Label.cpp
    src/Button.cpp
    src/Component.cpp
    src/TextBox.cpp
    src/PasswordBox.cpp
    src/Image.cpp
    src/CheckBox.cpp
    src/Converter.cpp
)

# ----- Defining library sets -----

if(${BUILD_SHARED_LIBRARIES})
    add_library(
        easyGUI-assets SHARED

        ${LIBRARY_SOURCES}
    )
else()
    add_library(
        easyGUI-assets-s STATIC

        ${LIBRARY_SOURCES}
    )
endif()

# ----- Defining includes -----

if(${BUILD_SHARED_LIBRARIES})
    target_include_directories(
        easyGUI-assets PUBLIC

        inc
        ../Logger/inc
    )
else()
    target_include_directories(
        easyGUI-assets-s PUBLIC

        inc
        ../Logger/inc
    )
endif()

# ----- Linking dependencies -----

if(${BUILD_SHARED_LIBRARIES})
    target_link_libraries(
        easyGUI-assets
        easyGUI-exceptions
        sfml-graphics 
        sfml-window
        sfml-system
    )

    if(WIN32)
        GENERATE_EXPORT_HEADER(easyGUI-assets)
    endif()
else()
    target_link_libraries(
        easyGUI-assets-s
        easyGUI-exceptions-s
        sfml-graphics
        sfml-window 
        sfml-system
    )
endif()

# ----- Installing library -----

if(${BUILD_SHARED_LIBRARIES})
    install( TARGETS easyGUI-assets 
        RUNTIME DESTINATION ${PROJECT_RUNTIME_DIR} 
        ARCHIVE DESTINATION ${PROJECT_LIBRARY_DIR}
    )
else()
    install( TARGETS easyGUI-assets-s DESTINATION ${PROJECT_LIBRARY_DIR} )
endif()

install( DIRECTORY inc/ DESTINATION ${PROJECT_INCLUDE_DIR}/ )