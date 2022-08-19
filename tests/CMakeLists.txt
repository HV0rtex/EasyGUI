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


# ----- Configuring GTest -----

set(CMAKE_CXX_FLAGS -pthread)

find_package(GTest REQUIRED)

# ----- Configuring macro for unit tests -----

macro(setup_unit_test)
    set(multi_valued_args TEST_SOURCES TEST_INCLUDES TEST_LIBS)

    cmake_parse_arguments(UT "" "TEST_NAME" "${multi_valued_args}" ${ARGN})

    message( STATUS "Creating Unit Test...")
    message( STATUS "TEST_NAME: ${UT_TEST_NAME}")
    message( STATUS "TEST_SOURCES: ${UT_TEST_SOURCES}")

    add_executable(${UT_TEST_NAME} ${UT_TEST_SOURCES})

    target_include_directories(${UT_TEST_NAME} PRIVATE ${GTEST_INCLUDE_DIRS} ${UT_TEST_INCLUDES})
    target_link_libraries(${UT_TEST_NAME} ${GTEST_BOTH_LIBRARIES} ${UT_TEST_LIBS})

    install(TARGETS ${UT_TEST_NAME} DESTINATION ${PROJECT_RUNTIME_DIR}/tests)
endmacro()

# ----- Adding unit tests to be built -----

add_subdirectory(Label)
add_subdirectory(FontManager)

# ----- Installing resources -----

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/res DESTINATION ${PROJECT_RUNTIME_DIR}/tests)