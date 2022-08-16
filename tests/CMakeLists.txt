
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