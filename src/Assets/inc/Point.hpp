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
 * @file Point.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Point class
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#if WIN32 && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <SFML/System/Vector2.hpp>
#include <utility>

namespace easyGUI
{

/**
 * @brief Stores the coordinates of a point.
 * 
 */
struct Point
{
    float Xcoord;
    float Ycoord;

    /**
     * @brief Default constructor
     * 
     */
    Point() = default;

    /**
     * @brief Constructor
     * 
     * @param x The X-coordinate
     * @param y The Y-coordinate
     */
    explicit Point(const float&, const float&);

    /**
     * @brief Converts Vector2f to Point
     * 
     * @param vector The SFML equivalent
     */
    explicit Point(const ::sf::Vector2f&);

    /**
     * @brief Copy-Constructor
     * 
     * @param other A point to copy from
     */
    Point(const Point&) noexcept;

    /**
     * @brief Move-constructor
     * 
     * @param other A point to be moved here
     */
    Point(Point&&) noexcept;

    /**
     * @brief Assignment operator
     * 
     * @param other A point to copy from
     * 
     * @return Point& 
     */
    const Point& operator= (const Point&) noexcept;

    /**
     * @brief Move assignment operator
     * 
     * @param other A point to be moved here
     * 
     * @return Point& 
     */
    const Point& operator= (Point&&) noexcept;

    /**
     * @brief Adds two points
     * 
     * @param other the point to be added
     * 
     * @return Point 
     */
    Point operator+ (const Point&) const noexcept;

    /**
     * @brief Divides both coordinates by a factor
     * 
     * @param factor The divisor
     * 
     * @return Point 
     */
    Point operator/ (const float&) const noexcept;

    /**
     * @brief Multiplies both coordinates by a factor
     * 
     * @param factor The factor
     * 
     * @return Point 
     */
    Point operator* (const float&) const noexcept;
};

}