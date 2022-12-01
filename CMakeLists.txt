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


cmake_minimum_required(VERSION 3.10)

# ----- Project config -----

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(
    EasyGUI
    VERSION 0.0.0.1
    DESCRIPTION "An extension for the SFML library that deals with GUI creation."
)

set(PROJECT_RUNTIME_DIR ${PROJECT_SOURCE_DIR}/bin)
set(PROJECT_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/lib)
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include/EasyGUI)

# ----- Build config -----

if(UNIX)
	add_compile_options(
		-pedantic
		-O3
		-Wall
		-Wextra
		-Wcast-align
		-Wcast-qual
		-Wdisabled-optimization
		-Wformat=2
		-Winit-self
		-Wmissing-declarations
		-Wmissing-include-dirs
		-Wold-style-cast
		-Woverloaded-virtual
		-Wredundant-decls
		-Wshadow
		-Wsign-conversion
		-Wsign-promo
		-Wstrict-overflow=5
		-Wswitch-default
		-Wundef
		-Werror
		-Wno-unused
	)
endif()

if(WIN32)
	add_compile_options(
		-O2
		-Oi
		-GL
		-Wall
		-WX
	)
endif()

# ----- Building sources -----

add_subdirectory(src)
add_subdirectory(example)
