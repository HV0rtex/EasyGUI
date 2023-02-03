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
 * @file Point.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the point struct
 * 
 * @copyright Copyright (c) 2022
 */

#include <Point.hpp>

namespace easyGUI
{

Point::Point(const float& x, const float& y)
{
    Xcoord = x;
    Ycoord = y;
}

Point::Point(const Point& other) noexcept
{
    Xcoord = other.Xcoord;
    Ycoord = other.Ycoord;
}

Point::Point(Point&& other) noexcept
{
    Xcoord = ::std::exchange(other.Xcoord, 0);  
    Ycoord = ::std::exchange(other.Ycoord, 0);
}

const Point& Point::operator=(const Point& other) noexcept
{
    if(&other != this)
    {
        Xcoord = other.Xcoord;
        Ycoord = other.Ycoord;
    }

    return *this;
}

Point::Point(const ::sf::Vector2f& vector)
{
    Xcoord = vector.x;
    Ycoord = vector.y;
}

const Point& Point::operator=(Point&& other) noexcept
{
    if(&other != this)
    {
        Xcoord = ::std::exchange(other.Xcoord, 0);
        Ycoord = ::std::exchange(other.Ycoord, 0);
    }

    return *this;
}

Point Point::operator+ (const Point& other) const noexcept
{
    return Point(
        Xcoord + other.Xcoord,
        Ycoord + other.Ycoord
    );
}

Point Point::operator- (const Point& other) const noexcept
{
    return Point(
        Xcoord - other.Xcoord,
        Ycoord - other.Ycoord
    );
}

Point Point::operator* (const float& factor) const noexcept
{
    return Point(
        Xcoord * factor,
        Ycoord * factor
    );
}

Point Point::operator/ (const float& factor) const noexcept
{
    if(factor == 0)
    {
        return Point();
    }

    return Point(
        Xcoord / factor,
        Ycoord / factor
    );
}

}