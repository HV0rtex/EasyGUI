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

#include <routines.hpp>

bool backButton_trigger (const ::sf::Event& event)
{
    easyGUI::Application* app = nullptr;
    app = app->getInstance();
    
    if(app != nullptr)
    {
        easyGUI::Menu* firstMenu = app->getMenu(1);
    
        if(firstMenu != nullptr && app->getActiveMenu() == firstMenu)
        {
            easyGUI::Component* backButton = firstMenu->getComponent(1);

            if(backButton == nullptr)
            {
                return false;
            }

            return (
                event.type == ::sf::Event::MouseButtonPressed && 
                event.mouseButton.button == ::sf::Mouse::Left &&
                backButton->isMouseHover()
            );
        }
    }
    
    return false;
}

void backButton_action ()
{
    easyGUI::Application* app = nullptr;
    
    app = app->getInstance();

    if(app != nullptr)
    {
        app->setActiveMenu(0);
    }
}