/**
 * @file ButtonException.hpp
 * @author your name (you@domain.com)
 * @brief Definition of the ButtonException class
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
 * @brief Exception thrown when an error occurs inside the Button.
 * 
 */
class ButtonException : public AssetException
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~ButtonException() {}

    /**
     * @brief Constructor
     * 
     * @param message The message to be displayed
     */
    ButtonException(::std::string message) : AssetException( "[ Button ] " + message ) {}
};

}