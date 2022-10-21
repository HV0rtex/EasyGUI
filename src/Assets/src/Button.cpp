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

void Button::updateLocation(const Point& newLocation)
{
    _shape.setPosition(newLocation.Xcoord, newLocation.Ycoord);
    _content->updateLocation(getLabelPosition(_content->getInternalText().getString().getSize(), _content->getInternalText().getCharacterSize()));
}

Button::Button(
    const Point& startLocation,
    const Point& endLocation,

    const ::std::string& text,
    const ::std::string& fontPath,

    const unsigned& charSize)
{
    _shape.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _shape.setFillColor(::sf::Color::Black);
    _shape.setOutlineColor(::sf::Color::White);
    _shape.setOutlineThickness(5);
    _shape.setSize(::sf::Vector2f(endLocation.Xcoord - startLocation.Xcoord, endLocation.Ycoord - startLocation.Ycoord));
    
    unsigned correction = getCharSizeCorrection(text.size(), charSize);

    if(correction != 0)
    {
        WARN << "Button text doesn't fit. Resizing text...\n";
    }

    try
    {
        _content = new Label(getLabelPosition(text.size(), charSize - correction), text, fontPath, charSize - correction);
    } 
    catch (const LabelException& err)
    {
        ERROR << err.what();

        ButtonException ex("Label text will not be visible.");
        _content = nullptr;

        WARN << ex.what();
    }
}

Button::Button(
    const Point& startLocation,
    const float& width,
    const float& height,

    const ::std::string& text,
    const ::std::string& fontPath,

    const unsigned& charSize) : 
Button(
    startLocation, 
    Point(startLocation.Xcoord + width, startLocation.Ycoord + height),
    text,
    fontPath,
    charSize
) {}

void Button::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_shape, states);

    if(_content != nullptr)
    {
        target.draw(*_content, states);
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

::sf::RectangleShape& Button::getInternalButton()
{
    return _shape;
}

Label* Button::getInternalText()
{
    return _content;
}

}