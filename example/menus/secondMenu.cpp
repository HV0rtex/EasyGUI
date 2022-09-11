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

void createSecondMenu(easyGUI::Application* appInst)
{
    if(appInst != nullptr)
    {
        easyGUI::Menu* menu = appInst->addMenu();

        if(menu == nullptr)
        {
            throw std::exception();
        }

        try
        {
            menu->addComponent( 
                new easyGUI::Label( 
                    easyGUI::Point(220, 100),
                    
                    "A second menu", 
                    "./res/Arial.ttf", 
                    
                    40, 
                    
                    sf::Color(255,255,255) 
                ) 
            );
            
            menu->addComponent( 
                new easyGUI::Button( 
                    easyGUI::Point(50, 200),
                    easyGUI::Point(250,250), 

                    ::sf::Color::Black, 
                    ::sf::Color::White, 
                    ::sf::Color::White, 
                    
                    "Go back", 
                    "./res/Arial.ttf", 
                    
                    25, 5
                )
            );
        }
        catch(...)
        {
            throw std::exception();
        }
    }
}