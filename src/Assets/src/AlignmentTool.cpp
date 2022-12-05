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

bool Anchor::isMovable() const
{
    return movable_ == 1;
}

void Anchor::blockAnchor()
{
    movable_ = 0;
}

void Anchor::freeAnchor()
{
    movable_ = 1;
}

AlignmentTool& AlignmentTool::getInstance()
{
    static AlignmentTool _instance;

    return _instance;
}


Point AlignmentTool::getAlignment(const Anchor& source, const Anchor& anchor, const Binding& mode, const Point& offset) noexcept
{
    Point desiredLocation;

    switch (mode.second)
    {
    case Mode::LEFT:
        desiredLocation = anchor.getLEFT() + offset;
        break;
    case Mode::RIGHT:
        desiredLocation = anchor.getRIGHT() + offset;
        break;
    case Mode::TOP:
        desiredLocation = anchor.getTOP() + offset;
        break;
    case Mode::BOTTOM:
        desiredLocation = anchor.getBOTTOM() + offset;
        break;
    case Mode::CENTER:
        desiredLocation = anchor.getCENTER() + offset;
        break;
    default:
        break;
    }

    Point delta;

    switch (mode.first)
    {
    case Mode::LEFT:
        delta = desiredLocation + (source.getLEFT() * -1); 
        break;
    case Mode::RIGHT:
        delta = desiredLocation + (source.getRIGHT() * -1); 
        break;
    case Mode::TOP:
        delta = desiredLocation + (source.getTOP() * -1); 
        break;
    case Mode::BOTTOM:
        delta = desiredLocation + (source.getBOTTOM() * -1); 
        break;
    case Mode::CENTER:
        delta = desiredLocation + (source.getCENTER() * -1); 
        break;
    default:
        break;
    }

    return Point(source.getLEFT().Xcoord + delta.Xcoord, source.getTOP().Ycoord + delta.Ycoord);
}

void AlignmentTool::createBinding(Anchor& source, const Anchor& anchor, const Binding& binding, const Point& offset)
{
    if(_bindings.find(&anchor) == _bindings.end())
    {
        _bindings.emplace(&anchor, ::std::vector<::std::pair<::std::pair<Anchor*, Binding>, const Point>>());
    }

    _bindings[&anchor].push_back(
        ::std::pair<::std::pair<Anchor*, Binding>, const Point>(
            ::std::pair<Anchor*, Binding>(&source, binding), offset
        ));

    source.blockAnchor();

    // A newly created binding will trigger an update
    triggerUpdate(anchor);
}

void AlignmentTool::triggerUpdate(const Anchor& source)
{
    for(const ::std::pair<::std::pair<Anchor*, Binding>, const Point>& pair : _bindings[&source])
    {
        if(dynamic_cast<Component*>(pair.first.first) != nullptr)
        {
            // Temporarily frees anchor
            pair.first.first->freeAnchor();

            dynamic_cast<Component*>(pair.first.first)->updateLocation(
                getAlignment(*pair.first.first, source, pair.first.second, pair.second)
            );

            pair.first.first->blockAnchor();
        }
    }
}

}