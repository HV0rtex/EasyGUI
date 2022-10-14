/**
 * @file PasswordBox.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the PasswordBox class
 * @version 0.1
 * @date 2022-10-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <PasswordBox.hpp>

namespace easyGUI
{

const ::std::string PasswordBox::getText() const
{
    return _passText;
}

void PasswordBox::updateText(const ::sf::Uint32& text)
{
    ::sf::String newContent = _text.getString();

    if(text == 8 && !newContent.isEmpty())
        newContent.erase(newContent.getSize() - 1);
    else
        newContent.insert(newContent.getSize(), "*");

    unsigned correction = getCharSizeCorrection(newContent.getSize(), desiredSize);

    _passText = newContent.toAnsiString();

    if(correction != 0)
    {
        WARN << "TextBox text doesn't fit. Resizing text...\n";
    }

    Point pos = getLabelPosition(newContent.getSize(), desiredSize - correction);

    _text.setString(newContent);
    _text.setPosition(pos.Xcoord, pos.Ycoord);
    _text.setCharacterSize(desiredSize - correction);
}

}