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
 * @file Routine.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Routine class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <application-export.hpp>
#endif

#include <SFML/Window/Event.hpp>
#include <Exceptions/ApplicationException.hpp>
#include <memory>
#include <functional>

namespace easyGUI
{

/**
 * @brief Defines a way to control the application flow
 * 
 * @details A routine denotes a procedure which is called if and only if specific
 * application events are fired. That way, it allows the user to control the flow
 * of the application.
 * 
 * For instance a routine may be called when a mouse is pressed on a button, but a second
 * routine may also fire if it is configured to fire whenever the mouse is pressed, regardless
 * of the mouse position.
 * 
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class APPLICATION_EXPORTS Routine
#else
class Routine
#endif
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Routine() = default;

    /**
     * @brief Constructor
     * 
     * @param trigger The trigger of the routine
     * @param response The response of the routine
     */
    Routine(
        const std::function<bool(const ::sf::Event&)>& trigger,
        const std::function<void()>& response);
    
    /**
     * @brief Call operator
     * 
     * @details The operator checks if the current event triggers the routine,
     * and on trigger fires the response action.
     */
    void operator() (const ::sf::Event& event) const;

    /**
     * @brief Enables / Disables the routine
     * 
     * @param active Denotes whether the routine should be active
     */
    void setActive(const bool& active);
private:
    std::function<void()> action_;
    std::function<bool(const ::sf::Event&)> trigger_;

    bool isActive_;
};

}