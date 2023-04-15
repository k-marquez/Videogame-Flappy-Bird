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
      active_time{Settings::TIME_POWERUP}
{
}

sf::FloatRect Powerup::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, Settings::POWERUP_WIDTH, Settings::POWERUP_HEIGHT};
}

void Powerup::update(float dt) noexcept
{
    if(taked)
    {
        active_time -= dt;
        if (active_time <= 0)
        {
            taked = false;   
        }
    }
    else
    {
        x += Settings::GRAVITY / 10 * -dt;
        sprite.setPosition(x, y);
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

int Powerup::get_time() const noexcept
{
    return active_time;
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
    return x < - Settings::POWERUP_WIDTH;
}

bool Powerup::collides(const sf::FloatRect& rect) const noexcept
{
    return get_collision_rect().intersects(rect);
}