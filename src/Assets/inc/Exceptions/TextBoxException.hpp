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
 * @file TextBoxException.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the TextBoxException class
 * 
 * @copyright Copyright (c) 2022 
 */

#pragma once

#include <string>

#include <Exceptions/AssetException.hpp>


namespace easyGUI {

/**
 * @brief Exception thrown when an error occurs inside the TextBox.
 * 
 */
class TextBoxException : public AssetException {
 public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~TextBoxException() = default;

    /**
     * @brief Constructor
     * 
     * @param message The message to be displayed
     */
    explicit TextBoxException(const ::std::string& message):
        AssetException("[ TextBox ] " + message) {}
};

}  // namespace easyGUI
