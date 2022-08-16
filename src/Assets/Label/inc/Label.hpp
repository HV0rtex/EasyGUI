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
    const ::sf::RenderWindow* _container;
    
    void (*_onClickAction)();
    void (*_onHoverAction)();

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
    bool mouseHover() const;

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

    // ----- Interactors -----

    /**
     * @brief Called when the label is pressed.
     * 
     * @param callBack A callback function to be executed on mouse press. Defaults to NULL.
     */
    virtual void onClick();

    /**
     * @brief Called when the mouse is over the label
     * 
     * @param callBack A callback function to be executed when mouse is over the label. Defauts to NULL.
     */
    virtual void onHover();
};

}