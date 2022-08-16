/**
 * @file T_Point_UT.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Unit tests for the Point structure
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>
#include <Point.hpp>

TEST(PointUnitTest, SimpleInitTest) 
{
    // Normal initialization
    egui::utils::Point obj;

    obj.Xcoord = 2;
    obj.Ycoord = -1;

    ASSERT_EQ(obj.Xcoord, 2);
    ASSERT_EQ(obj.Ycoord, -1);

    // Copy construction
    egui::utils::Point obj2(obj);

    ASSERT_EQ(obj2.Xcoord, 2);
    ASSERT_EQ(obj2.Ycoord, -1);

    obj2.Xcoord = 0;

    ASSERT_EQ(obj2.Xcoord, 0);
    ASSERT_NE(obj.Xcoord, 0);

    // Assignment
    obj = obj2;

    ASSERT_EQ(obj.Xcoord, 0);
}