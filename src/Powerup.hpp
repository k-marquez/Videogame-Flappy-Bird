/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class Powerup.
*/

#pragma once

#include <SFML/Graphics.hpp>

class Powerup
{
public:
    Powerup(float _x, float _y) noexcept;

    sf::FloatRect get_collision_rect() const noexcept;

    void update(float _x) noexcept;

    void render(sf::RenderTarget& target) const noexcept;
    
    void take_powerup() noexcept;
    
    void reset(float _x, float _y) noexcept;
    
    bool is_out_of_game() const noexcept;
    
    bool is_active() const noexcept;
    
    bool collides(const sf::FloatRect& rect) const noexcept;

private:
    float x;
    float y;
    float active_time;
    bool taked;
    sf::Sprite sprite;
};
