/**
 * @file LabelException.hpp
 * @author your name (you@domain.com)
 * @brief Definition of the LabelException class
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
 * @brief Exception thrown when an error occurs inside a Label.
 * 
 */
class LabelException : public AssetException
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~LabelException() {}

    /**
     * @brief Constructor
     * 
     * @param message The message to be displayed
     */
    LabelException(::std::string message) : AssetException( "[ Label ] " + message ) {}
};

}