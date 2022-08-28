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

namespace easyGUI
{

// Defining the application instance
Application* Application::instance = 0;

Application::Application(const unsigned& width, const unsigned& height, const char* title)
{
    _window = new ::sf::RenderWindow(::sf::VideoMode(width,height), title);
}

Application* Application::getInstance(const unsigned& width, const unsigned& height, const char* title, const char& isResponsive)
{
    if(title != nullptr)
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

        instance->_responsive = isResponsive;

        return instance;
    }

    return nullptr;
}

void Application::handleEvents(const ::sf::Event& event)
{
    for(Routine*& routine : routines)
    {
        routine->operator()(event);
    }
}

Menu* Application::getMenu(const ::std::string& id)
{
    if(menus.find(id) != menus.end())
    {
        return menus[id];
    }

    return nullptr;
}

::std::string Application::addMenu(const bool& isStart)
{
    ::std::string id;
    Menu* newMenu = new Menu();

    for(unsigned index = 0; index < (menus.size() + 1) / 256; index++)
    {
        id += "M";
    }

    char end = (menus.size() + 1) % 256;

    id += end;

    menus[id] = newMenu;

    if(isStart)
    {
        if(_activeMenu == nullptr)
        {
            _activeMenu = newMenu;
        }
        else
        {
            throw ::std::invalid_argument("Multiple start menus detected.");
        }
    }

    return id;
}

void Application::setActiveMenu(const ::std::string& id)
{
    if(menus.find(id) != menus.end())
    {
        _activeMenu = menus[id];
    }
    else
    {
        throw ::std::invalid_argument("Invalid menu ID provided.");
    }
}

void Application::addRoutine(Routine*& routine)
{
    routines.push_back(routine);
}

void Application::start()
{
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

}