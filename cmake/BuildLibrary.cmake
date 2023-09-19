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

function(BUILD_LIBRARY)
	cmake_parse_arguments(
		LIBRARY_OPTIONS
		""
		"TARGET;MACRO_NAME;VERSION"
		"SOURCES;HEADERS;DEPENDENCIES;INCLUDES"
		${ARGN}
	)

	set(EXPORT_MACRO "")
	set(EXPORT_FILE "")
	set(FILE_VERSION "${LIBRARY_OPTIONS_VERSION}")
	set(EXPORT_TARGET "EasyGUIStaticLibraries")

	if(${BUILD_SHARED_LIBRARIES})
		set(EXPORT_TARGET "EasyGUISharedLibraries")

		add_library(${LIBRARY_OPTIONS_TARGET} SHARED ${LIBRARY_OPTIONS_SOURCES} ${LIBRARY_OPTIONS_HEADERS})

		if(WIN32)
			generate_export_header(
				${LIBRARY_OPTIONS_TARGET}
				EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/inc/${LIBRARY_OPTIONS_TARGET}-export.hpp
				EXPORT_MACRO_NAME ${LIBRARY_OPTIONS_MACRO_NAME}
			)

			set(EXPORT_MACRO "${LIBRARY_OPTIONS_MACRO_NAME} ")
			set(EXPORT_FILE "#include <${LIBRARY_OPTIONS_TARGET}-export.hpp>")

			install(
				FILES ${CMAKE_CURRENT_SOURCE_DIR}/inc/${LIBRARY_OPTIONS_TARGET}-export.hpp
				DESTINATION ${PROJECT_SOURCE_DIR}/include
			)
    	endif()
	else()
		set(LIBRARY_OPTIONS_TARGET "${LIBRARY_OPTIONS_TARGET}-s")

		add_library(${LIBRARY_OPTIONS_TARGET} STATIC ${LIBRARY_OPTIONS_SOURCES} ${LIBRARY_OPTIONS_HEADERS})
	endif()

	add_library(EasyGUI::${LIBRARY_OPTIONS_TARGET} ALIAS ${LIBRARY_OPTIONS_TARGET})

	set(HEADER_LIST "${LIBRARY_OPTIONS_HEADERS}")
    foreach(FILE ${HEADER_LIST})
		message(STATUS "Configuring file ${FILE}")
        configure_file("${FILE}.in" "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}")
		configure_file("${FILE}.in" "${PROJECT_SOURCE_DIR}/include/${FILE}")
    endforeach()

	target_include_directories(
		${LIBRARY_OPTIONS_TARGET}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
		$<INSTALL_INTERFACE:${PROJECT_INCLUDE_DIRECTORY}>
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
		$<BUILD_INTERFACE:${LIBRARY_OPTIONS_INCLUDES}>
	)

	foreach(DEPENDENCY ${LIBRARY_OPTIONS_DEPENDENCIES})
		target_link_libraries(
			${LIBRARY_OPTIONS_TARGET}
        PRIVATE
			${DEPENDENCY}
		)
	endforeach()

	if(UNIX)
		if(NOT ${BUILD_RELEASE})
			target_compile_options(
				${LIBRARY_OPTIONS_TARGET}
			PRIVATE
				-Wpedantic
				-O0
				-Wall
				-Wextra
				-Werror
				-Wconversion
				-Wcast-align
				-Wunused
				-Wshadow
				-Wold-style-cast
				-Wpointer-arith
				-Wcast-qual
				-Wno-missing-braces
			)
		else()
			target_compile_options(
				${LIBRARY_OPTIONS_TARGET}
			PRIVATE
				-Ofast
				-funroll-loops
			)
		endif()
	else()
		if(NOT ${BUILD_RELEASE})
			target_compile_options(
				${LIBRARY_OPTIONS_TARGET}
			PRIVATE
				-analyze
				-fastfail
				-fp:except
				-sdl
				-W4
				-WX
				-Zc:enumTypes
				-Zc:externC
				-Zc:forScope
				-permissive
				-Zc:inline
				-Zc:noexceptTypes
				-Zc:templateScope
				-Zc:ternary
				-Zc:threadSafeInit
				-Zc:throwingNew
			)
		else()
			target_compile_options(
				${LIBRARY_OPTIONS_TARGET}
			PRIVATE
				-Oi
				-O2
				-GA
				-GL
				-Gw
				-Qfast_transcendentals
				-sdl
			)
		endif()

	endif()

	install(
		TARGETS ${LIBRARY_OPTIONS_TARGET}

		EXPORT ${EXPORT_TARGET}

		LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
		ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib
		RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
	)
endfunction()
