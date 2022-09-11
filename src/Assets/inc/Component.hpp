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
 * @file Component.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Component class
 * @version 0.1
 * @date 2022-08-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace easyGUI
{

/**
 * @brief Interface for drawable elements
 * 
 * @details This is the interface that all application components will inherit.
 * Some of them may also inherit other interfaces which will enable them
 * to interact with certain types of events such as OnMousePress or OnKeyPress,
 * however this one is mandatory for all GUI elements.
 * 
 */
class Component : public ::sf::Drawable
{
protected:
    ::sf::RenderWindow* _container;

public:

    /**
     * @brief Set the Component's container
     * 
     * @param container The window responsible of the component
     */
    void setContainer(::sf::RenderWindow*& container)
    {
        _container = container;
    }

    // ----- Auxiliaries -----

    /**
     * @brief Check if mouse is over the button
     * 
     * @return true Mouse is over the label
     * @return false otherwise
     */
    virtual bool isMouseHover() const = 0;
};

}