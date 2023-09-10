// Copyright © 2022 David Bogdan

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the “Software”), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do
// so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial
// portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
// LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
// SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


/**
 * @file fileGenerators.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the file generator functions
 * @version 0.1
 * @date 2022-12-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <generators.hpp>
#include <fstream>

void generateMainCpp(const std::string& projName, const int& noMenus)
{
    std::ofstream fout;

    fout.open(projName + "/main.cpp");
    fout << "#include \"routines.hpp\"\n";
    fout << "#include \"menus.hpp\"\n";
    fout << "\n";
    fout << "using namespace easyGUI;\n";
    fout << "using namespace std;\n";
    fout << "\n";
    fout << "int main (int argc, char** argv)\n";
    fout << "{\n";
    fout << "\t// Setting application parameters\n";
    fout << "\tunsigned appWidth = 800;\n";
    fout << "\tunsigned appHeight = 800;\n";
    fout << "\tstring appTitle = \"" << projName << "\";\n";
    fout << "\n";
    fout << "\t// Declaring application object\n";
    fout << "\tApplication* app = app->getInstance(appWidth, appHeight, appTitle.c_str());\n";
    fout << "\n";
    fout << "\t// Creating routines\n";
    fout << "\tRoutine windowHandler(windowHandler_trigger, windowHandler_action);\n";
    fout << "\n";
    fout << "\t// Adding routines to application\n";
    fout << "\tapp->addRoutine(&windowHandler);\n";
    fout << "\n";
    fout << "\ttry\n";
    fout << "\t{\n";
    fout << "\t\t// Creating menus\n";

    for (int i = 0; i < noMenus; i++)
    {
        std::string command = "\t\tcreateMenu" + std::to_string(i) + "(app);\n";
    }

    fout << "\n";
    fout << "\t\t// Starting the application\n";
    fout << "\t\tapp->start();\n";
    fout << "\t}\n";
    fout << "\tcatch(const ApplicationException& err)\n";
    fout << "\t{\n";
    fout << "\t\tERROR << err.what();\n";
    fout << "\n";
    fout << "\t\treturn 1;\n";
    fout << "\t}\n";
    fout << "\n";
    fout << "\treturn 0;\n";
    fout << "}\n";

    fout.close();
}

void generateRoutinesHpp(const std::string& projName)
{
    std::ofstream fout(projName + "/routines.hpp");

    fout << "\n";
    fout << "#pragma once\n";
    fout << "\n";
    fout << "// Including dependencies\n";
    fout << "#include <EasyGUI/Routine.hpp>\n";
    fout << "#include <EasyGUI/Application.hpp>\n";
    fout << "\n";
    fout << "// Defining routine triggers\n";
    fout << "bool windowHandler_trigger(const sf::Event& event);\n";
    fout << "\n";
    fout << "// Defining routine actions\n";
    fout << "void windowHandler_action();\n";

    fout.close();
}

void generateMenusHpp(const std::string& projName, const int& noMenus)
{
    std::ofstream fout(projName + "/menus.hpp");

    fout << "\n";
    fout << "#pragma once\n";
    fout << "\n";
    fout << "// Including dependencies\n";
    fout << "#include <EasyGUI/Application.hpp>\n";
    fout << "#include <EasyGUI/Menu.hpp>\n";
    fout << "\n";
    fout << "// Defining functions to create menus";
    
    for (int i = 0; i < noMenus; i++)
    {
        fout << "void generateMenu" << i << "(easyGUI::Application* app);\n";
    }

    fout.close();
}

void generateMenus(const std::string& projName, const int& noMenus)
{
    std::ofstream fout(projName + "/menu/buttons.hpp");

    fout << "\n";
    fout << "#pragma once\n";
    fout << "\n";
    fout << "//Including dependencies\n";
    fout << "\n";
    fout << "// --- Define button action functions here ---\n";

    fout.close();

    for (int i = 0; i < noMenus; i++)
    {
        fout.open(projName + "/menus/Menu" + std::to_string(i) + ".cpp");

        fout << "\n";
        fout << "#include \"../menus.hpp\"\n";
        fout << "#include \"buttons.hpp\"\n";
        fout << "\n";
        fout << "using namespace easyGUI;\n";
        fout << "\n";
        fout << "void generateMenu" << i << "(Application* app)\n";
        fout << "{\n";
        fout << "\tif (app == nullptr)\n";
        fout << "\t\tthrow MenuException(\"App has not been created.\");\n";
        fout << "\n";

        if(i != 0)
            fout << "\tMenu* menu = app->addMenu(\"menu" << i << "\");\n";
        else
            fout << "\tMenu* menu = app->addMenu(\"menu0\", true);\n";
        
        fout << "\n";
        fout << "\tif (menu == nullptr)\n";
        fout << "\t\tthrow MenuException(\"Could not create menu\");\n";
        fout << "\n";
        fout << "}\n";

        fout.close();
    }
}

void generateWindowHandler(const std::string& projName)
{
    std::ofstream fout(projName + "/routines/windowHandler.cpp");

    fout << "\n";
    fout << "#include \"../routines.hpp\"\n";
    fout << "\n";
    fout << "bool windowHandler_trigger(const sf::Event& event)\n";
    fout << "{\n";
    fout << "\treturn (event == sf::Event::Closed);\n";
    fout << "}\n";
    fout << "\n";
    fout << "void windowHandler_action()\n";
    fout << "{\n";
    fout << "\tApplication* app = app->getInstance();\n";
    fout << "\n";
    fout << "\tif (app != nullptr)\n";
    fout << "\t\tapp->stop();\n";
    fout << "}\n";

    fout.close();
}