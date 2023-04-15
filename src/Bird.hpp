/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class Bird.
*/

#pragma once

#include <SFML/Graphics.hpp>

class Bird
{
public:
    Bird(float _x, float _y, float w, float h) noexcept;

    Bird(const Bird&) = delete;

    Bird& operator = (Bird) = delete;

    sf::FloatRect get_collision_rect() const noexcept;

    void jump() noexcept;
    
    void move_to_left() noexcept;
    
    void move_to_right() noexcept;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;
    
    void reset() noexcept;
    
    void set_sprite(bool, float _w, float _y) noexcept;

    bool get_mode() const noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    float vy;
    float vx;
    float stop_time;
    sf::Sprite sprite;
    bool jumping{false};
    bool mode{false};
    int move_direction{0}; 
};
