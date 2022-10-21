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

void Label::constructText(const Point& position, const ::std::string& text, const unsigned& charSize)
{
    _text.setPosition(position.Xcoord, position.Ycoord);
    _text.setFont(*_font.get());
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

void Label::updateLocation(const Point& newLocation)
{
    _text.setPosition(newLocation.Xcoord, newLocation.Ycoord);
}

Label::Label(const Point& startLocation, const ::std::string& text, const ::std::string& fontPath, const unsigned& charSize)
{
    try
    {
        FontManager* manager = nullptr;
        manager = manager->getInstance();

        if(manager == nullptr)
        {
            throw LabelException("Could not get hold of Font Manager.");
        }

        _font = manager->getAsset(fontPath);

        _textColor = ::sf::Color::White;

        constructText(startLocation, text, charSize);
    }
    catch(const FontException& err)
    {
        ERROR << err.what();

        throw LabelException("Could not get font from Font Manager. Cannot create Label.");
    }
}

::sf::Text& Label::getInternalText()
{
    return _text;
}

}