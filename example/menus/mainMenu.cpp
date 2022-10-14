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
                "./res/Arial.ttf",          // <--- Text font path
                
                40,                         // <--- Desired character size
                
                sf::Color(255,255,255)      // <--- Text color
            ) 
        );
        
        menu->addComponent( 
            new easyGUI::Label(
                easyGUI::Point(100, 210),
                
                "Username",
                "./res/Arial.ttf",
                
                25,
                
                sf::Color(255,255,255)
            ) 
        );

        menu->addComponent( 
            new easyGUI::Label(
                easyGUI::Point(100, 310),
                
                "Password",
                "./res/Arial.ttf",
                
                25,
                
                sf::Color(255,255,255)
            ) 
        );

        menu->addComponent(
            new easyGUI::TextBox(
                easyGUI::Point(250, 200),   // <--- Top-left corner
                easyGUI::Point(500, 250),   // <--- Bottom-right corner

                ::sf::Color::Black,         // <--- Fill color
                ::sf::Color::White,         // <--- Outline color
                ::sf::Color::White,         // <--- Text color
                
                "./res/Arial.ttf",          // <--- Text font path
                
                25,                         // <--- Desired character size 
                5                           // <--- Outline thickness    
            )
        );

        menu->addComponent(
            new easyGUI::PasswordBox(
                easyGUI::Point(250, 300),   // <--- Top-left corner
                easyGUI::Point(500, 350),   // <--- Bottom-right corner

                ::sf::Color::Black,         // <--- Fill color
                ::sf::Color::White,         // <--- Outline color
                ::sf::Color::White,         // <--- Text color
                
                "./res/Arial.ttf",          // <--- Text font path
                
                25,                         // <--- Desired character size 
                5                           // <--- Outline thickness    
            )
        );

        menu->addComponent( 
            new easyGUI::Button(            // <--- Button component
                easyGUI::Point(250, 400),   // <--- Starting location
                easyGUI::Point(500,450),    // <--- Ending location

                ::sf::Color::Black,         // <--- Fill color
                ::sf::Color::White,         // <--- Outline color
                ::sf::Color::White,         // <--- Text color
                
                "Sign in",                  // <--- Button text
                "./res/Arial.ttf",          // <--- Text font path
                
                25,                         // <--- Desired character size 
                5                           // <--- Outline thickness
            )
        );

        menu->addComponent( 
            new easyGUI::Label(
                easyGUI::Point(270, 470),
                
                "Login with admin / admin",
                "./res/Arial.ttf",
                
                15,
                
                sf::Color(255,255,255)
            ) 
        );

        menu->getComponent(5)->setOnClickAction(demoButton_action);     // <--- Adding a callback to be executed on mouse press
    }
    catch(const easyGUI::AssetException& err)
    {
        // Throw error if couldn't add components
        ERROR << err.what();
    }
}