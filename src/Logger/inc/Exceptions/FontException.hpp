/**
 * @file FontException.hpp
 * @author your name (you@domain.com)
 * @brief Definition of the FontException class
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
 * @brief Exception thrown when an error occurs inside the Font Manager.
 * 
 */
class FontException : public AssetException
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~FontException() {}

    /**
     * @brief Constructor
     * 
     * @param message The message to be displayed
     */
    FontException(::std::string message) : AssetException( "[ FontManager ] " + message ) {}
};

}