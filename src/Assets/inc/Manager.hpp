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
 * @file Manager.hpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Definition of the Manager class
 * 
 * @copyright Copyright (c) 2022 
 */

#pragma once

// Including dependencies
#if defined(_WIN32) && BUILD_SHARED_LIBRARIES
    #include <assets-export.hpp>
#endif

#include <map>
#include <string>
#include <memory>

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <Exceptions/ManagerException.hpp>


namespace easyGUI {

/**
 * @brief Class responsible with loading external "assets"
 * 
 * @details The purpose of this class is to ensure the same external
 * resource is not loaded multiple times. To achieve this, it makes use
 * of shared pointers.
 * 
 * @tparam T The type of resource managed by the class
 */
template <typename T> class Manager {
 public:
    /**
     * @brief Destructor
     * 
     */
    virtual ~Manager() = default;

    /**
     * @brief Returns the manager instance
     * 
     * @return Manager&
     */
    static Manager& getInstance() {
        static Manager instance;

        return instance;
    }

    /**
     * @brief Returns the resource
     * 
     * @param path The path to the resource
     * 
     * @return ::std::shared_ptr<T> 
     * 
     * @throw ManagerException Could not load the resource
     */
    ::std::shared_ptr<T> getAsset(const ::std::string& path) {
        if (storedResources.find(path) != storedResources.end())
            return storedResources[path];

        ::std::shared_ptr<T> res = ::std::make_shared<T>();

        if (!res->loadFromFile(path))
            throw ManagerException("Could not get resource from path");

        storedResources[path] = res;
        return res;
    }

 private:
    ::std::map<::std::string, ::std::shared_ptr<T>> storedResources;

    /**
     * @brief Constructor
     * 
     * @details Private constructor in order to adhere to the singleton design pattern.
     */
    Manager() = default;
};

// Aliasing common managers
using FontManager = Manager<::sf::Font>;
using TextureManager = Manager<::sf::Texture>;

}  // namespace easyGUI
