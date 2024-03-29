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
 * @file Image.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Image class
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <string>
#include <memory>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <Exceptions/ImageException.hpp>
#include <AlignmentTool.hpp>
#include <Component.hpp>
#include <Manager.hpp>

namespace easyGUI {

/**
 * @brief Draws an image to the screen
 * 
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class ASSETS_EXPORTS Image : public Component, public Anchor
#else
class Image : public Component, public Anchor
#endif
{
 public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Image() = default;

    /**
     * @brief Constructor
     * 
     * @param startLocation The top-left corner of the image
     * @param endLocation The bottom-left corner of the image
     * @param path The path to the image
     * 
     * @throws ImageException could not load image
     */
    explicit Image(const Point&,
                   const Point&,
                   const ::std::string&);

    /**
     * @brief Constructor
     * 
     * @param startLocation The top-left corner of the image
     * @param width The width of the image
     * @param height The height of the image
     * @param path The path to the image
     * 
     * @throws ImageException could not load image
     */
    explicit Image(const Point&,
                   const float&,
                   const float&,
                   const std::string&);

    // Block other forms of construction

    Image() = delete;
    Image(const Image&) = delete;
    Image& operator= (const Image&) = delete;

    /**
     * @brief Check if mouse is over the button
     * 
     * @return true Mouse is over the label
     * @return false otherwise
     */
    bool isMouseHover() const override;

    /**
     * @brief Updates a component's location
     * 
     * @param newLocation The new location of the component
     */
    void updateLocation(const Point&) override;

    /**
     * @brief Hides / Shows the image frame.
     * 
     * @param thickness The thickness of the frame
     */
    void toggleFrame(const uint32_t = 0);

    // ----- Inherited from Anchor -----

    Point getLEFT() const override;
    Point getRIGHT() const override;
    Point getBOTTOM() const override;
    Point getTOP() const override;
    Point getCENTER() const override;
 private:
    ::std::shared_ptr<::sf::Texture> _image;
    ::std::shared_ptr<::sf::RectangleShape> _border;
    ::sf::Sprite _object;

    void draw(::sf::RenderTarget&, ::sf::RenderStates) const override;

    /**
     * @brief Builds the frame around the image
     * 
     * @param thickness The thickness of the frame
     */
    void constructFrame(const uint32_t);
};

}  // namespace easyGUI
