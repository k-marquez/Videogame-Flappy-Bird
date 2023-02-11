/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of utility functions to build texts.
*/

#pragma once

#include <string>

#include <SFML/Graphics.hpp>

void render_text(sf::RenderTarget& target, float x, float y, const std::string& text_str, int size, const std::string& font_name, const sf::Color& color, bool center = false) noexcept;
