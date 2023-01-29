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
 * @file AlignmentTool.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the AlignmentTool
 * @version 0.1
 * @date 2022-11-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <AlignmentTool.hpp>

namespace easyGUI
{

Point Anchor::getBindingPoint(const BindingPoint& point) const
{
    switch(point)
    {
        case BindingPoint::LEFT:
            return getLEFT();
        case BindingPoint::RIGHT:
            return getRIGHT();
        case BindingPoint::CENTER:
            return getCENTER();
        case BindingPoint::BOTTOM:
            return getBOTTOM();
        case BindingPoint::TOP:
            return getTOP();
        default:
            return Point();
    }
}

AlignmentTool& AlignmentTool::getInstance()
{
    static AlignmentTool _instance;

    return _instance;
}

Point AlignmentTool::getAlignment(const Binding& binding) noexcept
{
    Point desiredLocation = binding.anchors[1]->getBindingPoint(binding.points[1]) + binding.offset; 
    Point delta = desiredLocation - binding.anchors[0]->getBindingPoint(binding.points[0]);

    return Point(binding.anchors[0]->getLEFT().Xcoord + delta.Xcoord, binding.anchors[0]->getTOP().Ycoord + delta.Ycoord);
}

bool AlignmentTool::Binding::operator== (const Binding& other) const noexcept
{
    return (anchors[0] == other.anchors[0]) && (anchors[1] == other.anchors[1]);
}

void AlignmentTool::createBinding(
    Anchor* source,
    Anchor* anchor, 
    const BindingPoint& sourcePoint,
    const BindingPoint& anchorPoint, 
    const Point& offset)
{
    if (!source || !anchor)
        throw new AssetException("Invalid components to bind.");

    Binding newBinding;

    newBinding.anchors[0] = source;
    newBinding.anchors[1] = anchor;
    newBinding.points[0] = sourcePoint;
    newBinding.points[1] = anchorPoint;
    newBinding.offset = offset;

    if(::std::find(_bindings.begin(), _bindings.end(), newBinding) != _bindings.end())
        // The binding already exists
        return;

    _bindings.push_back(newBinding);

    // A newly created binding will trigger an update
    triggerUpdate(anchor);
}

void AlignmentTool::triggerUpdate(const Anchor* source)
{
    ::std::for_each(_bindings.begin(), _bindings.end(), 
        [source, this](Binding& binding) {
            Component* cast = nullptr;

            if(binding.anchors[0] == source)
                cast = dynamic_cast<Component*>(binding.anchors[1]);
            else if(binding.anchors[1] == source)
                cast = dynamic_cast<Component*>(binding.anchors[0]);

            if(!cast)
                return;
            
            cast->updateLocation(this->getAlignment(binding));
    });
}

void AlignmentTool::triggerUpdate(const AnchorPtr& source)
{
    triggerUpdate(source.get());
}

void AlignmentTool::createBinding(
    AnchorPtr& source,
    AnchorPtr& anchor,
    const BindingPoint& sourcePoint,
    const BindingPoint& anchorPoint,
    const Point& offset)
{
    createBinding(source.get(), anchor.get(), sourcePoint, anchorPoint, offset);
}

}