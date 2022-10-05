/**
 * @file AssetException.hpp
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
AssetException::AssetException(::std::string message)
{
    _msg = "[ Asset ]";
    _msg += message;
}

const char* AssetException::what() const
{
    return _msg.c_str();
}

}