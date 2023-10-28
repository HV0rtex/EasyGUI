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
 * @file Routine.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the routine class
 * 
 * @copyright Copyright (c) 2022
 */

#include <Routine.hpp>


namespace easyGUI {

Routine::Routine(const std::function<bool(const sf::Event&)>& trigger,
                 const std::function<void()>& response) {
    if (!trigger || !response)
        throw ApplicationException("Invalid initialization of routine.");

    trigger_ = trigger;
    action_ = response;
    isActive_ = true;
}

void Routine::toggle() {
    isActive_ = !isActive_;
}

void Routine::operator()(const ::sf::Event &event) const {
    if (isActive_ && trigger_(event))
        action_();
}

}  // namespace easyGUI
