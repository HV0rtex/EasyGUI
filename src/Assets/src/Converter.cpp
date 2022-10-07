/**
 * @file Converter.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Converter class
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Converter.hpp>

namespace easyGUI
{

Button* Converter::getButton(Component* asset)
{
    if(asset == nullptr)
        return nullptr;

    return dynamic_cast<Button*>(asset);
}

Label* Converter::getLabel(Component* asset)
{
    if(asset == nullptr)
        return nullptr;

    return dynamic_cast<Label*>(asset);
}

}