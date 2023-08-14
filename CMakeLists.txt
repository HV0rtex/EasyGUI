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

if(${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# ----- Options -----

option(BUILD_SHARED_LIBRARIES "Dentoes if to build SHARED or STATIC libraries" OFF)

# ----- Project config -----

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

project(
    EasyGUI
    VERSION 3.0.0
    DESCRIPTION "An extension for the SFML library that deals with GUI creation."
	LANGUAGES CXX
)

if(WIN32 AND ${BUILD_SHARED_LIBRARIES})
	include(GenerateExportHeader)
	set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE) 
endif()

include(BuildLibrary)
include(CMakePackageConfigHelpers)

# ----- Building sources -----

add_subdirectory(src)

# ----- Out-of-Source build enforcement -----

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS ${LOC_PATH})
	message(FATAL_ERROR "You cannot build in a source directory. Please make a build directory and try building from there.")
endif()

# ----- Exporting -----

write_basic_package_version_file(
	EasyGUIConfigVersion.cmake
	VERSION 3.0.0
	COMPATIBILITY SameMajorVersion
)

if (${BUILD_SHARED_LIBRARIES})
	install(
		EXPORT EasyGUISharedLibraries
		FILE EasyGUISharedLibraries.cmake
		NAMESPACE EasyGUI::
		DESTINATION ${PROJECT_SOURCE_DIR}/lib/cmake/EasyGUI
	)
else()
	install(
		EXPORT EasyGUIStaticLibraries
		FILE EasyGUIStaticLibraries.cmake
		NAMESPACE EasyGUI::
		DESTINATION ${PROJECT_SOURCE_DIR}/lib/cmake/EasyGUI
	)
endif()

install(
	FILES "${PROJECT_SOURCE_DIR}/cmake/EasyGUIConfig.cmake"
		  "${PROJECT_BINARY_DIR}/EasyGUIConfigVersion.cmake"
	DESTINATION ${PROJECT_SOURCE_DIR}/lib/cmake/EasyGUI
)