/**
 * @file Converter.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the converter class
 * @version 0.1
 * @date 2022-10-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <Button.hpp>
#include <PasswordBox.hpp>

namespace easyGUI
{

/**
 * @brief Responsible for conversions between components
 * 
 */
class Converter
{
public:
    /**
     * @brief Converts a Component object into a button
     * 
     * @param asset The component to be converted
     * 
     * @return Button* 
     * @retval nullptr Asset could not be converted
     */
    static Button* getButton(Component* asset);

    /**
     * @brief Converts a Component object into a label
     * 
     * @param asset The component to be converted
     * 
     * @return Label* 
     * @retval nullptr Asset could not be converted
     */
    static Label* getLabel(Component* asset);

    /**
     * @brief Converts a component into a textbox
     * 
     * @param asset The component to be converted
     * 
     * @return Textbox* 
     * @retval nullptr Asset could not be converted.
     */
    static TextBox* getTextbox(Component* asset);

    /**
     * @brief Converts a component into a password box
     * 
     * @param asset The component to be converted
     * 
     * @return PasswordBox* 
     * @retval nullptr Asset could not be converted.
     */
    static TextBox* getPasswordBox(Component* asset);

};

}