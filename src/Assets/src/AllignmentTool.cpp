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

#include <AlignmentTool.hpp>

namespace easyGUI
{

::std::shared_ptr<AllignmentTool> AllignmentTool::_instance = nullptr;

::std::shared_ptr<AllignmentTool> AllignmentTool::getInstance()
{
    if(_instance == nullptr)
    {
        _instance = ::std::make_shared<AllignmentTool>(AllignmentTool());
    }

    return _instance;
}


Point AllignmentTool::getAllignment(const Anchor* source, const Anchor* anchor, const Binding& mode, const Point& offset)
{
    if(anchor == nullptr || source == nullptr)
        throw AllignmentException("Invalid anchor.");

    Point desiredLocation;

    switch (mode.second)
    {
    case Mode::LEFT:
        desiredLocation = anchor->getLEFT() + offset;
        break;
    case Mode::RIGHT:
        desiredLocation = anchor->getRIGHT() + offset;
        break;
    case Mode::TOP:
        desiredLocation = anchor->getTOP() + offset;
        break;
    case Mode::BOTTOM:
        desiredLocation = anchor->getBOTTOM() + offset;
        break;
    case Mode::CENTER:
        desiredLocation = anchor->getCENTER() + offset;
        break;
    default:
        throw AllignmentException("Invalid allignment mode");
        break;
    }

    // TO-DO : plan and redo all
    switch (mode.first)
    {
    case Mode::LEFT:
        return desiredLocation + source->getLEFT();
    case Mode::RIGHT:
        return desiredLocation + (source->getRIGHT() * -1) + source->getBOTTOM();
    case Mode::TOP:
        return desiredLocation + anchor->getLEFT();
    case Mode::BOTTOM:
        return desiredLocation + anchor->getLEFT();
    case Mode::CENTER:
        return desiredLocation + anchor->getLEFT();
    default:
        throw AllignmentException("Invalid allignment mode");
        break;
    }
}

}