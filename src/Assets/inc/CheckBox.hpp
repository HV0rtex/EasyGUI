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
 * @file CheckBox.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the CheckBox class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <memory>

#include <SFML/Graphics/RectangleShape.hpp>

#include <Exceptions/CheckBoxException.hpp>
#include <AlignmentTool.hpp>
#include <Component.hpp>
#include <Point.hpp>


namespace easyGUI {

#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class ASSETS_EXPORTS CheckBox : public Component, public Anchor
#else
class CheckBox : public Component, public Anchor
#endif
{
 public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~CheckBox() = default;

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param endLocation The location of the bottom-right corner
     * 
     * @throw CheckBoxException
     */
    explicit CheckBox(const Point&,
                      const Point&);

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param width The width of the button
     * @param height The height of the button
     * 
     * @throw CheckBoxException
     */
    explicit CheckBox(const Point&,
                      const float&,
                      const float&);

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

    Point getLEFT() const override;
    Point getRIGHT() const override;
    Point getBOTTOM() const override;
    Point getTOP() const override;
    Point getCENTER() const override;
 private:
    ::sf::RectangleShape _box, _filler;

    uint8_t _isChecked;

    void draw(::sf::RenderTarget&, ::sf::RenderStates) const override;
};

}  // namespace easyGUI
