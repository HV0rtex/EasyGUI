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
 * 
 * @copyright Copyright (c) 2022
 */

#include <TextBox.hpp>

namespace easyGUI
{

TextBox* TextBox::selectedBox = nullptr;
bool TextBox::textBoxClicked = false;

void TextBox::applyCharSizeCorrection()
{
    float lenghtInPix = _text->getInternalText().getGlobalBounds().width;
    float heightInPix = _text->getInternalText().getGlobalBounds().height;

    float freeSpaceX = _shape.getGlobalBounds().width - lenghtInPix;
    float freeSpaceY = _shape.getGlobalBounds().height - heightInPix;

    uint32_t size = desiredSize;

    while(freeSpaceX <= 20 || freeSpaceY <= 20)
    {
        size--;
        _text->getInternalText().setCharacterSize(size);

        lenghtInPix = _text->getInternalText().getGlobalBounds().width;
        heightInPix = _text->getInternalText().getGlobalBounds().height;

        freeSpaceX = _shape.getGlobalBounds().width - lenghtInPix;
        freeSpaceY = _shape.getGlobalBounds().height - heightInPix;
    }
}

TextBox* TextBox::getSelectedBox() 
{
    return selectedBox;
}

bool& TextBox::getTextBoxClicked()
{
    return textBoxClicked;
}

void TextBox::updateLocation(const Point& newLocation)
{
    _shape.setPosition(newLocation.Xcoord, newLocation.Ycoord);
    
    AlignmentTool& tool = AlignmentTool::getInstance();
    tool.triggerUpdate(this);
}

TextBox::TextBox(
    const Point& startLocation,
    const Point& endLocation,

    const ::std::string& fontPath,

    const uint32_t charSize)
{
    _shape.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _shape.setFillColor(::sf::Color::Black);
    _shape.setOutlineColor(::sf::Color::White);
    _shape.setOutlineThickness(5);
    _shape.setSize(::sf::Vector2f(endLocation.Xcoord - startLocation.Xcoord, endLocation.Ycoord - startLocation.Ycoord));

    desiredSize = charSize;

    try
    {
        AlignmentTool& tool = AlignmentTool::getInstance();

        _text = ::std::make_shared<Label>(Point(), "", fontPath, charSize);
        Anchor* cast = static_cast<Anchor*>(_text.get());
        
        tool.createBinding(
            cast, 
            this, 
            BindingPoint::LEFT, 
            BindingPoint::LEFT, Point(19, -7));
    } 
    catch (const LabelException& err)
    {
        ERROR << err.what();
        this->~TextBox();

        throw TextBoxException("Label text will not be visible.");
    }
}

TextBox::TextBox(
    const Point& startLocation,
    const float& width,
    const float& height,

    const ::std::string& fontPath,

    const uint32_t charSize) : 
TextBox(
    startLocation, 
    Point(startLocation.Xcoord + width, startLocation.Ycoord + height),
    fontPath,
    charSize
) {}

void TextBox::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_shape, states);

    if(!_text->getInternalText().getString().isEmpty())
    {
        target.draw(*_text, states);
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

TextBox::~TextBox()
{
    if(selectedBox == this)
    {
        selectedBox = nullptr;
        textBoxClicked = false;
    }
}

::sf::RectangleShape& TextBox::getInternalBox()
{
    return _shape;
}

::sf::Text& TextBox::getInternalText()
{
    return _text->getInternalText();
}

void TextBox::updateText(const uint32_t text)
{
    ::sf::String newContent = _text->getInternalText().getString();
    AlignmentTool& tool = AlignmentTool::getInstance();

    if(text == 8 && !newContent.isEmpty())
        newContent.erase(newContent.getSize() - 1);
    else
        newContent.insert(newContent.getSize(), text);

    _text->getInternalText().setString(newContent);
    applyCharSizeCorrection();

    if (_text->getInternalText().getCharacterSize() < desiredSize)
    {
        WARN << "[TextBox] Text has been resized in order to fit.\n";
    }

    tool.triggerUpdate(this);
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
        _onClick->exec();
    }
}

::std::string TextBox::getText() const
{
    return _text->getInternalText().getString().toAnsiString();
}

void TextBox::clear()
{
    _text->getInternalText().setString("");
}

Point TextBox::getLEFT() const
{
    return Point(_shape.getGlobalBounds().left, _shape.getGlobalBounds().top + _shape.getGlobalBounds().height / 2);
}

Point TextBox::getRIGHT() const
{
    return Point(_shape.getGlobalBounds().left + _shape.getGlobalBounds().width, _shape.getGlobalBounds().top + _shape.getGlobalBounds().height / 2);
}

Point TextBox::getTOP() const
{
    return Point(_shape.getGlobalBounds().left + _shape.getGlobalBounds().width / 2, _shape.getGlobalBounds().top);
}

Point TextBox::getBOTTOM() const
{
    return Point(_shape.getGlobalBounds().left + _shape.getGlobalBounds().width / 2, _shape.getGlobalBounds().top + _shape.getGlobalBounds().height);
}

Point TextBox::getCENTER() const
{
    return Point(_shape.getGlobalBounds().left + _shape.getGlobalBounds().width / 2, _shape.getGlobalBounds().top + _shape.getGlobalBounds().height / 2);
}

}