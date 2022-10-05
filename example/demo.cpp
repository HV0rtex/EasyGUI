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
#include <menus.hpp>

using namespace easyGUI;

// Setting application parameters
unsigned appWidth = 800;
unsigned appHeight = 600;
std::string appTitle = "Demo app";

// Declaring application object
Application* app = nullptr;

int main()
{
    // Creating application
    app = app->getInstance(appWidth, appHeight, appTitle.c_str());

    // Creating routines
    Routine windowHandler(windowHandler_trigger, windowHandler_action);
    
    // Adding routine to app
    app->addRoutine(&windowHandler);

    try
    {
        // Creating menus
        createMainMenu(app);
        createSecondMenu(app);

        // Starting the application
        app->start();
    }
    catch(const ApplicationException* err)
    {
        ERROR << err->what();

        return 1;
    }
    
    return 0;
}