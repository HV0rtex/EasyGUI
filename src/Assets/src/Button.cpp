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
 * @file Button.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the button class
 * @version 0.1
 * @date 2022-09-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Button.hpp>

namespace easyGUI
{

Button::~Button()
{
    if(_content != nullptr)
    {
        delete _content;
    }
}

unsigned Button::getCharSizeCorrection(const unsigned& length, const unsigned& charSize) const
{
    float lenghtInPix = length * charSize / 1.9;
    float heightInPix = charSize * 1.55;

    float freeSpaceX = _shape.getSize().x - lenghtInPix;
    float freeSpaceY = _shape.getSize().y - heightInPix;

    unsigned correction = 0;

    while(freeSpaceX <= 0 || freeSpaceY <= 0)
    {
        correction++;

        lenghtInPix = length * (charSize - correction) / 1.9;
        heightInPix = (charSize - correction) * 1.5;

        freeSpaceX = _shape.getSize().x - lenghtInPix;
        freeSpaceY = _shape.getSize().y - heightInPix;
    }

    return correction;
}

Point Button::getLabelPosition(const unsigned& length, const unsigned& charSize) const
{
    float lenghtInPix = length * charSize / 1.9;
    float heightInPix = charSize * 1.55;

    float freeSpaceX = _shape.getSize().x - lenghtInPix;
    float freeSpaceY = _shape.getSize().y - heightInPix;

    return Point(_shape.getPosition().x + freeSpaceX / 2, _shape.getPosition().y + freeSpaceY / 2);
}

Button::Button(
    const Point& startLocation,
    const Point& endLocation,

    const ::sf::Color& fillColor,
    const ::sf::Color& outlineColor,
    const ::sf::Color& textColor,

    const ::std::string& text,
    const ::std::string& fontPath,

    const unsigned& charSize,
    const unsigned& thickness)
{
    _shape.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _shape.setFillColor(fillColor);
    _shape.setOutlineColor(outlineColor);
    _shape.setOutlineThickness(thickness);
    _shape.setSize(::sf::Vector2f(endLocation.Xcoord - startLocation.Xcoord, endLocation.Ycoord - startLocation.Ycoord));

    unsigned correction = getCharSizeCorrection(text.size(), charSize);

    _content = new Label(getLabelPosition(text.size(), charSize - correction), text, fontPath, charSize - correction, textColor);
}

Button::Button(
    const Point& startLocation,
    const unsigned& width,
    const unsigned& height,

    const ::sf::Color& fillColor,
    const ::sf::Color& outlineColor,
    const ::sf::Color& textColor,

    const ::std::string& text,
    const ::std::string& fontPath,

    const unsigned& charSize,
    const unsigned& thickness)
{
    _shape.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _shape.setFillColor(fillColor);
    _shape.setOutlineColor(outlineColor);
    _shape.setOutlineThickness(thickness);
    _shape.setSize(::sf::Vector2f(width, height));

    unsigned correction = getCharSizeCorrection(text.size(), charSize);

    _content = new Label(getLabelPosition(text.size(), charSize - correction), text, fontPath, charSize - correction, textColor);
}

void Button::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_shape);

    if(_content != nullptr)
    {
        target.draw(*_content);
    }
}

bool Button::isMouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);

        if(_shape.getGlobalBounds().contains(currentPosition.x, currentPosition.y))
            return true;
    }

    return false;
}

}