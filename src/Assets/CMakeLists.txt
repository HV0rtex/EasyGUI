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


cmake_minimum_required(VERSION 3.10...3.22)

# ----- Defining library sets -----

set(ASSETS_SOURCES
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
    src/Separator.cpp
)

set(ASSETS_HEADERS
    inc/AlignmentTool.hpp
    inc/Button.hpp
    inc/CheckBox.hpp
    inc/Component.hpp
    inc/Converter.hpp
    inc/Image.hpp
    inc/Label.hpp
    inc/Manager.hpp
    inc/PasswordBox.hpp
    inc/TextBox.hpp
    inc/Point.hpp
    inc/Separator.hpp
    inc/Task.hpp
    inc/Exceptions/AssetException.hpp
    inc/Exceptions/LabelException.hpp
    inc/Exceptions/ButtonException.hpp
    inc/Exceptions/CheckBoxException.hpp
    inc/Exceptions/ImageException.hpp
    inc/Exceptions/ManagerException.hpp
    inc/Exceptions/TextBoxException.hpp
)

build_library(
    TARGET "easyGUI-assets"
    VERSION "3.0.0"
    MACRO_NAME "EASYGUI_EXPORTS"
    SOURCES "${ASSETS_SOURCES}"
    HEADERS "${ASSETS_HEADERS}"
    DEPENDENCIES "sfml-graphics;sfml-window;sfml-system"
)