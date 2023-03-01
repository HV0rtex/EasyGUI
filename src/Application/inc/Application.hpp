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
 * @file Application.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the application class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <application-export.hpp>
#endif

#include <Exceptions/ApplicationException.hpp>
#include <Routine.hpp>
#include <Menu.hpp>
#include <Textbox.hpp>

namespace easyGUI
{
/**
 * @brief Emulates a windowed application
 * 
 * @details The class acts as a wrapper around the ::sf::RenderWindow, and provides
 * easier management of the events (such as onClick, onKeyPress, etc.). Furthermore,
 * the window works with entire Menus of components, so that UI creation is faster
 * and easier. 
 * 
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    class APPLICATION_EXPORTS Application
#else
    class Application
#endif
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Application() = default;

    /**
     * @brief Start the application
     * 
     * Creates a new application with an empty window. If an application has already
     * been created, it will adjust the existing application to the new parameters.
     * 
     * @param width The width of the window
     * @param height The height of the window
     * @param title The title of the application
     * 
     * @return ::std::shared_ptr<Application>
     * 
     * @throws ApplicationInstance Failed to instantiate application.
     */
    ::std::shared_ptr<Application> getInstance(const uint32_t = 0, const uint32_t = 0, const char* = nullptr);

    /**
     * @brief Appends a new menu to the application
     * 
     * @details If no menu is specified as being a MAIN menu when calling
     * this function, then the first call to Application#setActiveMenu will
     * initialize that menu as being the MAIN menu.
     * 
     * @param ID The ID of the menu
     * @param isStart Denotes if the menu is to be displayed first
     * 
     * @returns ::std::shared_ptr<Menu>
     * 
     * @throws MenuException More than one start menu declared.
     * @throws MenuException A menu with that ID already exists.
     */
    ::std::shared_ptr<Menu> addMenu(const ::std::string&, const bool& = false);

    /**
     * @brief Gets a menu by its index
     * 
     * @param ID The unique ID of the menu
     * 
     * @return ::std::shared_ptr<Menu>
     */
    ::std::shared_ptr<Menu> getMenu(const ::std::string&);

    /**
     * @brief Retruns the active menu
     * 
     * @return ::std::shared_ptr<Menu>
     */
    ::std::shared_ptr<Menu> getActiveMenu();

    /**
     * @brief Gets a routine by its index
     * 
     * @param index The index of the routine
     * 
     * @return Routine&
     * 
     * @throws ApplicationException Invalid index provided
     */
    Routine& getRoutine(const uint32_t);

    /**
     * @brief Returns the SFML RenderWindow
     * 
     * @return ::std::shared_ptr<::sf::RenderWindow> 
     */
    ::std::shared_ptr<::sf::RenderWindow> getWindow();

    /**
     * @brief Changes the active menu
     * 
     * @param id The ID of the menu
     * 
     * @throw MenuException Invalid index provided
     */
    void setActiveMenu(const ::std::string&);

    /**
     * @brief Adds a new routine to the application
     * 
     * @param routine The routine to be added
     */
    void addRoutine(const Routine&);

    /**
     * @brief Starts the application
     * 
     * @details Opens the application window and begins
     * handling the events according to configured routines.
     * 
     * @throws ApplicationException No initial menu has been set.
     */
    void start();

    /**
     * @brief Stops the application
     * 
     * @details Closes the application window.
     */
    void stop();
private:
    static ::std::shared_ptr<Application> _instance;

    ::std::shared_ptr<::sf::RenderWindow> _window;

    ::std::map<::std::string, ::std::shared_ptr<Menu>> _menus;
    ::std::vector<Routine> _routines;
    ::std::shared_ptr<Menu> _activeMenu;

    // ----- Control variables -----

    bool _startMenuSet;

    /**
     * @brief Constructor
     * 
     * @details The constructor is made private in order to adhere to the Singleton
     * design pattern.
     * 
     * @param width The width of the window
     * @param height The height of the window
     * @param title The title of the application
     * 
     */
    explicit Application(const uint32_t, const uint32_t, const char*);

    /**
     * @brief Event handler
     * 
     * @details The function is fired whenever an event occurs at window level
     * and loops through routines and fires all routines that match that event.
     * 
     * @param event The current window event
     */
    void handleEvents(const ::sf::Event&);
};

using ApplicationPtr = ::std::shared_ptr<Application>;

}