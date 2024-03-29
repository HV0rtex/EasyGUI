// Copyright © 2022 David Bogdan

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files
// (the “Software”), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the following
// conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/**
 * @file Menu.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Menu class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <application-export.hpp>
#endif

#include <string>
#include <vector>
#include <memory>
#include <map>

#include <Exceptions/AssetException.hpp>
#include <Exceptions/MenuException.hpp>
#include <Component.hpp>


namespace easyGUI {

using WindowPtr = ::std::shared_ptr<::sf::RenderWindow>;

/**
 * @brief Container of application components
 * 
 * @details A menu groups different application components under the same container
 * and usually corresponds to a specific application screen. The menu also provides
 * a method for the components to react to events.
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class APPLICATION_EXPORTS Menu : public ::sf::Drawable
#else
class Menu : public ::sf::Drawable
#endif
{
 public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Menu() = default;

    /**
     * @brief Constructor
     * 
     */
    Menu() = default;

    /**
     * @brief Adds a new component to the menu
     * 
     * @param component The component to be added
     * @param ID A unique ID for the component
     * 
     * @throws MenuException A component with that ID already exists
     */
    void addComponent(const ::std::shared_ptr<Component>&,
                      const ::std::string&);

    /**
     * @brief Set the Component's container
     * 
     * @param container The window responsible of the component
     */
    void setContainer(const WindowPtr&);

    /**
     * @brief Retrieves a specific component
     * 
     * @param ID The ID of the component
     * @return ::std::shared_ptr<Component>
     */
    ::std::shared_ptr<Component> getComponent(const ::std::string&);

    /**
     * @brief Returns a vector with all components
     * 
     * @return ::std::vector<Component*> 
     */
    ::std::vector<::std::shared_ptr<Component>> getAllComponents();

    /**
     * @brief Clears the menu of all content.
     * 
     */
    void clear();
 private:
    ::std::map<::std::string, ::std::shared_ptr<Component>> _components;
    ::std::shared_ptr<::sf::RenderWindow> _container;

    virtual void draw(::sf::RenderTarget&, ::sf::RenderStates) const;
};

using MenuPtr = ::std::shared_ptr<Menu>;

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
template < class Class, class... Args>
void AddElement(const MenuPtr& targetMenu,
                const ::std::string& id,
                Args... constructorArgs) {
    try {
        ::std::shared_ptr<Class> ptr =
            ::std::make_shared<Class>(constructorArgs...);
        targetMenu->addComponent(ptr, id);
    }
    catch(const AssetException& e) {
        ERROR << e.what();
    }
    catch(const MenuException& e) {
        ERROR << e.what();
    }
}

}  // namespace easyGUI
