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
 * @file FontManager.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the FontManager class
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <FontManager.hpp>

namespace easyGUI
{

FontManager* FontManager::instance = 0;

FontManager* FontManager::getInstance()
{
    if(instance == nullptr)
    {
        instance = new FontManager();
    }

    return instance;
}

::std::shared_ptr<::sf::Font> FontManager::getFont(const ::std::string& fontPath)
{
    if(storedFonts.find(fontPath) != storedFonts.end())
    {
        return storedFonts[fontPath];
    }

    ::std::shared_ptr<::sf::Font> font = ::std::make_shared<::sf::Font>();
}


FontManager::~FontManager()
{

}

}