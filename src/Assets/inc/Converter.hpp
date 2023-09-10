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
 * @file Converter.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the converter class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <memory>

#include <PasswordBox.hpp>
#include <Separator.hpp>
#include <CheckBox.hpp>
#include <Button.hpp>
#include <Image.hpp>


namespace easyGUI {

/**
 * @brief Responsible for conversions between components
 * 
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class ASSETS_EXPORTS Converter
#else
class Converter
#endif
{
 public:
    /**
     * @brief Converts a Component object into a button
     * 
     * @param asset The component to be converted
     * 
     * @return ::std::shared_ptr<Button>
     */
    static ::std::shared_ptr<Button> getButton(::std::shared_ptr<Component>);

    /**
     * @brief Converts a Component object into a label
     * 
     * @param asset The component to be converted
     * 
     * @return ::std::shared_ptr<Label> 
     */
    static ::std::shared_ptr<Label> getLabel(::std::shared_ptr<Component>);

    /**
     * @brief Converts a component into a textbox
     * 
     * @param asset The component to be converted
     * 
     * @return ::std::shared_ptr<Textbox> 
     */
    static ::std::shared_ptr<TextBox> getTextbox(::std::shared_ptr<Component>);

    /**
     * @brief Converts a component into an image
     *
     * @param asset The component to be converted 
     *
     * @return ::std::shared_ptr<Image> 
     */
    static ::std::shared_ptr<Image> getImage(::std::shared_ptr<Component>);

    /**
     * @brief Converts a component into a check box
     *
     * @param asset The component to be converted 
     *
     * @return ::std::shared_ptr<CheckBox> 
     */
    static ::std::shared_ptr<CheckBox> getCheckBox(::std::shared_ptr<Component>);   // NOLINT

    /**
     * @brief Converts a component into a separator
     *
     * @param asset The component to be converted 
     *
     * @return ::std::shared_ptr<Separator> 
     */
    static ::std::shared_ptr<Separator> getSeparator(::std::shared_ptr<Component>); // NOLINT
};

}  // namespace easyGUI
