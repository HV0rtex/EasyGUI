/**
 * @file Component.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Component class
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Component.hpp>

namespace easyGUI
{

void Component::onClick()
{
    if(_onClick != nullptr && isMouseHover())
    {
        _onClick();
    }
}

void Component::onHover()
{
    if(_onHover != nullptr)
    {
        _onHover();
    }
}

void Component::setContainer(::sf::RenderWindow*& container)
{
    _container = container;
}

void Component::setOnClickAction(void (*action)())
{
    _onClick = action;
}

void Component::setOnHoverAction(void (*action)())
{
    _onHover = action;
}

}