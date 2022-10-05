/**
 * @file MenuException.hpp
 * @author your name (you@domain.com)
 * @brief Definition of the MenuException class
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <Exceptions/ApplicationException.hpp>

namespace easyGUI
{

/**
 * @brief Exception thrown when an error occurs with a Menu.
 * 
 */
class MenuException : public ApplicationException
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~MenuException() {}

    /**
     * @brief Constructor
     * 
     * @param message The message to be displayed
     */
    MenuException(::std::string message) : ApplicationException( "[ Menu ] " + message ) {}
};

}