/**
 * @file Label.hpp
 * @author David Bogdan
 * @brief Definition of the Label class
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <Point.hpp>

namespace egui
{

/**
 * @brief Implements a label component
 * 
 * This class is a wrapper around the sf::Text class, in order
 * to make the implementation of Labels easier for the end-user.
 * 
 * Furthermore, the class provides methods for onClick() and onHover()
 * so that the label can act as a Text-button. For custom labels, you can
 * inherit this class.
 */
class Label : public ::sf::Drawable
{
private:
    ::sf::RenderWindow* _container;

    ::sf::Font _font;
    ::sf::Text _text;
    ::sf::Color _textColor;

    virtual void draw(::sf::RenderTarget& target, ::sf::RenderStates states) const;

    // ----- Initializers -----

    void constructText(const utils::Point& position, const ::std::string& text, const unsigned& charSize);

    // ----- Auxiliaries -----

    /**
     * @brief Check if mouse is over the button
     * 
     * @return true Mouse is over the label
     * @return false otherwise
     */
    bool isMouseHover() const;

public:
    /**
     * @brief Destructor
     * 
     */
    ~Label();

    /**
     * @brief Constructor
     * 
     * @param position The position where the text should be placed.
     * @param text The text to be displayed.
     * @param fontPath The path to the font file.
     * @param charSize The size of the characters.
     * @param color The color of the label.
     * 
     * @note The font file format must be .ttf
     */
    Label(const utils::Point& position, const ::std::string& text, const ::std::string& fontPath, const unsigned& charSize, const sf::Color& color);

    // Block other forms of construction

    Label()= delete;
    Label(const Label& other)= delete;
    Label& operator= (const Label& other)= delete;
};

}