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
 * @file Application.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Implementation of the Application class
 * 
 * @copyright Copyright (c) 2022
 */

#include <iostream>

#include <Application.hpp>


namespace easyGUI {

// Defining the application instance
std::shared_ptr<Application> Application::instance_ = 0;

Application::Application(const uint32_t width,
                         const uint32_t height,
                         const char* title) {
    window_ = ::std::make_shared<::sf::RenderWindow>
        (::sf::VideoMode(width, height), title);

    startMenuSet_ = false;
    activeMenu_ = nullptr;
    menus_ = ::std::map<::std::string, MenuPtr>();
    routines_ = ::std::map<ExecutionMoment, ::std::vector<Routine>>();

    routines_.emplace(ExecutionMoment::STARTUP, ::std::vector<Routine>());
    routines_.emplace(ExecutionMoment::PRE_EVENT, ::std::vector<Routine>());
    routines_.emplace(ExecutionMoment::EVENT, ::std::vector<Routine>());
    routines_.emplace(ExecutionMoment::PRE_DRAW, ::std::vector<Routine>());
    routines_.emplace(ExecutionMoment::POST_DRAW, ::std::vector<Routine>());
    routines_.emplace(ExecutionMoment::CLEANUP, ::std::vector<Routine>());
}

::std::shared_ptr<Application> Application::getInstance(
        const uint32_t width,
        const uint32_t height,
        const char* title) {
    if (title != nullptr && width > 0 && height > 0) {
        if (instance_ == nullptr) {
            instance_ = ::std::make_shared<Application>
                (Application(width, height, title));
        } else {
            // Adjust the window to the new configuration
            instance_->window_->setSize(::sf::Vector2u(width, height));
            instance_->window_->setTitle(title);
        }
    }

    if (instance_ == nullptr) {
        ERROR << "Application instance_ not created.";
        abort();
    }

    return instance_;
}

void Application::handleEvents(const ::sf::Event& event) {
    ::std::vector<::std::shared_ptr<Component>> components =
        activeMenu_->getAllComponents();

    if (event.type == ::sf::Event::MouseButtonPressed &&
        event.mouseButton.button == ::sf::Mouse::Left) {
        selectedBox_ = nullptr;

        ::std::for_each(components.begin(), components.end(),
            [this](::std::shared_ptr<Component>& comp) {
                comp->onClick();

                if (!selectedBox_ && comp->isMouseHover()) {
                    ::std::shared_ptr<TextBox> cast =
                        ::std::dynamic_pointer_cast<TextBox>(comp);
                    selectedBox_ = cast;
                }
        });
    } else if (event.type == ::sf::Event::MouseMoved) {
        ::std::for_each(components.begin(), components.end(),
            [](::std::shared_ptr<Component>& comp) {
                comp->onHover();
        });
    } else if (event.type == ::sf::Event::TextEntered && selectedBox_) {
        selectedBox_->updateText(event.text.unicode);
    } else if (event.type == ::sf::Event::Resized) {
        ::sf::View newView = window_->getDefaultView();
        newView.setSize(static_cast<float>(event.size.width),
                        static_cast<float>(event.size.height));

        window_->setView(newView);
    }

    for (const Routine& routine : routines_.at(ExecutionMoment::EVENT))
        routine.operator()(event);
}

::std::shared_ptr<Menu> Application::getMenu(const ::std::string& id) {
    if (menus_.find(id) != menus_.end())
        return menus_.at(id);

    return nullptr;
}

::std::shared_ptr<Menu> Application::getActiveMenu() {
    return activeMenu_;
}

Routine& Application::getRoutine(const ExecutionMoment& moment,
                                 const uint32_t index) {
    if (index < routines_.at(moment).size())
        return routines_.at(moment).at(index);

    throw ApplicationException("Attempting to get routine with invalid index: " + ::std::to_string(index)); // NOLINT
}

void Application::stop() {
    window_->close();
}

::std::shared_ptr<Menu> Application::addMenu(
        const ::std::string& id,
        const bool& isStart) {
    if (menus_.find(id) != menus_.end())
        throw ApplicationException("A menu with this ID exists already: " + id);

    ::std::shared_ptr<Menu> newMenu = ::std::make_shared<Menu>();
    newMenu->setContainer(window_);

    if (isStart && !startMenuSet_) {
        activeMenu_ = newMenu;
        startMenuSet_ = true;
    } else {
        throw ApplicationException("Could not create initial menu because another initial menu has already been created."); // NOLINT
    }

    menus_.emplace(id, newMenu);

    return newMenu;
}

void Application::setActiveMenu(const ::std::string& id) {
    if (menus_.find(id) != menus_.end()) {
        activeMenu_ = menus_.at(id);

        if (!startMenuSet_) {
            // A main menu can also be configured by manually setting
            // the active menu.
            INFO << "No start menu detected. Defaulting to the one specified in call."; // NOLINT

            startMenuSet_ = true;
        }
    } else {
        throw MenuException("Could not get hold of menu wiht id: " + id);
    }
}

void Application::addRoutine(const ExecutionMoment& moment,
                             const Routine& routine) {
    routines_[moment].push_back(routine);
}

void Application::start() {
    if (activeMenu_ == nullptr)
        throw ApplicationException("Attempting start with no initial menu.");

    for (const Routine& routine : routines_.at(ExecutionMoment::STARTUP))
        routine.operator()(::sf::Event());

    while (window_->isOpen()) {
        ::sf::Event event;

        for (const Routine& routine : routines_.at(ExecutionMoment::PRE_EVENT))
            routine.operator()(::sf::Event());

        while (window_->pollEvent(event))
            handleEvents(event);

        for (const Routine& routine : routines_.at(ExecutionMoment::PRE_DRAW))
            routine.operator()(::sf::Event());

        window_->clear();
        window_->draw(*activeMenu_);
        window_->display();

        for (const Routine& routine : routines_.at(ExecutionMoment::POST_DRAW))
            routine.operator()(::sf::Event());
    }

    for (const Routine& routine : routines_.at(ExecutionMoment::CLEANUP))
        routine.operator()(::sf::Event());
}

::std::shared_ptr<::sf::RenderWindow> Application::getWindow() {
    return window_;
}

}  // namespace easyGUI
