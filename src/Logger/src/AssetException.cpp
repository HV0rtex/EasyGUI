/**
 * @file AssetException.cpp
 * @author your name (you@domain.com)
 * @brief Implementation of the AssetException class
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Exceptions/AssetException.hpp>

namespace easyGUI
{

AssetException::~AssetException() {}
AssetException::AssetException(::std::string message) : ::std::exception()
{
    _msg = "[ Asset ]";
    _msg += message;
    _msg += "\n";
}

const char* AssetException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
{
    return _msg.c_str();
}

}