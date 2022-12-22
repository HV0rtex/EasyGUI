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
 * @file parser.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the parser variable
 * @version 0.1
 * @date 2022-12-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <parser.hpp>

void clearScreen()
{
    #if defined(_WIN32) || defined(WIN32) || defined(__WIN32__) || defined(__NT__)
        if (system("cls")) {}
    #else
        if (system("clear")) {}
    #endif
}

void parseArguments(const int& argc, char** argv, std::string& projName, int& noMenus)
{
    if(argc == 1)
    {
        projName = "INIT";
    }
    else if(argc > 1)
    {
        if(strcmp(argv[1], "--project") == 0)
        {
            projName = std::string(argv[2]);

            if(argc > 3 && strcmp(argv[3], "--menus") == 0)
            {
                noMenus = std::stoi(std::string(argv[4]));
            }
            else if(argc == 3 || (argc > 3 && strcmp(argv[3], "--menus") != 0))
            {
                projName = "ERROR";
            }
        }
        else if(strcmp(argv[1], "--menus") == 0)
        {
            noMenus = std::stoi(argv[2]);

            if(argc > 3 && strcmp(argv[3], "--project") == 0)
            {
                projName = argv[4];
            }
            else if(argc == 3 || (argc > 3 && strcmp(argv[3], "--project") != 0))
            {
                projName = "ERROR";
            }
        }
    }
}
