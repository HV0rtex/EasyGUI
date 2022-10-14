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


TextBox::TextBox(
    const Point& startLocation,
    const Point& endLocation,

    const ::sf::Color& fillColor,
    const ::sf::Color& outlineColor,
    const ::sf::Color& textColor,

    const ::std::string& fontPath,

    const unsigned& charSize,
    const unsigned& thickness)
{
    _shape.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _shape.setFillColor(fillColor);
    _shape.setOutlineColor(outlineColor);
    _shape.setOutlineThickness(thickness);
    _shape.setSize(::sf::Vector2f(endLocation.Xcoord - startLocation.Xcoord, endLocation.Ycoord - startLocation.Ycoord));

    desiredSize = charSize;

    try
    {
        FontManager* manager = nullptr;
        manager = manager->getInstance();

        if(manager == nullptr)
        {
            throw TextBoxException("Could not get hold of Font Manager.");
        }

        _font = manager->getFont(fontPath);

        _text.setFillColor(textColor);
        _text.setFont(*_font.get());
    } 
    catch (const FontException& err)
    {
        ERROR << err.what();

        throw TextBoxException("Label text will not be visible.");
    }
}

TextBox::TextBox(
    const Point& startLocation,
    const unsigned& width,
    const unsigned& height,

    const ::sf::Color& fillColor,
    const ::sf::Color& outlineColor,
    const ::sf::Color& textColor,

    const ::std::string& fontPath,

    const unsigned& charSize,
    const unsigned& thickness) : 
    
TextBox(
    startLocation, 
    Point(startLocation.Xcoord + width, startLocation.Ycoord + height),
    fillColor,
    outlineColor,
    textColor,
    fontPath,
    charSize,
    thickness
) {}

void TextBox::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_shape);

    if(!_text.getString().isEmpty())
    {
        target.draw(_text);
    }
}

bool TextBox::isMouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);

        if(_shape.getGlobalBounds().contains(currentPosition.x, currentPosition.y))
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