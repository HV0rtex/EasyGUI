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
 * @file Task.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Task abstract class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

// Including dependencies
#include <memory>

namespace easyGUI
{

/**
 * @brief Wrapper around an abstract callable.
 * 
 * @details This class serves to provide an interface for other
 * classes which need to run any function with any parameters.
 * This way, any derived class will be compatible with methods
 * such as onClick() and onHover()
 * 
 * @warning This class cannot be used as a standalone.
 */
class Task
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Task() = default;
    
    /**
     * @brief Constructor
     * 
     */
    Task() = default;

    /**
     * @brief Executes the task
     * 
     */
    virtual void exec() {}
};

/**
 * @brief Safely appends a component to a menu.
 * 
 * @details Attempts to append a component to a menu. The macro
 * handles any possible error thrown by the component, so that it will
 * not affect the rest of the application.
 */
template < class Class, class... Args> std::shared_ptr<Task> CreateNewTask(Args... constructorArgs)
{
    ::std::shared_ptr<Class> ptr = ::std::make_shared<Class>(constructorArgs...);
    return ::std::dynamic_pointer_cast<Task>(ptr);
}

}
