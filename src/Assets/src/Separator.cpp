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
 * @file Separator.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Separator class
 *
 * @copyright Copyright (c) 2022
 */

#include <Separator.hpp>

namespace easyGUI
{

Separator::Separator(
    const Point& startLocation,
    const bool& vertical,
    
    const float& size,
    const uint32_t thickness)
{
    _shape.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _shape.setFillColor(::sf::Color::Black);
    _shape.setOutlineColor(::sf::Color::White);
    _shape.setOutlineThickness(thickness);

    if(vertical) 
    {
        _shape.setSize(::sf::Vector2f(1, size));
    }
    else 
    {
        _shape.setSize(::sf::Vector2f(size, 1));
    }
}


void Separator::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_shape, states);
}

bool Separator::isMouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);
        ::sf::Vector2f worldPos = _container->mapPixelToCoords(currentPosition);

        if(_shape.getGlobalBounds().contains(worldPos.x, worldPos.y))
            return true;
    }

    return false;
}

::sf::RectangleShape& Separator::getInternalSeparator()
{
    return _shape;
}

void Separator::updateLocation(const Point& newLocation)
{
    _shape.setPosition(newLocation.Xcoord, newLocation.Ycoord);

    AlignmentTool& tool = AlignmentTool::getInstance();
    tool.triggerUpdate(this);
}

Point Separator::getLEFT() const
{
    return Point(_shape.getGlobalBounds().left, _shape.getGlobalBounds().top + _shape.getGlobalBounds().height / 2);
}

Point Separator::getRIGHT() const
{
    return Point(_shape.getGlobalBounds().left + _shape.getGlobalBounds().width, _shape.getGlobalBounds().top + _shape.getGlobalBounds().height / 2);
}

Point Separator::getTOP() const
{
    return Point(_shape.getGlobalBounds().left + _shape.getGlobalBounds().width / 2, _shape.getGlobalBounds().top);
}

Point Separator::getBOTTOM() const
{
    return Point(_shape.getGlobalBounds().left + _shape.getGlobalBounds().width / 2, _shape.getGlobalBounds().top + _shape.getGlobalBounds().height);
}

Point Separator::getCENTER() const
{
    return Point(_shape.getGlobalBounds().left + _shape.getGlobalBounds().width / 2, _shape.getGlobalBounds().top + _shape.getGlobalBounds().height / 2);
}

}