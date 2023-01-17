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
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <Point.hpp>
#include <Logger.hpp>

#include <memory>

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
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class ASSETS_EXPORTS Component : public ::sf::Drawable
#else
class Component : public ::sf::Drawable
#endif
{
protected:
    std::shared_ptr<::sf::RenderWindow> _container;

    void (*_onClick)() = nullptr;
    void (*_onHover)() = nullptr;

public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Component() = default;

    /**
     * @brief Set the Component's container
     * 
     * @param container The window responsible of the component
     */
    void setContainer(const ::std::shared_ptr<::sf::RenderWindow>&);

    // ----- Interaction methods -----

    /**
     * @brief Check if mouse is over the button
     * 
     * @return true Mouse is over the label
     * @return false otherwise
     */
    virtual bool isMouseHover() const = 0;

    /**
     * @brief Makes the component interactable
     * 
     * @param action Function to be called when component is clicked.
     */
    void setOnClickAction(void (*)());

    /**
     * @brief Sets the behaviour when the mouse is moved
     * 
     * @param action The action to be executed.
     */
    void setOnHoverAction(void (*)());

    /**
     * @brief Executes the onClick action
     * 
     */
    virtual void onClick();

    /**
     * @brief Executes the onHover action
     * 
     */
    virtual void onHover();

    /**
     * @brief Updates a component's location
     * 
     * @param newLocation The new location of the component
     */
    virtual void updateLocation(const Point&) = 0;
};

}