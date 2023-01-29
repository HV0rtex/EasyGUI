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

void createMainMenu(ApplicationPtr& appInstance)
{
    if(appInstance == nullptr)
        // Raise error if application has not been created
        throw MenuException("Could not get hold of application instance.");

    MenuPtr menu = appInstance->addMenu("mainMenu", true);   // Adds a new MAIN menu

    AddElement<Label>(menu, "title",
            Point(220, 100),        // <--- The position of the component
            "A demo application",   // <--- The text of the label
            "./res/Arial.ttf",      // <--- The font of the label
            40                      // <--- Desired character size
    );

    AddElement<Label>(menu, "uNameLabel", Point(100, 210), "Username", "./res/Arial.ttf", 25);
    AddElement<Label>(menu, "passLabel", Point(100, 310), "Password", "./res/Arial.ttf", 25);
    AddElement<Label>(menu, "hint", Point(270, 500), "Login with admin / admin", "./res/Arial.ttf", 15);

    AddElement<TextBox>(menu, "uname", 
            Point(250, 200),        // <--- Tpp-left corner of the box
            Point(500, 250),        // <--- Bottom-right corner of the box
            "./res/Arial.ttf",      // <--- Font of the text
            25                      // <--- Desired character size
    );
    
    AddElement<PasswordBox>(menu, "pass", Point(250, 300), Point(500, 350), "./res/Arial.ttf", 25);
    
    AddElement<Button>(menu, "submit",
            Point(250, 400),        // <--- The top-left of the button
            Point(500, 450),        // <--- The bottom-right corner of the button
            "Sign in",              // <--- The text of the button
            "./res/Arial.ttf",      // <--- The font of the text
            25                      // <--- Desired character size
    );
     
    if(Converter::getButton(menu->getComponent("submit")) != nullptr)
        menu->getComponent("submit")->setOnClickAction(demoButton_action);     // <--- Adding a callback to be executed on mouse press
}