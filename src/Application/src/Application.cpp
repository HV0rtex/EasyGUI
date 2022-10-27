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
 * @file Application.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Application class
 * @version 0.1
 * @date 2022-08-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Application.hpp>
#include <iostream>

namespace easyGUI
{

// Defining the application instance
Application* Application::instance = 0;

Application::Application(const unsigned& width, const unsigned& height, const char* title)
{
    _window = new ::sf::RenderWindow(::sf::VideoMode(width,height), title);
}

Application* Application::getInstance(const unsigned& width, const unsigned& height, const char* title)
{
    if(title != nullptr && width > 0 && height > 0)
    {
        if(instance == nullptr)
        {
            instance = new Application(width, height, title);
        }
        else
        {
            // Adjust the window to the new configuration
            instance->_window->setSize(::sf::Vector2u(width, height));
            instance->_window->setTitle(title);
        }
    }

    if(instance == nullptr)
    {
        ERROR << "Invalid parameters provided. Application instance not created.";
        abort();
    }

    return instance;
}

void Application::executeForAll(void (*action)(Component*))
{
    unsigned index = 0;
    
    for(Component*& currentComponent : _activeMenu->getAllComponents())
    {
        action(currentComponent);
    }
}

void Application::handleEvents(const ::sf::Event& event)
{
    if(event.type == ::sf::Event::MouseButtonPressed && event.mouseButton.button == ::sf::Mouse::Left)
    {
        TextBox::textBoxClicked = false;

        executeForAll([](Component* comp) {comp->onClick();});
    
        if(TextBox::textBoxClicked == false)
            TextBox::selectedBox = nullptr;
    }
    else if(event.type == ::sf::Event::MouseMoved)
    {
        executeForAll([](Component* comp) {comp->onHover();});
    }
    else if(event.type == ::sf::Event::TextEntered && TextBox::selectedBox != nullptr)
    {
        TextBox::selectedBox->updateText(event.text.unicode);
    }

    for(Routine*& routine : routines)
    {
        routine->operator()(event);
    }
}

Menu* Application::getMenu(const ::std::string& id)
{
    if(menus.find(id) != menus.end())
    {
        return menus.at(id);
    }

    return nullptr;
}

Menu* Application::getActiveMenu()
{
    return _activeMenu;
}

Routine* Application::getRoutine(const unsigned& index)
{
    if(index < routines.size())
    {
        return routines.at(index);
    }

    return nullptr;
}

void Application::stop()
{
    _window->close();
}

Application::~Application()
{
    for(auto menu : menus)
    {
        delete menu.second;
    }
}

Menu* Application::addMenu(const ::std::string& id, const bool& isStart)
{
    if(menus.find(id) != menus.end())
    {
        throw MenuException("A menu with this ID exists already");
    }

    Menu* newMenu = new Menu();

    if(isStart)
    {
        if(!_startMenuSet)
        {
            _activeMenu = newMenu;
            _startMenuSet = true;
        }
        else
        {
            delete newMenu;

            throw MenuException("Could not create initial menu because another initial menu was already created.");
        }
    }

    newMenu->setContainer(_window);

    menus.insert(::std::make_pair(id, newMenu));

    return newMenu;
}

void Application::setActiveMenu(const ::std::string& id)
{
    if(menus.find(id) != menus.end())
    {
        _activeMenu = menus.at(id);
        TextBox::selectedBox = nullptr;

        if(!_startMenuSet)
        {
            // A main menu can also be configured by manually setting
            // the active menu.
            INFO << "No start menu detected. Defaulting to the one specified in call.";

            _startMenuSet = true;
        }
    }
    else
    {
        throw MenuException("Could not get hold of menu wiht id: " + id);
    }
}

void Application::addRoutine(Routine* routine)
{
    routines.push_back(routine);
}

void Application::start()
{
    if(_activeMenu == nullptr)
    {   
        throw ApplicationException("Attempting start with no initial menu.");
    }

    while(_window->isOpen())
    {
        ::sf::Event event;

        while(_window->pollEvent(event))
        {
            handleEvents(event);
        }

        _window->clear();
        _window->draw(*_activeMenu);
        _window->display();
    }
}

::sf::RenderWindow* Application::getWindow()
{
    return _window;
}

}