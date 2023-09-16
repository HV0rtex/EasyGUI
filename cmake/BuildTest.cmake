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


cmake_minimum_required(VERSION 3.11...3.22)

function(add_test)
    cmake_parse_arguments(
        TEST_OPTIONS
        ""
        "TARGET"
        "SOURCES;HEADERS;DEPENDENCIES"
        ${ARGN}
    )

    add_executable(${TEST_OPTIONS_TARGET} ${TEST_OPTIONS_SOURCES} ${TEST_OPTIONS_HEADERS})

	foreach(DEPENDENCY ${TEST_OPTIONS_DEPENDENCIES})
		target_link_libraries(
			${TEST_OPTIONS_TARGET}
        PRIVATE
			${DEPENDENCY}
		)
	endforeach()

    target_link_libraries(
        ${TEST_OPTIONS_TARGET}
    PRIVATE
        gmock
        gtest
        gtest-main
    )

    gtest_discover_tests(
        ${TEST_OPTIONS_TARGET}
        WORKING_DIRECTORY   ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
    )

    set_target_properties(
        ${TEST_OPTIONS_TARGET}
    PROPERTIES
        FOLDER test
    )
endfunction()