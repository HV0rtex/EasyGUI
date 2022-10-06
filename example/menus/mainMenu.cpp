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

void createMainMenu(easyGUI::Application* appInstance)
{
    if(appInstance == nullptr)
        // Raise error if application has not been created
        throw easyGUI::MenuException("Could not get hold of application instance.");

    easyGUI::Menu* menu = appInstance->addMenu(true);   // Adds a new MAIN menu

    if(menu == nullptr)
        // Raise error if creating a menu fails
        throw easyGUI::MenuException("Could not create menu.");

    try
    {
        menu->addComponent( 
            new easyGUI::Label(             // <--- Label component
                easyGUI::Point(220, 100),   // <--- Starting location
                
                "A demo application",       // <--- Label text
                "./res/Arial2.ttf",          // <--- Text font path
                
                40,                         // <--- Desired character size
                
                sf::Color(255,255,255)      // <--- Text color
            ) 
        );
        
        menu->addComponent( 
            new easyGUI::Button(            // <--- Button component
                easyGUI::Point(50, 200),    // <--- Starting location
                easyGUI::Point(250,250),    // <--- Ending location

                ::sf::Color::Black,         // <--- Fill color
                ::sf::Color::White,         // <--- Outline color
                ::sf::Color::White,         // <--- Text color
                
                "Demo button",              // <--- Button text
                "./res/Arial.ttf",          // <--- Text font path
                
                55,                         // <--- Desired character size 
                5                           // <--- Outline thickness
            )
        );

        menu->addComponent( 
            new easyGUI::Button( 
                easyGUI::Point(50, 275),
                easyGUI::Point(250,325), 

                ::sf::Color::Black, 
                ::sf::Color::White, 
                ::sf::Color::White, 
                
                "Exit", 
                "./res/Arial.ttf", 
                
                25, 5
            )
        );

        menu->getComponent(1)->setOnClickAction(demoButton_action);     // <--- Adding a callback to be executed on mouse press
        menu->getComponent(2)->setOnClickAction(exitButton_action);
    }
    catch(const easyGUI::AssetException& err)
    {
        // Throw error if couldn't add components
        ERROR << err.what();
    }
}