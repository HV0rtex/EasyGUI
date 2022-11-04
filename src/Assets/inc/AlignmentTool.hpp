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
 * @file AlignmentTool.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Anchor interface and AllignmentTool class
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

// Including dependencies
#include <Exceptions/AllignmentException.hpp>
#include <Point.hpp>
#include <memory>

namespace easyGUI
{

/**
 * @brief Defines an anchor on the window
 * 
 * @details An anchor denotes an element of the GUI which can be used by other elements in order
 * to allign themselves in the window.
 * 
 */
class Anchor
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Anchor() = default;

    /**
     * @brief Returns the point leftmost of the Anchor
     * 
     * @return Point& 
     */
    virtual Point& getLEFT() const = 0;

    /**
     * @brief Returns the point rightmost of the Anchor
     * 
     * @return Point& 
     */
    virtual Point& getRIGHT() const = 0;

    /**
     * @brief Returns the lowest point of the Anchor
     * 
     * @return Point& 
     */
    virtual Point& getBOTTOM() const = 0;

    /**
     * @brief Returns the highest point of the Anchor
     * 
     * @return Point& 
     */
    virtual Point& getTOP() const = 0;

    /**
     * @brief Returns the point at the center of the Anchor
     * 
     * @return Point& 
     */
    virtual Point& getCENTER() const = 0;
};

/**
 * @brief Class responsible with computing positions
 * 
 * @details This class is a Singleton which is used when you want to allign elements
 * of the GUI in respect to other elements, called Anchors. 
 * 
 */
class AllignmentTool
{
private:
    static ::std::shared_ptr<AllignmentTool> _instance;

    /**
     * @brief Constructor
     * 
     */
    AllignmentTool() = default;
public:
    enum Modes {
        LEFT,
        RIGHT,
        BOTTOM,
        TOP,
        CENTER
    };

    /**
     * @brief Destructor
     * 
     */
    ~AllignmentTool() = default;

    /**
     * @brief Returns an instance of the allignment tool
     * 
     * @return AllignmentTool* 
     */
    static ::std::shared_ptr<AllignmentTool> getInstance();

    /**
     * @brief Computes the position of an element
     * 
     * @param anchor The anchor used for allignment
     * @param mode How to allign the element
     * @param offest An offest to be applied between the component and the element
     * 
     * @return Point
     */
    Point getAllignment(const Anchor*, const Modes&, const Point&);
};

}