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
 * @brief Definition of the Anchor interface and AlignmentTool class
 * @version 0.1
 * @date 2022-11-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#ifdef _WIN32
#include <assets_export.hpp>
#endif

// Including dependencies
#include <Component.hpp>
#include <Point.hpp>
#include <utility>
#include <vector>
#include <map>

namespace easyGUI
{

// Stub declaration
#ifdef _WIN32
class ASSETS_EXPORTS AlignmentTool;
#else
class AlignmentTool;
#endif

/**
 * @brief Defines an anchor on the window
 * 
 * @details An anchor denotes an element of the GUI which can be used by other elements in order
 * to allign themselves in the window.
 * 
 */
#ifdef _WIN32
class ASSETS_EXPORTS Anchor
#else
class Anchor
#endif
{
private:
    char movable_;

    /**
     * @brief Makes anchor imovable
     * 
     */
    void blockAnchor();

    /**
     * @brief Makes anchor imovable
     * 
     */
    void freeAnchor();

public:
    friend class AlignmentTool;

    /**
     * @brief Destructor
     * 
     */
    virtual ~Anchor() = default;

    /**
     * @brief Constructor
     * 
     */
    Anchor() : movable_(1) {}

    /**
     * @brief Returns the point leftmost of the Anchor
     * 
     * @return Point& 
     */
    virtual Point getLEFT() const = 0;

    /**
     * @brief Returns the point rightmost of the Anchor
     * 
     * @return Point& 
     */
    virtual Point getRIGHT() const = 0;

    /**
     * @brief Returns the lowest point of the Anchor
     * 
     * @return Point& 
     */
    virtual Point getBOTTOM() const = 0;

    /**
     * @brief Returns the highest point of the Anchor
     * 
     * @return Point& 
     */
    virtual Point getTOP() const = 0;

    /**
     * @brief Returns the point at the center of the Anchor
     * 
     * @return Point& 
     */
    virtual Point getCENTER() const = 0;

    /**
     * @brief Checks if an anchor can be moved
     * 
     * @return bool
     */
    bool isMovable() const;
};

enum Mode {
    LEFT,
    RIGHT,
    BOTTOM,
    TOP,
    CENTER
};

typedef ::std::pair<Mode, Mode> Binding;


/**
 * @brief Class responsible with computing positions
 * 
 * @details This class is a Singleton which is used when you want to allign elements
 * of the GUI in respect to other elements, called Anchors. Whenever an element becomes
 * bound to an anchor, it becomes unmovable. Meaning the only way to alter its position
 * is by moving the anchor it is bound to.
 * 
 */
#ifdef _WIN32
class ASSETS_EXPORTS AlignmentTool
#else
class AlignmentTool
#endif
{
private:
    ::std::map<const Anchor*, ::std::vector<::std::pair<::std::pair<Anchor*, Binding>, const Point>>> _bindings;

    /**
     * @brief Computes the position of an element
     * 
     * @param source The object to be alligned.
     * @param anchor The anchor used for Alignment
     * @param mode How to allign the element
     * @param offest An offest to be applied between the component and the element
     * 
     * @return Point
     */
    Point getAlignment(const Anchor&, const Anchor&, const Binding&, const Point& = Point()) noexcept;

    /**
     * @brief Constructor
     * 
     */
    AlignmentTool() = default;
public:
    /**
     * @brief Destructor
     * 
     */
    ~AlignmentTool() = default;

    /**
     * @brief Returns an instance of the Alignment tool
     * 
     * @return AlignmentTool* 
     */
    static AlignmentTool& getInstance();

    /**
     * @brief Creates a binding between two elements
     * 
     * @param source The bound element
     * @param anchor The "free" element
     * @param binding The type of binding between elements
     * @param offset The desired offset
     */
    void createBinding(Anchor&, const Anchor&, const Binding&, const Point& = Point());

    /**
     * @brief Updates all the elements bound to an anchor
     * 
     * @param source The anchor that moved
     */
    void triggerUpdate(const Anchor&);
};

}