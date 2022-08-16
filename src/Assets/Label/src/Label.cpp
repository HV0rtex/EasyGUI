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

namespace egui
{

void Label::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    target.draw(_text, states);
}

void Label::constructText(const utils::Point& position, const ::std::string& text, const unsigned& charSize)
{
    _text.setPosition(position.Xcoord, position.Ycoord);
    _text.setFont(_font);
    _text.setFillColor(_textColor);
    _text.setCharacterSize(charSize);
    _text.setString(text);
}

bool Label::mouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);

        if(_text.getGlobalBounds().contains(currentPosition.x, currentPosition.y))
            return true;
    }

    return false;
}

Label::~Label() {}
Label::Label(const utils::Point& position, const ::std::string& text, const ::std::string& fontPath, const unsigned& charSize, const sf::Color& color)
{
    if(!_font.loadFromFile(fontPath))
    {
        throw ::std::invalid_argument("Invalid font path!");
    }

    _textColor = color;

    _container = nullptr;
    _onClickAction = nullptr;
    _onHoverAction = nullptr;

    constructText(position, text, charSize);
}

void Label::onClick()
{
    if(_onClickAction != nullptr)
    {
        _onClickAction();
    }
}

void Label::onHover()
{
    if(_onHoverAction != nullptr)
    {
        _onHoverAction();
    }
}

}