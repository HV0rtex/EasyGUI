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

CheckBox::~CheckBox()
{
    if(_component != nullptr)
    {
        delete _component;
    }
}

void CheckBox::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_box, states);

    if(_component != nullptr)
        target.draw(*_component, states);

    if(_checked)
        target.draw(_filler, states);
}

void CheckBox::updateLocation(const Point& newLocation)
{
    _box.setPosition(newLocation.Xcoord, newLocation.Ycoord);
    _filler.setPosition(newLocation.Xcoord + 7, newLocation.Ycoord + 7);

    switch(_allignment)
    {
        case Allignment::BOTTOM:
            _component->updateLocation(Point(newLocation.Xcoord, newLocation.Ycoord + 20));
            break;
        
        case Allignment::TOP:
            _component->updateLocation(Point(newLocation.Xcoord, newLocation.Ycoord - 20));
            break;

        case Allignment::LEFT:
            _component->updateLocation(Point(newLocation.Xcoord - 20, newLocation.Ycoord));
            break;

        case Allignment::RIGHT:
            _component->updateLocation(Point(newLocation.Xcoord + 20, newLocation.Ycoord));
            break;

        default:
            break;
    }
}

CheckBox::CheckBox(const Point& startLocation, const Allignment& allignment, Component* content)
{
    _box.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _box.setFillColor(::sf::Color::Black);
    _box.setOutlineColor(::sf::Color::White);
    _box.setOutlineThickness(3);
    _box.setSize(::sf::Vector2f(20, 20));

    _filler.setPosition(startLocation.Xcoord + 7, startLocation.Ycoord + 7);
    _filler.setFillColor(::sf::Color::White);
    _filler.setOutlineColor(::sf::Color::White);
    _filler.setSize(::sf::Vector2f(6,6));
    _filler.setOutlineThickness(3);

    _component = content;
    _allignment = allignment;
    _checked = false;

    switch(allignment)
    {
        case Allignment::BOTTOM:
            content->updateLocation(Point(startLocation.Xcoord, startLocation.Ycoord + 10));
            break;
        
        case Allignment::TOP:
            content->updateLocation(Point(startLocation.Xcoord, startLocation.Ycoord - 20));
            break;

        case Allignment::LEFT:
            content->updateLocation(Point(startLocation.Xcoord - 20, startLocation.Ycoord - 5));
            break;

        case Allignment::RIGHT:
            content->updateLocation(Point(startLocation.Xcoord + 30, startLocation.Ycoord - 5));
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
        _checked = !_checked;

        if(_onClick != nullptr)
        {
            _onClick();
        }
    }
}

bool CheckBox::isChecked() const
{
    return _checked;
}

}