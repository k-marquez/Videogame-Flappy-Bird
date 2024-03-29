/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class Bird.
*/

#include <iostream>

#include <Settings.hpp>
#include <src/Bird.hpp>

Bird::Bird(float _x, float _y, float w, float h) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, vy{0.f}, move_direction(0.f), stop_time(0.3), sprite{Settings::textures["bird"]}
{
    sprite.setPosition(x, y);
}

sf::FloatRect Bird::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, width, height};
}

void Bird::jump() noexcept
{
    if (!jumping)
    {
        jumping = true;
    }
}

void Bird::move_to_left() noexcept
{
    if (move_direction != -1.f)
    {
        move_direction = -1.f;
        stop_time = 0.35;
    }
}
    
void Bird::move_to_right() noexcept
{
    if (move_direction != 1.f)
    {
        move_direction = 1.f;
        stop_time = 0.35;
    }
}

void Bird::update(float dt) noexcept
{
    vy += Settings::GRAVITY * dt;
    vx += move_direction * Settings::HORIZONTAL_SPEED * dt;
    
    if (move_direction != 0)
    {
        stop_time -= dt;
    }
    
    if (stop_time < 0)
    {
        vx = 0.f;
        move_direction = 0;
        stop_time = 0.3;
    }
    
    if (jumping)
    {
        Settings::sounds["jump"].play();
        vy = -Settings::JUMP_TAKEOFF_SPEED;
        jumping = false;
    }
    
    y += vy * dt;
    x += vx * dt;
    sprite.setPosition(x, y);
}

void Bird::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}

void Bird::reset() noexcept
{
    vx = 0.f;
    stop_time = 0.f;
}

void Bird::set_sprite(bool bird, float _w, float _h) noexcept
{
    if(bird)
    {
        sprite.setTexture(Settings::textures["bird2"]);
        mode = true;
    }
    else
    {
        sprite.setTexture(Settings::textures["bird"]);
        mode = false;
    }
    width = _w;
    height = _h;   
}

bool Bird::get_mode() const noexcept
{
    return mode;
}