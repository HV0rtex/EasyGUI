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
 * @file T_FontManager_UT.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Unit tests for the font manager class
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <FontManager.hpp>
#include <gtest/gtest.h>


TEST(FontManagerUT, SimpleInitTest)
{
    ::easyGUI::FontManager* inst = nullptr;

    ASSERT_NO_THROW(inst = inst->getInstance());
    ASSERT_NE(inst, nullptr);
}

TEST(FontManagerUT, GetFontWorks)
{
    ::easyGUI::FontManager* inst = nullptr;

    const ::sf::Font* ptr = nullptr;
    const ::sf::Font* ptr2 = nullptr;

    ASSERT_NO_THROW(inst = inst->getInstance());
    ASSERT_NE(inst, nullptr);

    ptr = inst->getFont("./res/Arial.ttf");
    ptr2 = inst->getFont("./res/Arial.ttf");


    ASSERT_NE(ptr, nullptr);
    ASSERT_EQ(ptr, ptr2);

    ASSERT_EQ(inst->getFont("/font/font/Path"), nullptr);
    ASSERT_NO_THROW(inst->removeFont(ptr));
}
