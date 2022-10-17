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
 * @file Converter.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the converter class
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <Button.hpp>
#include <PasswordBox.hpp>

namespace easyGUI
{

/**
 * @brief Responsible for conversions between components
 * 
 */
class Converter
{
public:
    /**
     * @brief Converts a Component object into a button
     * 
     * @param asset The component to be converted
     * 
     * @return Button* 
     * @retval nullptr Asset could not be converted
     */
    static Button* getButton(Component* asset);

    /**
     * @brief Converts a Component object into a label
     * 
     * @param asset The component to be converted
     * 
     * @return Label* 
     * @retval nullptr Asset could not be converted
     */
    static Label* getLabel(Component* asset);

    /**
     * @brief Converts a component into a textbox
     * 
     * @param asset The component to be converted
     * 
     * @return Textbox* 
     * @retval nullptr Asset could not be converted.
     */
    static TextBox* getTextbox(Component* asset);
};

}