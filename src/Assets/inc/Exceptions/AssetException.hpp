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
 * @file AssetException.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the base exception class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <iostream>
#include <exception>
#include <string>

#ifndef ERROR
#define ERROR std::cout << "[ERROR] "
#endif

#ifndef WARN
#define WARN std::cout << "[WARNING] "
#endif

#ifndef INFO
#define INFO std::cout << "[INFO] "
#endif


namespace easyGUI {

/**
 * @brief Exception thrown when something goes wrong at Asset level.
 * 
 */
class AssetException : public ::std::exception {
 public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~AssetException() = default;

    /**
     * @brief Constructor
     * 
     * @param message The message to be displayed
     */
    explicit AssetException(const ::std::string& message):
        _msg("[ASSET] " + message + "\n") {}

    /**
     * @brief Returns the exception message
     * 
     * @return const char* 
     */
    const char* what() const noexcept {
        return _msg.c_str();
    }

 private:
    ::std::string _msg;
};

}  // namespace easyGUI
