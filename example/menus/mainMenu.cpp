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

#include <menus.hpp>
#include "buttons.hpp"

using namespace easyGUI;

void createMainMenu(Application* appInstance)
{
    if(appInstance == nullptr)
        // Raise error if application has not been created
        throw MenuException("Could not get hold of application instance.");

    Menu* menu = appInstance->addMenu(true);   // Adds a new MAIN menu

    if(menu == nullptr)
        // Raise error if creating a menu fails
        throw MenuException("Could not create menu.");

    AddElement(menu, new Label(Point(220, 100), "A demo application", "./res/Arial.ttf", 40));
    AddElement(menu, new Label(Point(100, 210), "Username", "./res/Arial.ttf", 25));
    AddElement(menu, new Label(Point(100, 310), "Password", "./res/Arial.ttf", 25));

    AddElement(menu, new TextBox(Point(250, 200), Point(500, 250), "./res/Arial.ttf", 25));
    AddElement(menu, new PasswordBox(Point(250, 300), Point(500, 350), "./res/Arial.ttf", 25));
    
    AddElement(menu, new Button(Point(250, 400), Point(500, 450), "Sign in", "./res/Arial.ttf", 25));
    
    AddElement(menu, new CheckBox(Point(270, 470), Allignment::RIGHT, new Label(Point(270, 470), "Remember me", "./res/Arial.ttf", 25)));
    AddElement(menu, new Label(Point(270, 500), "Login with admin / admin", "./res/Arial.ttf", 15));

    if(Converter::getButton(menu->getComponent(5)) != nullptr)
        menu->getComponent(5)->setOnClickAction(demoButton_action);     // <--- Adding a callback to be executed on mouse press
}