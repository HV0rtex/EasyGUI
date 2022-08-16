/**
 * @file T_Label_UT.cpp
 * @author David Bogdan (david.bnicolae@gmail.com)
 * @brief Unit tests for the label class
 * @version 0.1
 * @date 2022-08-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <gtest/gtest.h>
#include <Label.hpp>

TEST(LabelUnitTest, SimpleInitTest)
{
    ::egui::utils::Point pos;

    pos.Xcoord = 0;
    pos.Ycoord = 0;

    ASSERT_THROW(egui::Label(pos, "Example", "some/random/path", 10, ::sf::Color(10,10,10)), std::invalid_argument);
}