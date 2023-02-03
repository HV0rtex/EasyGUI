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
 * @file Routine.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the routine class
 * 
 * @copyright Copyright (c) 2022
 */

#include <Routine.hpp>

namespace easyGUI
{

Routine::Routine(bool (*trigger)(const ::sf::Event&), void(*response)())
{
    if(!trigger || !response)
        throw ApplicationException("Invalid initialization of routine.");

    _trigger = trigger;
    _action = ::std::make_shared<Routine::DeprecatedTask>(response);
    _isActive = true;
}

Routine::Routine(bool (*trigger)(const ::sf::Event&), const ::std::shared_ptr<Task>& action)
{
    if(!trigger || !action)
        throw ApplicationException("Invalid initialization of routine.");

    _trigger = trigger;
    _action = action;
    _isActive = true;
}

void Routine::setActive(const bool& active)
{
    _isActive = active;
}

void Routine::operator()(const ::sf::Event &event) const
{
    if(_isActive && _trigger(event))
    {
        _action->exec();
    }
}

}