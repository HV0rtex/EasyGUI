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
 * @file Button.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the button class
 * 
 * @copyright Copyright (c) 2022
 */

#include <Button.hpp>

namespace easyGUI {

void Button::applyCharSizeCorrection() {
    float lenghtInPix = _content->getInternalText().getGlobalBounds().width;
    float heightInPix = _content->getInternalText().getGlobalBounds().height;

    float freeSpaceX = _shape.getGlobalBounds().width - lenghtInPix;
    float freeSpaceY = _shape.getGlobalBounds().height - heightInPix;

    uint32_t size = _content->getInternalText().getCharacterSize();

    while (freeSpaceX <= 0 || freeSpaceY <= 0) {
        size--;
        _content->getInternalText().setCharacterSize(size);

        lenghtInPix = _content->getInternalText().getGlobalBounds().width;
        heightInPix = _content->getInternalText().getGlobalBounds().height;

        freeSpaceX = _shape.getGlobalBounds().width - lenghtInPix;
        freeSpaceY = _shape.getGlobalBounds().height - heightInPix;
    }
}

Button::Button(const Point& startLocation,
               const Point& endLocation,
               const ::std::string& text,
               const ::std::string& fontPath,
               const uint32_t charSize) {
    _shape.setPosition(startLocation.Xcoord, startLocation.Ycoord);
    _shape.setFillColor(::sf::Color::Black);
    _shape.setOutlineColor(::sf::Color::White);
    _shape.setOutlineThickness(5);
    _shape.setSize(
        ::sf::Vector2f(endLocation.Xcoord - startLocation.Xcoord,
                       endLocation.Ycoord - startLocation.Ycoord));

    try {
        AlignmentTool& tool = AlignmentTool::getInstance();
        _content = ::std::make_shared<Label>(Point(), text, fontPath, charSize);
        applyCharSizeCorrection();

        if (_content->getInternalText().getCharacterSize() < charSize)
            WARN << "[Button] Text has been resized in order to fit.\n";

        Anchor* cast = static_cast<Anchor*>(_content.get());
        tool.createBinding(
            cast,
            this,
            BindingPoint::CENTER,
            BindingPoint::CENTER,
            Point(-1, -7));
    }
    catch (const LabelException& err) {
        ERROR << err.what();

        ButtonException ex("Label text will not be visible.");

        WARN << ex.what();
    }
}

Button::Button(const Point& startLocation,
               const float& width,
               const float& height,
               const ::std::string& text,
               const ::std::string& fontPath,
               const uint32_t charSize):
    Button(startLocation,
           Point(startLocation.Xcoord + width, startLocation.Ycoord + height),
           text,
           fontPath,
           charSize) {}

void Button::draw(::sf::RenderTarget& target,
                  ::sf::RenderStates states) const {
    target.draw(_shape, states);

    if (_content != nullptr)
        target.draw(*_content, states);
}

bool Button::isMouseHover() const {
    if (_container != nullptr) {
        ::sf::Vector2i currentPosition = ::sf::Mouse::getPosition(*_container);
        ::sf::Vector2f worldPos = _container->mapPixelToCoords(currentPosition);

        if (_shape.getGlobalBounds().contains(worldPos.x, worldPos.y))
            return true;
    }

    return false;
}

::sf::RectangleShape& Button::getInternalButton() {
    return _shape;
}

::sf::Text& Button::getInternalText() {
    if (!_content)
        throw ButtonException("Label has not been created.");

    return _content->getInternalText();
}

void Button::updateLocation(const Point& newLocation) {
    _shape.setPosition(newLocation.Xcoord, newLocation.Ycoord);

    AlignmentTool& tool = AlignmentTool::getInstance();
    tool.triggerUpdate(this);
}

Point Button::getLEFT() const {
    return Point(
        _shape.getGlobalBounds().left,
        _shape.getGlobalBounds().top + _shape.getGlobalBounds().height / 2);
}

Point Button::getRIGHT() const {
    return Point(
        _shape.getGlobalBounds().left + _shape.getGlobalBounds().width,
        _shape.getGlobalBounds().top + _shape.getGlobalBounds().height / 2);
}

Point Button::getTOP() const {
    return Point(
        _shape.getGlobalBounds().left + _shape.getGlobalBounds().width / 2,
        _shape.getGlobalBounds().top);
}

Point Button::getBOTTOM() const {
    return Point(
        _shape.getGlobalBounds().left + _shape.getGlobalBounds().width / 2,
        _shape.getGlobalBounds().top + _shape.getGlobalBounds().height);
}

Point Button::getCENTER() const {
    return Point(
        _shape.getGlobalBounds().left + _shape.getGlobalBounds().width / 2,
        _shape.getGlobalBounds().top + _shape.getGlobalBounds().height / 2);
}

}  // namespace easyGUI
