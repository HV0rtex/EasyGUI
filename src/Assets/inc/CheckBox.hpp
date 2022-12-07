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
 * @file CheckBox.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the CheckBox class
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <SFML/Graphics/RectangleShape.hpp>
#include <Exceptions/CheckBoxException.hpp>
#include <AlignmentTool.hpp>
#include <Component.hpp>
#include <Logger.hpp>
#include <Point.hpp>

namespace easyGUI
{

class CheckBox : public Component, public Anchor
{
private:
    ::sf::RectangleShape _box, _filler;
    Component* _content;

    char _isChecked;

    virtual void draw(::sf::RenderTarget&, ::sf::RenderStates) const override;

public:
    /**
     * @brief Destructor
     * 
     */
    ~CheckBox();

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param endLocation The location of the bottom-right corner
     * 
     * @param content A component to be bound to the checkbox
     * @param binding How to aling the components
     * 
     * @throw CheckBoxException
     *
     */
    CheckBox(const Point&, const Point&, Component*&, const Binding&);

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param width The width of the button
     * @param height The height of the button
     * 
     * @param content A component to be bound to the checkbox
     * @param binding How to align the components
     * 
     * @throw CheckBoxException
     */
    CheckBox(const Point&, const float&, const float&, Component*&, const Binding&);

    // Block other forms of construction

    CheckBox() = delete;
    CheckBox( const CheckBox& ) = delete;
    CheckBox& operator= ( const CheckBox& ) = delete;

    // ----- Auxiliaries -----

    /**
     * @brief Check if mouse is over the button
     * 
     * @return true Mouse is over the label
     * @return false otherwise
     */
    bool isMouseHover() const override;

    // ----- Getters -----

    /**
     * @brief Returns the SFML RectangleShape
     * 
     * @return ::sf::RectangleShape& 
     */
    ::sf::RectangleShape& getInternalBox();

    /**
     * @brief Returns the filler rectangles
     * 
     * @return ::sf::RectangleShape& 
     */
    ::sf::RectangleShape& getFiller();

    /**
     * @brief Returns the component bound to the checkbox
     * 
     * @return Component&
     */
    Component& getInternalComponent();

    /**
     * @brief Checks if the box has been checked
     * 
     * @return bool
     */
    bool isChecked() const;

    // ----- Methods -----

    /**
     * @brief Updates a component's location
     * 
     * @param newLocation The new location of the component
     */
    void updateLocation(const Point&) override;

    /**
     * @brief Checks / Unchecks the checkbox
     * 
     */
    void onClick() override;

    // ----- Inherited from Anchor -----

    /**
     * @brief Returns the point leftmost of the Anchor
     * 
     * @return Point& 
     */
    Point getLEFT() const override;

    /**
     * @brief Returns the point rightmost of the Anchor
     * 
     * @return Point& 
     */
    Point getRIGHT() const override;

    /**
     * @brief Returns the lowest point of the Anchor
     * 
     * @return Point& 
     */
    Point getBOTTOM() const override;

    /**
     * @brief Returns the highest point of the Anchor
     * 
     * @return Point& 
     */
    Point getTOP() const override;

    /**
     * @brief Returns the point at the center of the Anchor
     * 
     * @return Point& 
     */
    Point getCENTER() const override;
};


}