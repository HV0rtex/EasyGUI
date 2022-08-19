// Copyright © 2022 David Bogdan

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files 
// (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, 
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do 
// so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


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
    easyGUI::utils::Point obj;

    obj.Xcoord = 2;
    obj.Ycoord = -1;

    ASSERT_EQ(obj.Xcoord, 2);
    ASSERT_EQ(obj.Ycoord, -1);

    // Copy construction
    easyGUI::utils::Point obj2(obj);

    ASSERT_EQ(obj2.Xcoord, 2);
    ASSERT_EQ(obj2.Ycoord, -1);

    obj2.Xcoord = 0;

    ASSERT_EQ(obj2.Xcoord, 0);
    ASSERT_NE(obj.Xcoord, 0);

    // Assignment
    obj = obj2;

    ASSERT_EQ(obj.Xcoord, 0);
}