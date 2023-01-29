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

void createSecondMenu(ApplicationPtr& appInst)
{
    if(appInst == nullptr)
        // Throw exception if application has not been created
        throw MenuException("Could not get hold of application instance.");
    
    MenuPtr menu = appInst->addMenu("second");   // <--- Adding a regular menu

    if(menu == nullptr)
        // Throw exception if menu could not be created
        throw MenuException("Could not create menu.");

    AddElement<Label>(menu, "title", Point(220, 100), "A second menu", "./res/Arial.ttf", 40);
    AddElement<Button>(menu, "back", Point(50, 200), Point(250, 250), "Go back", "./res/Arial.ttf", 25);
    
    AddElement<Image>(menu, "img",
            Point(200, 300),        // <--- Top left corner
            Point(250, 350),        // <--- Bottom right corner 
            "./res/image.jpeg"      // <--- Path to image file
    );
    
    if(Converter::getButton(menu->getComponent("back")) != nullptr)
        menu->getComponent("back")->setOnClickAction(backButton_action);
}