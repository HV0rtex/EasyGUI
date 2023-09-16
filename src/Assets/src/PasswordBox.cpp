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
 * @file PasswordBox.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the PasswordBox class
 * 
 * @copyright Copyright (c) 2022
 */

#include <PasswordBox.hpp>

namespace easyGUI {

PasswordBox::PasswordBox(const Point& startLocation,
                         const Point& endLocation,
                         const ::std::string& fontPath,
                         const uint32_t charSize) :
    TextBox(startLocation, endLocation, fontPath, charSize) {}

PasswordBox::PasswordBox(const Point& startLocation,
                         const float& width,
                         const float& height,
                         const ::std::string& fontPath,
                         const uint32_t charSize) :
    TextBox(startLocation, width, height, fontPath, charSize) {}

::std::string PasswordBox::getText() const {
    return _passText;
}

void PasswordBox::updateText(const uint32_t text) {
    ::sf::String newContent = _text->getInternalText().getString();

    if (text == 8 && !newContent.isEmpty()) {
        newContent.erase(newContent.getSize() - 1);

        _passText.erase(_passText.end() - 1);
    } else {
        newContent.insert(newContent.getSize(), "*");

        _passText += ::sf::String(text).toAnsiString();
    }


    AlignmentTool& tool = AlignmentTool::getInstance();

    _text->getInternalText().setString(newContent);
    applyCharSizeCorrection();
    tool.triggerUpdate(this);

    if (_text->getInternalText().getCharacterSize() < desiredSize)
        WARN << "[PasswordBox] Text has been resized in order to fit.";
}

}  // namespace easyGUI
