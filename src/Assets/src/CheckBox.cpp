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
 * @brief Implementation of the CheckBox class
 * @version 0.1
 * @date 2022-10-19
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

    if(_component != nullptr)
        target.draw(*_component, states);
}

CheckBox::CheckBox(const Point& startLocation, const Allignment& allignment, Component*& content)
{
    _box.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _box.setFillColor(::sf::Color::Black);
    _box.setOutlineColor(::sf::Color::White);
    _box.setOutlineThickness(5);
    _box.setSize(::sf::Vector2f(10, 10));

    _component = content;

    switch(allignment)
    {
        case Allignment::BOTTOM:
            content->updateLocation(Point(startLocation.Xcoord, startLocation.Ycoord + 20));
            break;
        
        case Allignment::TOP:
            content->updateLocation(Point(startLocation.Xcoord, startLocation.Ycoord - 20));
            break;

        case Allignment::LEFT:
            content->updateLocation(Point(startLocation.Xcoord - 20, startLocation.Ycoord));
            break;

        case Allignment::RIGHT:
            content->updateLocation(Point(startLocation.Xcoord + 20, startLocation.Ycoord));
            break;

        default:
            break;
    }
}

bool CheckBox::isMouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);

        if(_box.getGlobalBounds().contains(currentPosition.x, currentPosition.y))
            return true;
    }

    return false;  
}

void CheckBox::onClick()
{
    if(isMouseHover())
    {
        

        if(_onClick != nullptr)
        {
            _onClick();
        }
    }
}

}