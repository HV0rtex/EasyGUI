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
 * @file TextBox.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the TextBox class
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Textbox.hpp>

namespace easyGUI
{

TextBox* TextBox::selectedBox = nullptr;
bool TextBox::textBoxClicked = false;

unsigned TextBox::getCharSizeCorrection(const unsigned& length, const unsigned& charSize) const
{
    float lenghtInPix = length * charSize / 1.9;
    float heightInPix = charSize * 1.55;

    float freeSpaceX = _shape.getSize().x - lenghtInPix;
    float freeSpaceY = _shape.getSize().y - heightInPix;

    unsigned correction = 0;

    while(freeSpaceX <= 0 || freeSpaceY <= 0)
    {
        correction++;

        lenghtInPix = length * (charSize - correction) / 1.9;
        heightInPix = (charSize - correction) * 1.5;

        freeSpaceX = _shape.getSize().x - lenghtInPix;
        freeSpaceY = _shape.getSize().y - heightInPix;
    }

    return correction;
}

Point TextBox::getLabelPosition(const unsigned& length, const unsigned& charSize) const
{
    float lenghtInPix = length * charSize / 1.9;
    float heightInPix = charSize * 1.55;

    float freeSpaceX = _shape.getSize().x - lenghtInPix;
    float freeSpaceY = _shape.getSize().y - heightInPix;

    return Point(_shape.getPosition().x + freeSpaceX / 2, _shape.getPosition().y + freeSpaceY / 2);
}

void TextBox::updateLocation(const Point& newLocation)
{
    _shape.setPosition(newLocation.Xcoord, newLocation.Ycoord);
    
    if(!_text.getString().isEmpty())
    {
        Point newTextLocation = getLabelPosition(_text.getString().getSize(), _text.getCharacterSize());

        _text.setPosition(newTextLocation.Xcoord, newTextLocation.Ycoord);
    }
}

TextBox::TextBox(
    const Point& startLocation,
    const Point& endLocation,

    const ::std::string& fontPath,

    const unsigned& charSize)
{
    _shape.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _shape.setFillColor(::sf::Color::Black);
    _shape.setOutlineColor(::sf::Color::White);
    _shape.setOutlineThickness(5);
    _shape.setSize(::sf::Vector2f(endLocation.Xcoord - startLocation.Xcoord, endLocation.Ycoord - startLocation.Ycoord));

    desiredSize = charSize;

    try
    {
        FontManager* manager = FontManager::getInstance();

        if(manager == nullptr)
        {
            throw TextBoxException("Could not get hold of Font Manager.");
        }

        _font = manager->getAsset(fontPath);

        _text.setFillColor(::sf::Color::White);
        _text.setFont(*_font.get());
    } 
    catch (const ManagerException& err)
    {
        ERROR << err.what();

        throw TextBoxException("Label text will not be visible.");
    }
}

TextBox::TextBox(
    const Point& startLocation,
    const float& width,
    const float& height,

    const ::std::string& fontPath,

    const unsigned& charSize) : 
TextBox(
    startLocation, 
    Point(startLocation.Xcoord + width, startLocation.Ycoord + height),
    fontPath,
    charSize
) {}

void TextBox::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_shape, states);

    if(!_text.getString().isEmpty())
    {
        target.draw(_text, states);
    }
}

bool TextBox::isMouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);
        ::sf::Vector2f worldPos = _container->mapPixelToCoords(currentPosition);

        if(_shape.getGlobalBounds().contains(worldPos.x, worldPos.y))
            return true;
    }

    return false;
}

::sf::RectangleShape& TextBox::getInternalBox()
{
    return _shape;
}

::sf::Text& TextBox::getInternalText()
{
    return _text;
}

void TextBox::updateText(const ::sf::Uint32& text)
{
    ::sf::String newContent = _text.getString();

    if(text == 8 && !newContent.isEmpty())
        newContent.erase(newContent.getSize() - 1);
    else
        newContent.insert(newContent.getSize(), text);

    unsigned correction = getCharSizeCorrection(newContent.getSize(), desiredSize);

    if(correction != 0)
    {
        WARN << "TextBox text doesn't fit. Resizing text...\n";
    }


    Point pos = getLabelPosition(newContent.getSize(), desiredSize - correction);

    _text.setString(newContent);
    _text.setPosition(pos.Xcoord, pos.Ycoord);
    _text.setCharacterSize(desiredSize - correction);
}

void TextBox::onClick()
{
    if(isMouseHover())
    {
        selectedBox = this;
        textBoxClicked = true;
    }

    if(_onClick != nullptr)
    {
        _onClick();
    }
}

const ::std::string TextBox::getText() const
{
    return _text.getString().toAnsiString();
}

void TextBox::clear()
{
    _text.setString("");
}

}