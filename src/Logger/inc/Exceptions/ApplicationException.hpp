/**
 * @file ApplicationException.hpp
 * @author your name (you@domain.com)
 * @brief Definition of the ApplicationException base class
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <exception>
#include <string>

namespace easyGUI
{

/**
 * @brief Exception thrown when something goes wrong at Application level.
 * 
 */
class ApplicationException : public ::std::exception
{
private:
    ::std::string _msg;

public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~ApplicationException();

    /**
     * @brief Constructor
     * 
     * @param message The message to be displayed
     */
    ApplicationException(::std::string message);

    /**
     * @brief Returns the exception message
     * 
     * @return const char* 
     */
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;     
};

}