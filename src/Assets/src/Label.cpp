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
 * @file Label.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Label class
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Label.hpp>

namespace easyGUI
{

void Label::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_text, states);
}

bool Label::isMouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);
        ::sf::Vector2f worldPos = _container->mapPixelToCoords(currentPosition);

        if(_text.getGlobalBounds().contains(worldPos.x, worldPos.y))
            return true;
    }

    return false;
}

void Label::updateLocation(const Point& newLocation)
{
    _text.setPosition(newLocation.Xcoord, newLocation.Ycoord);

    AlignmentTool& tool = AlignmentTool::getInstance();
    tool.triggerUpdate(this->getShared());
}

void Label::toggleDecoration(const TextDecoration& deco)
{
    bool removed = false;
    auto res = ::std::remove_if(_decorations.begin(), _decorations.end(), 
        [&removed, &deco](const TextDecoration& elem) {
            removed = (elem == deco);
            return elem == deco;
    });

    if(removed)
        return;

    switch(deco)
    {
        case TextDecoration::BOLD:
            _text.setStyle(::sf::Text::Bold);
            break;
        case TextDecoration::ITALIC:
            _text.setStyle(::sf::Text::Italic);
            break;
        case TextDecoration::STRIKETHROUGH:
            _text.setStyle(::sf::Text::StrikeThrough);
            break;
        case TextDecoration::UNDERLINED:
            _text.setStyle(::sf::Text::Underlined);
            break;
        default:
            break;
    }
}

Label::Label(const Point& startLocation, const ::std::string& text, const ::std::shared_ptr<::sf::Font>& font, const uint32_t charSize)
{
    if(font == nullptr)
    {
        throw LabelException("Invalid font received");
    }

    _font = font;
 
    _text.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _text.setFont(*_font.get());
    _text.setFillColor(::sf::Color::White);
    _text.setCharacterSize(charSize);
    _text.setString(text);
}

Label::Label(const Point& startLocation, const ::std::string& text, const ::std::string& fontPath, const uint32_t charSize)
{
    try
    {
        FontManager& manager = FontManager::getInstance();

        _font = manager.getAsset(fontPath);

        _text.setPosition(startLocation.Xcoord, startLocation.Ycoord);
        _text.setFont(*_font.get());
        _text.setFillColor(::sf::Color::White);
        _text.setCharacterSize(charSize);
        _text.setString(text);
    }
    catch(const ManagerException& err)
    {
        ERROR << err.what();
        this->~Label();

        throw LabelException("Could not get font from Font Manager. Cannot create Label.");
    }
}

::sf::Text& Label::getInternalText()
{
    return _text;
}

Point Label::getLEFT() const
{
    return Point(_text.getGlobalBounds().left - 1, _text.getGlobalBounds().top - 7 + _text.getGlobalBounds().height / 2);
}

Point Label::getRIGHT() const
{
    return Point(_text.getGlobalBounds().left - 1 + _text.getGlobalBounds().width, _text.getGlobalBounds().top - 7 + _text.getGlobalBounds().height / 2);
}

Point Label::getTOP() const
{
    return Point(_text.getGlobalBounds().left - 1 + _text.getGlobalBounds().width / 2, _text.getGlobalBounds().top - 7);
}

Point Label::getBOTTOM() const
{
    return Point(_text.getGlobalBounds().left - 1 + _text.getGlobalBounds().width / 2, _text.getGlobalBounds().top - 7+ _text.getGlobalBounds().height);
}

Point Label::getCENTER() const
{
    return Point(_text.getGlobalBounds().left - 1 + _text.getGlobalBounds().width / 2, _text.getGlobalBounds().top - 7 + _text.getGlobalBounds().height / 2);
}

}