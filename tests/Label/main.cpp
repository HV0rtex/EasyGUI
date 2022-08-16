/**
 * @file main.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Entry point to the Label unit tests
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>


GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}