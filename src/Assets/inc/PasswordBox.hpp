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
 * @file PasswordBox.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the password box class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <string>

#include <Textbox.hpp>


namespace easyGUI {

/**
 * @brief A textbox that hides the text entered
 * 
 * @details This class acts just like a textbox, except it doesn't display the actual
 * text entered, but an array of stars (*). For this reason, a Component* cannot be converted
 * into a password box via the Converter class.
 * 
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class ASSETS_EXPORTS PasswordBox : public TextBox
#else
class PasswordBox : public TextBox
#endif
{
 public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~PasswordBox() = default;

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param endLocation The location of the bottom-right corner

     * @param fontPath The path to the font file
     * 
     * @param charSize The size of the characters
     * 
     * @throw TextBoxException
     * 
     * @note The font file format must be .ttf
     */
    explicit PasswordBox(const Point&,
                         const Point&,
                         const ::std::string&,
                         const uint32_t);

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param width The width of the button
     * @param height The height of the button
     * 
     * @param fontPath The path to the font file
     * 
     * @param charSize The size of the characters
     * 
     * @throw TextBoxException
     * 
     * @note The font file format must be .ttf
     */
    explicit PasswordBox(const Point&,
                         const float&,
                         const float&,
                         const ::std::string&,
                         const uint32_t);

    // Block other forms of construction

    PasswordBox() = delete;
    PasswordBox(const PasswordBox&) = delete;
    PasswordBox& operator= (const PasswordBox&) = delete;

    /**
     * @brief Returns a string containing the text in the box
     * 
     * @return ::std::string 
     */
    ::std::string getText() const override;

    /**
     * @brief Updates the text of the keyboard
     * 
     * @param text The text that has been entered
     */
    void updateText(const uint32_t) override;
 private:
    ::std::string _passText;
};

}  // namespace easyGUI
