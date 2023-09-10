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
 * @file generators.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the generator functions
 * @version 0.1
 * @date 2022-12-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <generators.hpp>

#if defined(WIN32)
    #include <windows.h>
#else
    #include <sys/stat.h>
    #include <sys/types.h>
#endif

void createDir(const std::string& path)
{
    #if defined(WIN32)
        CreateDirectory(path.c_str(), NULL);
    #else
        mkdir(path.c_str(), 0777);
    #endif
}

void generateMain(const std::string& projName, const int& noMenus)
{
    createDir(projName);

    generateMainCpp(projName, noMenus);
    generateRoutinesHpp(projName);
    generateMenusHpp(projName, noMenus);

    createDir(projName + "/menus");
    createDir(projName + "/routines");

    generateMenus(projName, noMenus);
    generateWindowHandler(projName);

    createDir(projName + "/menus/buttons");
}