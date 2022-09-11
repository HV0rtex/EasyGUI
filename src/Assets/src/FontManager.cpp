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

::sf::Font* FontManager::getFont(const ::std::string& fontPath)
{
    if(instance->fontMap.find(fontPath) != instance->fontMap.end())
    {
        instance->occurances[fontPath]++;

        return instance->fontMap[fontPath];
    }

    instance->fontMap[fontPath] = new ::sf::Font();
    
    if(!instance->fontMap[fontPath]->loadFromFile(fontPath))
    {
        instance->fontMap.erase(fontPath);

        return nullptr;
    }

    instance->occurances[fontPath] = 1;
    instance->reverseFontMap[instance->fontMap[fontPath]] = fontPath;

    return instance->fontMap[fontPath];
}

void FontManager::updateMaps(const ::sf::Font* usedFont)
{
    if(usedFont == nullptr)
    {
        throw ::std::invalid_argument("Invalid font being removed!");
    }

    ::std::string fontKey = instance->reverseFontMap[usedFont];

    if( --instance->occurances[fontKey] <= 0 )
    {
        instance->fontMap.erase(fontKey);
        instance->reverseFontMap.erase(usedFont);
        instance->occurances.erase(fontKey);
    }
}

FontManager::~FontManager()
{
    for(auto element : instance->reverseFontMap)
    {
        if(element.first != nullptr)
        {
            delete element.first;
        }
    }
}

}