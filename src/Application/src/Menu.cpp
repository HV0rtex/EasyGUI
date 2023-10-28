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
 * @file Menu.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Menu class
 * 
 * @copyright Copyright (c) 2022
 */

#include <Menu.hpp>


namespace easyGUI {

void Menu::addComponent(const std::shared_ptr<Component>& component,
                        const ::std::string& ID) {
    if (components_.find(ID) != components_.end())
        throw MenuException("A component with that ID already exists: " + ID);

    components_.emplace(ID, component);
    component->setContainer(container_);
}

void Menu::draw(::sf::RenderTarget& target,
                ::sf::RenderStates states) const {
    for (const auto& element : components_)
        target.draw(*element.second, states);
}

::std::shared_ptr<Component> Menu::getComponent(const ::std::string& ID) {
    if (components_.find(ID) != components_.end())
        return components_.at(ID);

    return nullptr;
}

::std::vector<::std::shared_ptr<Component>> Menu::getAllComponents() {
    ::std::vector<::std::shared_ptr<Component>> temp;
    ::std::transform(
        components_.begin(),
        components_.end(),
        ::std::back_inserter(temp),
        [](const ::std::pair<::std::string, ::std::shared_ptr<Component>>& el) {
            return el.second;
    });

    return temp;
}

void Menu::clear() {
    components_.clear();
}

void Menu::setContainer(const WindowPtr& container) {
    container_ = container;
}

}  // namespace easyGUI
