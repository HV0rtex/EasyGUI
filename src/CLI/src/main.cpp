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


#include <iostream>
#include <parser.hpp>
#include <generators.hpp>

int main(int argc, char** argv)
{
    std::string projName = "ERROR";
    int noMenus = 0;

    parseArguments(argc, argv, projName, noMenus);

    if(projName == "ERROR")
        return 1;
    if(projName == "INIT")
    {
        std::string buffer;

        std::cout << ".-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-.\n";
        std::cout << "|                                                                       |\n";
        std::cout << "|                                                                       |\n";
        std::cout << "|                                                                       |\n";
        std::cout << "|                                                                       |\n";
        std::cout << "|                                                                       |\n";
        std::cout << "!                            E A S Y - G U I                            !\n";
        std::cout << ":                          ===================                          :\n";
        std::cout << ":                                                                       :\n";
        std::cout << ".            This tool will help generate some of the project           .\n";
        std::cout << ".                     files for a faster development                    .\n";
        std::cout << ":                                                                       :\n";
        std::cout << ":                                                                       :\n";
        std::cout << "!                                                                       !\n";
        std::cout << "|                                                                       |\n";
        std::cout << "|                - Press any key to start a new project -               |\n";
        std::cout << "|                                                                       |\n";
        std::cout << "|                                                                       |\n";
        std::cout << "|                                                                       |\n";
        std::cout << "`-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-etf-'\n";
    
        std::cin.get();
        
        std::cout << "Type in the name of the project : ";
        std::cin >> projName;

        std::cout << "Type in the number of menus : ";
        std::cin >> noMenus;
    }

    generateMain(projName, noMenus);

    return 0;
}