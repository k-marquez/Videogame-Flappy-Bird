/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class Powerup.
*/

#include <Settings.hpp>
#include <src/Powerup.hpp>

Powerup::Powerup(float _x, float _y) noexcept
    : x{_x}, y{_y}, taked{false}, sprite{Settings::textures["powerup"]},
      active_time{5.f}
{
}

sf::FloatRect Powerup::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, Settings::POWERUP_WIDTH, Settings::POWERUP_HEIGHT};
}

void Powerup::update(float dt) noexcept
{
    if (not taked)
    {
        x += -5.f;
        sprite.setPosition(x, y);
    }
    
    if(taked)
    {
        active_time -= dt;
        
        if (active_time <= 0)
        {
            taked = false;   
        }
    }
}

void Powerup::take_powerup() noexcept
{
    taked = true;
}

bool Powerup::is_active() const noexcept
{
    return taked;
}

void Powerup::reset(float _x, float _y) noexcept
{
    x = _x;
    y = _y;
    taked = false;
}

void Powerup::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}

bool Powerup::is_out_of_game() const noexcept
{
    return x < -Settings::POWERUP_WIDTH;
}

bool Powerup::collides(const sf::FloatRect& rect) const noexcept
{
    return get_collision_rect().intersects(rect);
}

