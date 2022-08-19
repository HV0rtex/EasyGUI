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
 * @file T_Label_UT.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Unit tests for the label class
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <gtest/gtest.h>
#include <Label.hpp>

TEST(LabelUnitTest, SimpleInitTest)
{
    ::easyGUI::utils::Point pos;
    ::easyGUI::Label* testObj; 

    pos.Xcoord = 0;
    pos.Ycoord = 0;

    // Good case
    ASSERT_NO_THROW(testObj = new ::easyGUI::Label(pos, "Example", "./res/Arial.ttf", 15, ::sf::Color(0,0,0)));
}

TEST(LabelUnitTest, InitFailsInvalidFont)
{
    ::easyGUI::utils::Point pos;
    ::easyGUI::Label* testObj; 

    pos.Xcoord = 0;
    pos.Ycoord = 0;

    try
    {
        testObj = new ::easyGUI::Label(pos, "Example", "some/random/path", 10, ::sf::Color(10,10,10));
    
        FAIL();
    }
    catch(const ::std::invalid_argument& e)
    {
        ASSERT_STREQ(e.what(), "Invalid font path!");
    }
    catch(...)
    {
        FAIL();
    }

}