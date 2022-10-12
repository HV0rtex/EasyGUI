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

void TextBox::constructText(const Point& position, const ::std::string& text, const unsigned& charSize, ::sf::Color textColor)
{
    _text.setPosition(position.Xcoord, position.Ycoord);
    _text.setFont(*_font.get());
    _text.setFillColor(textColor);
    _text.setCharacterSize(charSize);
    _text.setString(text);
}

TextBox::TextBox(
    const Point& startLocation,
    const Point& endLocation,

    const ::sf::Color& fillColor,
    const ::sf::Color& outlineColor,
    const ::sf::Color& textColor,

    const ::std::string& text,
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

    unsigned correction = getCharSizeCorrection(text.size(), charSize);

    if(correction != 0)
    {
        WARN << "TextBox text doesn't fit. Resizing text...\n";
    }

    try
    {
        FontManager* manager = nullptr;
        manager = manager->getInstance();

        if(manager == nullptr)
        {
            throw TextBoxException("Could not get hold of Font Manager.");
        }

        _font = manager->getFont(fontPath);

        constructText(getLabelPosition(text.size(), charSize - correction), text, charSize - correction, textColor);
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

    const ::std::string& text,
    const ::std::string& fontPath,

    const unsigned& charSize,
    const unsigned& thickness) : 
    
TextBox(
    startLocation, 
    Point(startLocation.Xcoord + width, startLocation.Ycoord + height),
    fillColor,
    outlineColor,
    textColor,
    text,
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

void TextBox::updateText(const ::sf::Event& event)
{
    if(selectedBox == nullptr || (event.type != ::sf::Event::TextEntered && (event.type != ::sf::Event::KeyPressed || event.key.code != ::sf::Keyboard::BackSpace)))
        return;

    ::sf::Text& text = selectedBox->getInternalText();
    ::sf::String newContent = text.getString();

    // if(event.type == ::sf::Event::KeyPressed && event.key.code == ::sf::Keyboard::BackSpace)
    // {
    //     newContent.erase(newContent.getSize() - 1);
    // }
    if(event.type == ::sf::Event::KeyPressed)
    {
        if(event.text.unicode == ::sf::Keyboard::BackSpace)
        {
            newContent.erase(newContent.getSize() - 1);
        }
        else
        {
            WARN << event.text.unicode;

            newContent.insert(newContent.getSize(), event.text.unicode);
        }
    }

    unsigned correction = getCharSizeCorrection(newContent.getSize(), desiredSize);

    if(correction != 0)
    {
        WARN << "TextBox text doesn't fit. Resizing text...\n";
    }


    Point pos = getLabelPosition(newContent.getSize(), desiredSize - correction);

    text.setString(newContent);
    text.setPosition(pos.Xcoord, pos.Ycoord);
    text.setCharacterSize(desiredSize - correction);
}

void TextBox::onClick()
{
    if(isMouseHover())
    {
        selectedBox = this;
    }
}

}