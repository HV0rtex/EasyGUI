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
    Component* currentComp = _activeMenu->getComponent(0);

    while(currentComp != nullptr)
    {
        action(currentComp);

        index++;
        currentComp = _activeMenu->getComponent(index);
    }
}

void Application::handleEvents(const ::sf::Event& event)
{
    if(event.type == ::sf::Event::MouseButtonPressed && event.mouseButton.button == ::sf::Mouse::Left)
    {
        executeForAll([](Component* comp) {comp->onClick();});
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

Menu* Application::getMenu(const unsigned& index)
{
    if(index < menus.size())
    {
        return menus.at(index);
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
        delete menu;
    }
}

Menu* Application::addMenu(const bool& isStart)
{
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

    menus.push_back(newMenu);

    return newMenu;
}

void Application::setActiveMenu(const unsigned& index)
{
    if(index < menus.size())
    {
        _activeMenu = menus.at(index);
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
        throw MenuException("Could not get hold of menu wiht id " + index);
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