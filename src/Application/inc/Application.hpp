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
 * @version 0.1
 * @date 2022-08-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <Routine.hpp>

namespace easyGUI
{

/**
 * @brief Emulates a windowed application
 * 
 * @details The class acts as a wrapper around the ::sf::RenderWindow, and provides
 * easier management of the events (such as onClick, onKeyPress, etc.) Furthermore,
 * when the RESPONSIVE option is set to True, the application will automatically resive the
 * GUI in order to match the new window size.
 * 
 */
class Application
{
private:
    static Application* instance;

    ::sf::RenderWindow* _window;
    ::std::vector < const Routine* > routines;

    // ----- Configurations -----

    char _responsive;

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
    Application(const unsigned& width, const unsigned& height, const char* title);

    /**
     * @brief Event handler
     * 
     * @details The function is fired whenever an event occurs at window level
     * and loops through routines to find the best fit for the event.
     * 
     * @param event The current window event
     * 
     * @warning Not yet implemented.
     */
    void handleEvents(const ::sf::Event& event);

public:
    /**
     * @brief Destructor
     * 
     */
    ~Application();

    /**
     * @brief Start the application
     * 
     * Creates a new application with an empty window. If an application has already
     * been created, it will adjust the existing application to the new parameters.
     * 
     * @param width The width of the window
     * @param height The height of the window
     * @param title The title of the application
     * @param isResponsive Flag to mark if the application should be responsive or not
     * 
     * @return Application* 
     */
    Application* getInstance(const unsigned& width, const unsigned& height, const char* title, const char& isResponsive = 0);

    /**
     * @brief Appends a new menu to the application
     * 
     * The appended menu can be referenced via the index
     * returned by the function.
     * 
     * @param isStart Denotes if the menu is to be displayed first
     * 
     * @returns const char*
     * @retval NULL the menu could not be added
     * @retval String The unique ID of the menu.
     * 
     * @note Only one menu can be declared as start menu
     * @warning Not yet implemented.
     */
    const char* addMenu(const bool& isStart = false);

    /**
     * @brief Gets a menu by its ID
     * 
     * @param id The ID of the menu
     * 
     * @return Menu*
     * @retval NULL invalid ID
     * @retval Menu The menu linked to that ID.
     * 
     * @warning Not yet implemented.
     */
    void getMenu(const char* id);

    /**
     * @brief Adds a new routine to the application
     * 
     * @param routine The routine to be added
     */
    void addRoutine(const Routine*& routine);

    /**
     * @brief Starts the application
     * 
     * Opens the application window and handles
     * the events according to routines.
     * 
     */
    void start();
};

}