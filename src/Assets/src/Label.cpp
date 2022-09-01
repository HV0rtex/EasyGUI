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
 * @file Label.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Label class
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Label.hpp>

namespace easyGUI
{

void Label::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_text, states);
}

void Label::constructText(const utils::Point& position, const ::std::string& text, const unsigned& charSize)
{
    _text.setPosition(position.Xcoord, position.Ycoord);
    _text.setFont(*_font);
    _text.setFillColor(_textColor);
    _text.setCharacterSize(charSize);
    _text.setString(text);
}

bool Label::isMouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);

        if(_text.getGlobalBounds().contains(currentPosition.x, currentPosition.y))
            return true;
    }

    return false;
}

Label::~Label() 
{
    utils::FontManager* manager = nullptr;
    manager = manager->getInstance();

    manager->updateMaps(_text.getFont());
}

Label::Label(const utils::Point& position, const ::std::string& text, const ::std::string& fontPath, const unsigned& charSize, const sf::Color& color)
{
    utils::FontManager* manager = nullptr;
    manager = manager->getInstance();

    if(manager->getFont(fontPath) == nullptr)
    {
        throw ::std::invalid_argument("Invalid font path!");
    }

    _font = manager->getFont(fontPath);
    _textColor = color;

    constructText(position, text, charSize);
}

}