/**
 * @file AssetException.hpp
 * @author your name (you@domain.com)
 * @brief Definition of the base exception class
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
 * @brief Exception thrown when something goes wrong at Asset level.
 * 
 */
class AssetException : public ::std::exception
{
private:
    ::std::string _msg;

public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~AssetException();

    /**
     * @brief Constructor
     * 
     * @param message The message to be displayed
     */
    AssetException(::std::string message);

    /**
     * @brief Returns the exception message
     * 
     * @return const char* 
     */
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
};

}