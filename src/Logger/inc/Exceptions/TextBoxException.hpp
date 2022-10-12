/**
 * @file TextBoxException.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the TextBoxException class
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <Exceptions/AssetException.hpp>

namespace easyGUI
{

/**
 * @brief Exception thrown when an error occurs inside the TextBox.
 * 
 */
class TextBoxException : public AssetException
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~TextBoxException() {}

    /**
     * @brief Constructor
     * 
     * @param message The message to be displayed
     */
    TextBoxException(::std::string message) : AssetException( "[ TextBox ] " + message ) {}
};

}