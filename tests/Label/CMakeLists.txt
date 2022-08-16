
setup_unit_test(
    TEST_NAME Label-UT
    TEST_SOURCES main.cpp T_Label_UT.cpp T_Point_UT.cpp
    TEST_INCLUDES ${PROJECT_SOURCE_DIR}/src/Assets/Label/inc
    TEST_LIBS assets
)