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
 * @file Button.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Button class
 * @version 0.1
 * @date 2022-09-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <SFML/Graphics/RectangleShape.hpp>
#include <Exceptions/ButtonException.hpp>
#include <AlignmentTool.hpp>
#include <Label.hpp>

namespace easyGUI
{

/**
 * @brief Implements a button component
 * 
 * @details Draws a button on a window. The class makes use of the
 * Label class in order to draw and configure the button's text.
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class ASSETS_EXPORTS Button : public Component, public Anchor
#else
class Button : public Component, public Anchor
#endif
{
private:
    ::sf::RectangleShape _shape;
    ::std::shared_ptr<Label> _content;

    virtual void draw(::sf::RenderTarget&, ::sf::RenderStates) const override;

    // ----- Helper methods -----

    /**
     * @brief Computes the correction to be applied to the char size of the text
     * 
     * @param textLenght The length of the text
     * @param desiredSize The desired char size
     * 
     * @return unsigned
     */
    unsigned getCharSizeCorrection(const unsigned&, const unsigned&) const;

public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Button() = default;

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param endLocation The location of the bottom-right corner
     *
     * @param text The button's text
     * @param fontPath The path to the font file
     * 
     * @param charSize The size of the characters
     * 
     * @throw ButtonException
     * 
     * @note The font file format must be .ttf

     */
    Button(const Point&, const Point&, const ::std::string&, const ::std::string&, unsigned);

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param width The width of the button
     * @param height The height of the button
     * 
     * @param text The button's text
     * @param fontPath The path to the font file
     * 
     * @param charSize The size of the characters
     * 
     * @throw ButtonException
     * 
     * @note The font file format must be .ttf
     */
    Button(const Point&, const float&, const float&, const ::std::string&, const ::std::string&, unsigned);

    // Block other forms of construction

    Button() = delete;
    Button( const Button& ) = delete;
    Button& operator= ( const Button& ) = delete;

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
    ::sf::RectangleShape& getInternalButton();

    /**
     * @brief Returns the button's text
     * 
     * @return ::sf::Text&
     */
    ::sf::Text& getInternalText();

    /**
     * @brief Updates a component's location
     * 
     * @param newLocation The new location of the component
     */
    void updateLocation(const Point&) override;

    // ----- Inherited from Anchor -----

    Point getLEFT() const override;
    Point getRIGHT() const override;
    Point getBOTTOM() const override;
    Point getTOP() const override;
    Point getCENTER() const override;
};

}