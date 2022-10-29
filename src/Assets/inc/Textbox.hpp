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
 * @file Textbox.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the textbox class
 * @version 0.1
 * @date 2022-10-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <Component.hpp>
#include <Manager.hpp>
#include <Exceptions/TextBoxException.hpp>
#include <Point.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

namespace easyGUI
{

/**
 * @brief Models a text box
 * 
 * @details This class provides a means for the end-user to input text and
 * enables the creation of forms (e.g. Login forms). The class provides methods
 * to access both the border and the text.
 * 
 */
class TextBox : public Component
{
protected:
    ::sf::RectangleShape _shape;
    ::sf::Text _text;
    ::std::shared_ptr <::sf::Font> _font;

    unsigned desiredSize;
    
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
    static TextBox* selectedBox;
    static bool textBoxClicked;

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param endLocation The location of the bottom-right corner
     *
     * @param fontPath The path to the font file
     * 
     * @param charSize The size of the characters
    
     * @throw TextBoxException
     * 
     * @note The font file format must be .ttf

     */
    TextBox( const Point&, const Point&, const ::std::string&, const unsigned& );

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param width The width of the button
     * @param height The height of the button
     * 
     * @param fontPath The path to the font file
     * 
     * @param charSize The size of the characters
     *
     * @throw TextBoxException
     * 
     * @note The font file format must be .ttf
     */
    TextBox( const Point&, const float&, const float&, const ::std::string&, const unsigned& );

    // Block other forms of construction

    TextBox() = delete;
    TextBox( const TextBox& ) = delete;
    TextBox& operator= ( const TextBox& ) = delete;

    // ----- Auxiliaries -----

    /**
     * @brief Check if mouse is over the button
     * 
     * @return true Mouse is over the label
     * @return false otherwise
     */
    bool isMouseHover() const;

    /**
     * @brief Updates the text of the keyboard
     * 
     * @param text The text that has been entered
     */
    virtual void updateText( const ::sf::Uint32& );

    // ----- Getters -----

    /**
     * @brief Returns the SFML RectangleShape
     * 
     * @return ::sf::RectangleShape& 
     */
    ::sf::RectangleShape& getInternalBox();

    /**
     * @brief Returns the SFML Text
     * 
     * @return ::sf::Text& 
     */
    ::sf::Text& getInternalText();

    /**
     * @brief Returns a string containing the text in the box
     * 
     * @return const ::std::string 
     */
    virtual const ::std::string getText() const;

    /**
     * @brief Erases all text from a textbox
     * 
     */
    void clear();

    /**
     * @brief Updates the selected text box
     * 
     */
    void onClick();

    /**
     * @brief Updates a component's location
     * 
     * @param newLocation The new location of the component
     */
    virtual void updateLocation( const Point& );

    /**
     * @brief Scales a component 
     * 
     * @param factorX The X factor
     * @param factorY The Y factor
     */
    void scale( const float&, const float& ) {}

};

}