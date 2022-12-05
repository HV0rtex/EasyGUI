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
 * @file Menu.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Menu class
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <Exceptions/AssetException.hpp>
#include <Exceptions/MenuException.hpp>
#include <Logger.hpp>
#include <Component.hpp>
#include <string>
#include <vector>
#include <map>

namespace easyGUI
{

/**
 * @brief Container of application components
 * 
 * @details A menu groups different application components under the same container
 * and usually corresponds to a specific application screen.
 */
#ifdef _WIN32
class __declspec(dllexport) Menu : public ::sf::Drawable
#else
class Menu : public ::sf::Drawable
#endif
{
private:
    ::sf::RenderWindow* _container;
    ::std::map <::std::string, Component* > _components;

    virtual void draw(::sf::RenderTarget&, ::sf::RenderStates) const;

public:
    /**
     * @brief Destructor
     * 
     */
    ~Menu();

    /**
     * @brief Constructor
     * 
     */
    Menu();

    /**
     * @brief Adds a new component to the menu
     * 
     * @param component The component to be added
     * @param ID A unique ID for the component
     * 
     * @throws MenuException A component with that ID already exists
     */
    void addComponent(Component*, const ::std::string&);

    /**
     * @brief Set the Component's container
     * 
     * @param container The window responsible of the component
     */
    void setContainer(::sf::RenderWindow*&);
    
    /**
     * @brief Retrieves a specific component
     * 
     * @param ID The ID of the component
     * @return Component* 
     */
    Component* getComponent(const ::std::string&);

    /**
     * @brief Returns a vector with all components
     * 
     * @return ::std::vector<Component*> 
     */
    ::std::vector<Component*> getAllComponents();
};

/**
 * @brief Safely appends a component to a menu.
 * 
 * @details Attempts to append a component to a menu. The macro
 * handles any possible error thrown by the component, so that it will
 * not affect the rest of the application.
 * 
 * @param targetMenu The menu to which the component is appended
 * @param element The component to append
 * 
 */
#define AddElement(targetMenu, element, id)                     \
{                                                               \
    try                                                         \
    {                                                           \
        (targetMenu)->addComponent((element), (id));            \
    }                                                           \
    catch(const AssetException& e)                              \
    {                                                           \
        ERROR << e.what();                                      \
    }                                                           \
}

}