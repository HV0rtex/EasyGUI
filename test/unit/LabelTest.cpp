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


#include <memory>
#include <gtest/gtest.h>

#include <Label.hpp>


class LabelTest : public ::testing::Test {
 protected:
    void SetUp() {
        component_ =
            std::make_shared<easyGUI::Label>(
                easyGUI::Point(0,0),
                "DEMO TEXT",
                "res/Ginga.ttf",
                32);
    }
    
    void TearDown() {
        if (component_)
            component_.reset();
    }

 private:
    std::shared_ptr<easyGUI::Label> component_;
};

TEST_F(LabelTest, CreationWithInvalidFont) {
    EXPECT_THROW(
        component_ = std::make_shared<easyGUI::Label>(
            easyGUI::Point(0,0),
            "",
            nullptr,
            32),
        easyGUI::LabelException(::testing::_));
}

TEST_F(LabelTest, AnchorBoundaries) {
    EXPECT_EQ(component_->getLEFT(), easyGUI::Point(0,0));
}