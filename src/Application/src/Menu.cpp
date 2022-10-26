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
 * @file Menu.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Menu class
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Menu.hpp>

namespace easyGUI
{

Menu::~Menu()
{
    for(Component*& element : _components)
    {
        delete element;
    }
}

Menu::Menu() {}

void Menu::addComponent(Component* component)
{
    _components.push_back(component);

    component->setContainer(_container);
}

void Menu::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    for(Component* const element : _components)
    {
        target.draw(*element, states);
    }
}

Component* Menu::getComponent(const unsigned& index)
{
    if(index < _components.size())
    {
        return _components.at(index);
    }

    return nullptr;
}

void Menu::setContainer(::sf::RenderWindow*& container)
{
    _container = container;
}

}