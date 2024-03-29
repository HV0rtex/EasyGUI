// Copyright © 2022 David Bogdan

// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files
// (the “Software”), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the following
// conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/**
 * @file Image.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Image class
 * 
 * @copyright Copyright (c) 2022
 */

#include <Image.hpp>

namespace easyGUI {

void Image::draw(::sf::RenderTarget& target,
                 ::sf::RenderStates states) const {
    if (_object.getTexture() != nullptr)
        target.draw(_object, states);

    if (_border)
        target.draw(*_border, states);
}

Image::Image(const Point& startLocation,
             const Point& endLocation,
             const ::std::string& path) {
    TextureManager& manager = TextureManager::getInstance();

    try {
        _image = manager.getAsset(path);

        _object.setTexture(*_image.get());
        _object.setPosition(startLocation.Xcoord, startLocation.Ycoord);

        const float factorX = _object.getTextureRect().width /
            (endLocation.Xcoord - startLocation.Xcoord);
        const float factorY = _object.getTextureRect().height /
            (endLocation.Ycoord - startLocation.Ycoord);

        _object.setScale(::sf::Vector2f(1 / factorX, 1 / factorY));
    }
    catch(const ManagerException& err) {
        ERROR << err.what();

        throw ImageException("Could not load image from file");
    }
}

Image::Image(const Point& startLocation,
             const float& width,
             const float& height,
             const std::string& path) :
    Image(startLocation,
          Point(startLocation.Xcoord + width, startLocation.Ycoord + height),
          path) {}

bool Image::isMouseHover() const {
    if (_container != nullptr) {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);
        ::sf::Vector2f worldPos = _container->mapPixelToCoords(currentPosition);

        if (_object.getGlobalBounds().contains(worldPos.x, worldPos.y))
            return true;
    }

    return false;
}

void Image::constructFrame(const uint32_t thickness) {
    _border = ::std::make_shared<::sf::RectangleShape>();

    _border->setPosition(_object.getPosition().x, _object.getPosition().y);
    _border->setOutlineColor(::sf::Color::White);
    _border->setOutlineThickness(thickness);

    const float width =
        _object.getTextureRect().width * _object.getScale().x;
    const float height =
        _object.getTextureRect().height * _object.getScale().y;

    _border->setSize(::sf::Vector2f(width, height));
}

void Image::toggleFrame(const uint32_t thickness) {
    if (_border)
        _border.reset();
    else
        constructFrame(thickness);
}

void Image::updateLocation(const Point& newLocation) {
    _object.setPosition(newLocation.Xcoord, newLocation.Ycoord);

    AlignmentTool& tool = AlignmentTool::getInstance();
    tool.triggerUpdate(this);
}

Point Image::getLEFT() const {
    return Point(
        _object.getGlobalBounds().left,
        _object.getGlobalBounds().top + _object.getGlobalBounds().height / 2);
}

Point Image::getRIGHT() const {
    return Point(
        _object.getGlobalBounds().left + _object.getGlobalBounds().width,
        _object.getGlobalBounds().top + _object.getGlobalBounds().height / 2);
}

Point Image::getTOP() const {
    return Point(
        _object.getGlobalBounds().left + _object.getGlobalBounds().width / 2,
        _object.getGlobalBounds().top);
}

Point Image::getBOTTOM() const {
    return Point(
        _object.getGlobalBounds().left + _object.getGlobalBounds().width / 2,
        _object.getGlobalBounds().top + _object.getGlobalBounds().height);
}

Point Image::getCENTER() const {
    return Point(
        _object.getGlobalBounds().left + _object.getGlobalBounds().width / 2,
        _object.getGlobalBounds().top + _object.getGlobalBounds().height / 2);
}

}  // namespace easyGUI
