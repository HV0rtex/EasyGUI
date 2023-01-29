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
 * @file CheckBox.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the check box class
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <CheckBox.hpp>

namespace easyGUI
{

void CheckBox::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_box, states);

    if(_isChecked)
        target.draw(_filler, states);
}

CheckBox::CheckBox(const Point& startLocation, const Point& endLocation)
{
    _box.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _box.setSize(::sf::Vector2f(endLocation.Xcoord - startLocation.Xcoord, endLocation.Ycoord - startLocation.Ycoord));
    _box.setOutlineColor(::sf::Color::White);
    _box.setOutlineThickness(2);

    _filler.setPosition(startLocation.Xcoord + 5, startLocation.Ycoord + 5);
    _filler.setSize(::sf::Vector2f(endLocation.Xcoord - startLocation.Xcoord + 5, endLocation.Ycoord - startLocation.Ycoord + 5));
    _filler.setFillColor(::sf::Color::White);
}

CheckBox::CheckBox(
    const Point& startLocation, 
    const float& width, const float& height):
    
    CheckBox(startLocation, startLocation + Point(width, height))
{
}

bool CheckBox::isMouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);
        ::sf::Vector2f worldPos = _container->mapPixelToCoords(currentPosition);

        if(_box.getGlobalBounds().contains(worldPos.x, worldPos.y))
            return true;
    }

    return false;
}

void CheckBox::updateLocation(const Point& newLocation)
{
    _box.setPosition(newLocation.Xcoord, newLocation.Ycoord);
    _filler.setPosition(newLocation.Xcoord + 5, newLocation.Ycoord + 5);

    AlignmentTool& tool = AlignmentTool::getInstance();
    tool.triggerUpdate(this);
}

void CheckBox::onClick()
{
    if(isMouseHover())
    {
        _isChecked = 1 - _isChecked;
    }
}

bool CheckBox::isChecked() const
{
    return _isChecked;
}

::sf::RectangleShape& CheckBox::getInternalBox()
{
    return _box;
}

::sf::RectangleShape& CheckBox::getFiller()
{
    return _filler;
}

Point CheckBox::getLEFT() const
{
    return Point(_box.getGlobalBounds().left - 1, _box.getGlobalBounds().top - 7 + _box.getGlobalBounds().height / 2);
}

Point CheckBox::getRIGHT() const
{
    return Point(_box.getGlobalBounds().left - 1 + _box.getGlobalBounds().width, _box.getGlobalBounds().top - 7 + _box.getGlobalBounds().height / 2);
}

Point CheckBox::getTOP() const
{
    return Point(_box.getGlobalBounds().left - 1 + _box.getGlobalBounds().width / 2, _box.getGlobalBounds().top - 7);
}

Point CheckBox::getBOTTOM() const
{
    return Point(_box.getGlobalBounds().left - 1 + _box.getGlobalBounds().width / 2, _box.getGlobalBounds().top - 7+ _box.getGlobalBounds().height);
}

Point CheckBox::getCENTER() const
{
    return Point(_box.getGlobalBounds().left - 1 + _box.getGlobalBounds().width / 2, _box.getGlobalBounds().top - 7 + _box.getGlobalBounds().height / 2);
}

}