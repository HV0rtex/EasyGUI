/**
 * @file ApplicationException.cpp
 * @author your name (you@domain.com)
 * @brief Implementation of the ApplicationException class
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Exceptions/ApplicationException.hpp>

namespace easyGUI
{

ApplicationException::~ApplicationException() {}
ApplicationException::ApplicationException(::std::string message) : ::std::exception()
{
    _msg = "[ Application ] ";
    _msg += message;
    _msg += "\n";
}

const char* ApplicationException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return _msg.c_str();
}

}