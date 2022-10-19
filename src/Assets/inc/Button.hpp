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
#include <SFML/Graphics/RectangleShape.hpp>
#include <Exceptions/ButtonException.hpp>
#include <Label.hpp>

namespace easyGUI
{

/**
 * @brief Implements a button component
 * 
 * @details Draws a button on a window. The class makes use of the
 * Label class in order to draw and configure the button's text.
 */
class Button : public Component
{
private:
    ::sf::RectangleShape _shape;
    Label* _content;

    virtual void draw( ::sf::RenderTarget&, ::sf::RenderStates ) const;

    // ----- Helper methods -----

    /**
     * @brief Computes the label's starting positon
     * 
     * @param length The length of the label's text
     * @param charSize The size of the characters
     * @return Point 
     */
    Point getLabelPosition( const unsigned&, const unsigned& ) const;

    /**
     * @brief Computes the correction to be applied to the char size of the text
     * 
     * @param textLenght The length of the text
     * @param desiredSize The desired char size
     * @return unsigned
     */
    unsigned getCharSizeCorrection( const unsigned&, const unsigned& ) const;

public:
    /**
     * @brief Destructor
     * 
     */
    ~Button();

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
    Button( const Point&, const Point&, const ::std::string&, const ::std::string&, const unsigned& );

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
    Button( const Point&, const float&, const float&, const ::std::string&, const ::std::string&, const unsigned& );

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
    bool isMouseHover() const;

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
     * @return Label* 
     */
    Label* getInternalText();

    /**
     * @brief Updates a component's location
     * 
     * @param newLocation The new location of the component
     */
    virtual void updateLocation(const Point&);
};

}