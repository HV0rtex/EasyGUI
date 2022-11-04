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
 * @brief Definition of the Check Box class
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <SFML/Graphics/RectangleShape.hpp>
#include <Component.hpp>
#include <Point.hpp>

namespace easyGUI
{

/**
 * @brief Defines enums for component alignment to improve code clarity.
 * 
 */
enum Allignment
{
    TOP,
    BOTTOM,
    LEFT,
    RIGHT
};

/**
 * @brief Emulates a check box. 
 * 
 * @details The box contains a sf::RectangleShape (box) which can be checked
 * as well as an aditional component to be displayed next to the box. The component
 * can be alligned ABOVE / BELOW / LEFT / RIGHT the checkbox and cannot be interacted with.
 * Because of this, the component will have the OnClick() and OnHover() methods suppressed.
 * 
 */
class CheckBox : public Component
{

private:
    ::sf::RectangleShape _box;
    ::sf::RectangleShape _filler;

    Component* _component;
    Allignment _allignment;

    bool _checked;

    virtual void draw (::sf::RenderTarget&, ::sf::RenderStates) const override;

    /**
     * @brief Alligns the component next to the checkbox.
     * 
     * @param startLocation The location of the checkbox
     */
    void allignComponent(const Point&);

public:
    /**
     * @brief Destructor
     * 
     */
    ~CheckBox();

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the text box
     * @param allignment Denotes how to align the element in respect to the checkbox
     * @param content The content of the checkbox. Defaults to NULL.
     */
    explicit CheckBox(const Point&, const Allignment&, Component* = nullptr);

    // ----- Auxiliaries -----

    /**
     * @brief Adds a component to the checkbox in respect
     * to the defined allignment
     * 
     * @param element The component to be alligned next to the textbox
     */
    void addComponent(Component*);

    /**
     * @brief Check if mouse is over the button
     * 
     * @return true Mouse is over the label
     * @return false otherwise
     */
    bool isMouseHover() const override;

    /**
     * @brief Updates the selected text box
     * 
     */
    void onClick() override;

    /**
     * @brief Updates a component's location
     * 
     * @param newLocation The new location of the component
     */
    virtual void updateLocation(const Point&) override;

    // ----- Getters -----

    /**
     * @brief Returns if the checkbox has been checked
     * 
     * @return true 
     * @return false 
     */
    bool isChecked() const;
};

}
