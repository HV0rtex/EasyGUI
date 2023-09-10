// Copyright © 2022 David Bogdan

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files
// (the “Software”), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the following
// conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/**
 * @file Application.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Application class
 * 
 * @copyright Copyright (c) 2022
 */

#include <Application.hpp>
#include <iostream>

namespace easyGUI
{

// Defining the application instance
std::shared_ptr<Application> Application::_instance = 0;

Application::Application(const uint32_t width, const uint32_t height, const char* title)
{
    _window = ::std::make_shared<::sf::RenderWindow>(::sf::VideoMode(width,height), title);

    _startMenuSet = false;
    _activeMenu = nullptr;
    _menus = ::std::map<::std::string, MenuPtr>();
    _routines = ::std::vector<Routine>();
}

::std::shared_ptr<Application> Application::getInstance(const uint32_t width, const uint32_t height, const char* title)
{
    if(title != nullptr && width > 0 && height > 0)
    {
        if(_instance == nullptr)
        {
            _instance = ::std::make_shared<Application>(Application(width, height, title));
        }
        else
        {
            // Adjust the window to the new configuration
            _instance->_window->setSize(::sf::Vector2u(width, height));
            _instance->_window->setTitle(title);
        }
    }

    if(_instance == nullptr)
    {
        ERROR << "Invalid parameters provided. Application _instance not created.";
        abort();
    }

    return _instance;
}

void Application::handleEvents(const ::sf::Event& event)
{
    bool& boxClicked = TextBox::getTextBoxClicked();
    TextBox* box = TextBox::getSelectedBox();
    ::std::vector<::std::shared_ptr<Component>> components = _activeMenu->getAllComponents();

    if(event.type == ::sf::Event::MouseButtonPressed && event.mouseButton.button == ::sf::Mouse::Left)
    {
        boxClicked = false;
        ::std::for_each(components.begin(), components.end(),
            [](::std::shared_ptr<Component>& comp) {comp->onClick();}
        );

        if(boxClicked == false)
            box = nullptr;
    }
    else if(event.type == ::sf::Event::MouseMoved)
    {
        ::std::for_each(components.begin(), components.end(),
            [](::std::shared_ptr<Component>& comp) {
                comp->onHover();
            }
        );
    }
    else if(event.type == ::sf::Event::TextEntered && box)
    {
        box->updateText(event.text.unicode);
    }
    else if(event.type == ::sf::Event::Resized)
    {
        ::sf::View newView = _window->getDefaultView();
        newView.setSize(event.size.width, event.size.height);
        
        _window->setView(newView);
    }

    for(const Routine& routine : _routines)
    {
        routine.operator()(event);
    }
}

::std::shared_ptr<Menu> Application::getMenu(const ::std::string& id)
{
    if(_menus.find(id) != _menus.end())
    {
        return _menus.at(id);
    }

    return nullptr;
}

::std::shared_ptr<Menu> Application::getActiveMenu()
{
    return _activeMenu;
}

Routine& Application::getRoutine(const uint32_t index)
{
    if(index < _routines.size())
    {
        return _routines.at(index);
    }

    throw ApplicationException("Attempting to get routine with invalid index: " + ::std::to_string(index));
}

void Application::stop()
{
    _window->close();
}

::std::shared_ptr<Menu> Application::addMenu(const ::std::string& id, const bool& isStart)
{
    if(_menus.find(id) != _menus.end())
        throw ApplicationException("A menu with this ID exists already: " + id);

    ::std::shared_ptr<Menu> newMenu = ::std::make_shared<Menu>();
    newMenu->setContainer(_window);

    if(isStart)
    {
        if(!_startMenuSet)
        {
            _activeMenu = newMenu;
            _startMenuSet = true;
        }
        else
        {
            throw ApplicationException("Could not create initial menu because another initial menu has already been created.");
        }
    }

    _menus.emplace(id, newMenu);

    return newMenu;
}

void Application::setActiveMenu(const ::std::string& id)
{
    if(_menus.find(id) != _menus.end())
    {
        TextBox* box = TextBox::getSelectedBox();

        _activeMenu = _menus.at(id);

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

void Application::addRoutine(const Routine& routine)
{
    _routines.push_back(routine);
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
            handleEvents(event);

        _window->clear();
        _window->draw(*_activeMenu);
        _window->display();
    }
}

::std::shared_ptr<::sf::RenderWindow> Application::getWindow()
{
    return _window;
}

}