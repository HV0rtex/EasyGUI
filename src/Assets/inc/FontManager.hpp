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
 * @file FontManager.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the FontManager wrapper class
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <SFML/Graphics/Font.hpp>
#include <stdexcept>
#include <utility>
#include <map>

namespace easyGUI
{

/**
 * @brief Wrapper around ::sf::Font class
 * 
 * @details The purpose of this wrapper is to optimize the space usage by
 * creating the same font only once and providing shared access to it
 * via pointers. 
 */
class FontManager
{
private:
    static FontManager* instance;
    
    ::std::map < const ::sf::Font*, ::std::string > reverseFontMap;
    ::std::map < ::std::string, ::sf::Font* > fontMap;
    ::std::map < ::std::string, unsigned > occurances;

    /**
     * @brief Constructor
     * 
     * Private constructor in order to adhere to the singleton design pattern.
     */
    FontManager() {}
public:
    /**
     * @brief Destructor
     * 
     */
    ~FontManager();
 
    /**
     * @brief Returns the manager instance
     * 
     * @return FontManager* 
     */
    FontManager* getInstance();

    /**
     * @brief Returns the font
     * 
     * @param fontPath The path to the font
     * 
     * @return ::sf::Font* 
     * @retval NULL invalid font path
     */
    ::sf::Font* getFont(const ::std::string& fontPath);

    /**
     * @brief Updates the occurances of the font
     * 
     * @details If the occurances hits 0, then that font is removed
     * from memory, as there are no labels using it.
     * 
     * @param usedFont The font of the destructed label
     */
    void updateMaps(const ::sf::Font* usedFont);
};

}