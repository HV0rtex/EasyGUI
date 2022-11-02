// Copyright © 2022 David Bogdan

// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files 
// (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, 
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do 
// so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE 
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


/**
 * @file Image.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Image class
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Image.hpp>

namespace easyGUI
{

void Image::draw(::sf::RenderTarget& target, ::sf::RenderStates states) const
{
    if(_object.getTexture() != nullptr)
        target.draw(_object, states);
}

Image::Image(const Point& startLocation, const Point& endLocation, const ::std::string& path)
{
    TextureManager* manager = TextureManager::getInstance();

    if(manager == nullptr)
    {
        throw ImageException("Could not get hold of Manager asset");
    }

    try
    {
        _image = manager->getAsset(path);

        _object.setTexture(*_image.get());
        _object.setPosition(startLocation.Xcoord, startLocation.Ycoord);
        
        float factorX = (startLocation.Xcoord + _object.getTextureRect().width) / endLocation.Xcoord;
        float factorY = (startLocation.Ycoord + _object.getTextureRect().height) / endLocation.Ycoord;

        _object.setScale(::sf::Vector2f(1 / factorX, 1 / factorY));
    }
    catch(const ManagerException& err)
    {
        ERROR << err.what();

        throw ImageException("Could not load image from file");
    }
}

Image::Image(const Point& startLocation, const float& width, const float& height, const std::string& path) :
    Image(startLocation, Point(startLocation.Xcoord + width, startLocation.Ycoord + height), path) {}

bool Image::isMouseHover() const
{
    if(_container != nullptr)
    {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);

        if(_object.getGlobalBounds().contains(currentPosition.x, currentPosition.y))
            return true;
    }

    return false;
}

void Image::updateLocation(const Point& newLocation)
{
    _object.setPosition(newLocation.Xcoord, newLocation.Ycoord);
}

}