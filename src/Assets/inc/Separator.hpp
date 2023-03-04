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
 * @file Separator.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Separator class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <SFML/Graphics/RectangleShape.hpp>
#include <Exceptions/AssetException.hpp>
#include <AlignmentTool.hpp>

namespace easyGUI
{

/**
 * @brief Implements a line separator
 * 
 * @details Draws a line on the window. The component can act as
 * an Anchor so that you may align other components in respect to the Separator.
 * You can also set whether the line is vertical or horizontal.
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class ASSETS_EXPORTS Separator : public Component, public Anchor
#else
class Separator : public Component, public Anchor
#endif
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Separator() = default;

    /**
     * @brief Constructor
     * 
     * @param startLocation The location of the top-left corner 
     * @param vertical Denotes the orientation of the separator
     * 
     * @param size The length of the separator
     * @param thickness The thickness of the separator
     * 
     */
    explicit Separator(const Point&, const bool&, const float&, const uint32_t);

    // Block other forms of construction

    Separator() = delete;
    Separator( const Separator& ) = delete;
    Separator& operator= ( const Separator& ) = delete;

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
    ::sf::RectangleShape& getInternalSeparator();

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
private:
    ::sf::RectangleShape _shape;

    virtual void draw(::sf::RenderTarget&, ::sf::RenderStates) const override;
};

}