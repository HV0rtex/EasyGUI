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
#include <Component.hpp>
#include <string>
#include <vector>
#include <map>

namespace easyGUI
{

/**
 * @brief Container of application components
 * 
 * A menu groups different application components under the same container
 * and usually corresponds to a specific application screen.
 */
class Menu : public ::sf::Drawable
{
private:
    ::std::vector < Component* > _components;
    ::std::map < ::std::string, Component* > _componentMap;
 
    virtual void draw(::sf::RenderTarget& target, ::sf::RenderStates states) const;

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
     * @details Upon adding the component, the function returns a string
     * denoting a unique ID for the component. That way, each component
     * can be identified by its menu and ID.
     * 
     * @param component The component to be added
     * @return ::std::string 
     */
    ::std::string addComponent(Component* component);

    /**
     * @brief Retrieves a specific component
     * 
     * @param id The id of the component
     * @return Component* 
     */
    Component* getComponent(const ::std::string& id);
};

}