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

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <Component.hpp>
#include <Point.hpp>
#include <utility>
#include <vector>
#include <map>

namespace easyGUI
{

/**
 * @brief Represents different parts by which
 * an Anchor can be bound / bount to.
 * 
 */
enum BindingPoint {
    LEFT,
    RIGHT,
    BOTTOM,
    TOP,
    CENTER
};

/**
 * @brief Defines an anchor on the window
 * 
 * @details An anchor denotes an element of the GUI which can be used by other elements in order
 * to allign themselves in the window.
 * 
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class ASSETS_EXPORTS Anchor : public ::std::enable_shared_from_this<Anchor>
#else
class Anchor : public ::std::enable_shared_from_this<Anchor>
#endif
{
public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Anchor() = default;

    /**
     * @brief Constructor
     * 
     */
    Anchor() = default;

    /**
     * @brief Returns a binding point of the anchor
     * 
     * @param point Which point to return
     * 
     * @return Point The binding point
     */
    Point getBindingPoint(const BindingPoint&) const;

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

    // ----- Enable shared_ptr -----

    /**
     * @brief Converts this to a shared pointer
     * 
     * @return ::std::shared_ptr<Anchor> 
     */
    ::std::shared_ptr<Anchor> getShared();
};

using AnchorPtr = ::std::shared_ptr<Anchor>;

/**
 * @brief Class responsible with computing positions
 * 
 * @details This class is a Singleton which is used when you want to allign elements
 * of the GUI in respect to other elements, called Anchors. Whenever an element becomes
 * bound to an anchor, it becomes unmovable. Meaning the only way to alter its position
 * is by moving the anchor it is bound to.
 * 
 */
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
class ASSETS_EXPORTS AlignmentTool
#else
class AlignmentTool
#endif
{
private:
    struct Binding
    {
        AnchorPtr anchors[2];
        BindingPoint points[2];

        Point offset;

        bool operator== (const Binding&) const noexcept;
    };

    ::std::vector<Binding> _bindings;

    /**
     * @brief Computes the position of an element
     * 
     * @param binding The binding between the elements
     * 
     * @return Point
     */
    Point getAlignment(const Binding&) noexcept;

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
    virtual ~AlignmentTool() = default;

    /**
     * @brief Returns an instance of the Alignment tool
     * 
     * @return AlignmentTool&
     */
    static AlignmentTool& getInstance();

    /**
     * @brief Creates a binding between two elements
     * 
     * @param source The bound element
     * @param anchor The anchor to which the source is bound=
     * @param sourcePoint The point by which the source is bound
     * @param anchorPoint The point by which the anchor is bound
     * @param offset The desired offset
     */
    void createBinding(AnchorPtr&, const AnchorPtr&, const BindingPoint&, const BindingPoint&, const Point& = Point());

    /**
     * @brief Updates all the elements bound to an anchor
     * 
     * @param source The anchor that moved
     */
    void triggerUpdate(const AnchorPtr&);
};

}