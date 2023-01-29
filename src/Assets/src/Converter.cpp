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
 * @file Converter.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Converter class
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Converter.hpp>

namespace easyGUI
{

::std::shared_ptr<Button> Converter::getButton(::std::shared_ptr<Component> asset)
{
    return ::std::dynamic_pointer_cast<Button>(asset);
}

::std::shared_ptr<Label> Converter::getLabel(::std::shared_ptr<Component> asset)
{
    return ::std::dynamic_pointer_cast<Label>(asset);
}

::std::shared_ptr<TextBox> Converter::getTextbox(::std::shared_ptr<Component> asset)
{
    return ::std::dynamic_pointer_cast<TextBox>(asset);
}

::std::shared_ptr<Image> Converter::getImage(::std::shared_ptr<Component> asset)
{
    return ::std::dynamic_pointer_cast<Image>(asset);
}

::std::shared_ptr<CheckBox> Converter::getCheckBox(::std::shared_ptr<Component> asset)
{
    return ::std::dynamic_pointer_cast<CheckBox>(asset);
}

::std::shared_ptr<Separator> Converter::getSeparator(::std::shared_ptr<Component> asset)
{
    return ::std::dynamic_pointer_cast<Separator>(asset);
}

}