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
#include <FontManager.hpp>
#include <Exceptions/TextBoxException.hpp>
#include <Point.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

namespace easyGUI
{

class TextBox : public Component
{
private:
    ::sf::RectangleShape _shape;
    ::sf::Text _text;
    ::std::shared_ptr <::sf::Font> _font;

    unsigned desiredSize;
    
    virtual void draw(::sf::RenderTarget& target, ::sf::RenderStates states) const;

    // ----- Helper methods -----

    /**
     * @brief Computes the label's starting positon
     * 
     * @param length The length of the label's text
     * @param charSize The size of the characters
     * @return Point 
     */
    Point getLabelPosition(const unsigned& length, const unsigned& charSize) const;

    /**
     * @brief Computes the correction to be applied to the char size of the text
     * 
     * @param textLenght The length of the text
     * @param desiredSize The desired char size
     * @return unsigned
     */
    unsigned getCharSizeCorrection(const unsigned& textLenght, const unsigned& desiredSize) const;

    // ----- Initializers -----

    void constructText(const Point& position, const ::std::string& text, const unsigned& charSize, ::sf::Color textColor);

public:
    static TextBox* selectedBox;

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param endLocation The location of the bottom-right corner
     * @param fillColor The color of the button background
     * @param outlineColor The color of the button border
     * @param textColor The color of the text
     * 
     * @param text The button's text
     * @param fontPath The path to the font file
     * 
     * @param charSize The size of the characters
     * @param thickness The thickness of the outline
     * 
     * @throw ::std::invalid_argument Invalid font path
     * 
     * @note The font file format must be .ttf

     */
    TextBox(
        const Point& startLocation,
        const Point& endLocation,

        const ::sf::Color& fillColor,
        const ::sf::Color& outlineColor,
        const ::sf::Color& textColor,

        const ::std::string& text,
        const ::std::string& fontPath,

        const unsigned& charSize,
        const unsigned& thickness
    );

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param width The width of the button
     * @param height The height of the button
     * @param fillColor The color of the button background
     * @param outlineColor The color of the button border
     * @param textColor The color of the text
     * 
     * @param text The button's text
     * @param fontPath The path to the font file
     * 
     * @param charSize The size of the characters
     * @param thickness The thickness of the outline
     * 
     * @throw ::std::invalid_argument Invalid font path
     * 
     * @note The font file format must be .ttf
     */
    TextBox(
        const Point& startLocation,
        const unsigned& width,
        const unsigned& height,

        const ::sf::Color& fillColor,
        const ::sf::Color& outlineColor,
        const ::sf::Color& textColor,

        const ::std::string& text,
        const ::std::string& fontPath,

        const unsigned& charSize,
        const unsigned& thickness
    );

    // Block other forms of construction

    TextBox()= delete;
    TextBox(const TextBox& other)= delete;
    TextBox& operator= (const TextBox& other)= delete;

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
     * @details This component uses ::sf::Event because there are two types of events which can cause text updates.
     * The first one is TextEntered (when text is added) and second one is KeyPressed (when text is removed if the key
     * being pressed is backspace).
     * 
     * @param event The event which triggered the update
     */
    void updateText(const ::sf::Event& event);

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
     * @brief Updates the selected text box
     * 
     */
    void onClick();
};

}