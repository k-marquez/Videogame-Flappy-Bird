/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class LogPair.
*/

#include <Settings.hpp>
#include <src/LogPair.hpp>
#include <iostream>

LogPair::LogPair(float _x, float _y, int _level) noexcept
    : x{_x}, y{_y}, level{_level},
      top{x, y + Settings::LOG_HEIGHT, true},
      bottom{x, y + Settings::LOGS_GAP + Settings::LOG_HEIGHT, false}
{

}

bool LogPair::collides(const sf::FloatRect& rect) const noexcept
{
    return top.get_collision_rect().intersects(rect) || bottom.get_collision_rect().intersects(rect);
}

void LogPair::update(float dt) noexcept
{
    if(level>40)
    {
        float y2{top.getY()};
        float y3{bottom.getY()};
        if(first)
        {
            ty = top.getY();
            by = bottom.getY();
            first = false;
        }
        if(top.getY() < bottom.getY() && close == false)
        {
            y2 = top.getY() + (Settings::MAIN_SCROLL_SPEED/3) * dt;
            y3 = bottom.getY() - (Settings::MAIN_SCROLL_SPEED/3) * dt;
        }
        else
        {
            close = true;
            if(top.getY() > ty)
            {
                y2 = top.getY() - (Settings::MAIN_SCROLL_SPEED/3) * dt;
                y3 = bottom.getY() + (Settings::MAIN_SCROLL_SPEED/3) * dt;
            }
            else
                close = false;
        }
        x += -Settings::MAIN_SCROLL_SPEED * dt;
        top.update(x,y2);
        bottom.update(x,y3);
    }
    else
    {
        x += -Settings::MAIN_SCROLL_SPEED * dt;
        top.update(x,top.getY());
        bottom.update(x,bottom.getY());
    }
    
}

void LogPair::render(sf::RenderTarget& target) const noexcept
{
    top.render(target);
    bottom.render(target);
}

bool LogPair::is_out_of_game() const noexcept
{
    return x < -Settings::LOG_WIDTH;
}

bool LogPair::update_scored(const sf::FloatRect& rect) noexcept
{
    if (scored)
    {
        return false;
    }

    if (rect.left > x + Settings::LOG_WIDTH)
    {
        scored = true;
        return true;
    }

    return false;
}

void LogPair::reset(float _x, float _y) noexcept
{
    x = _x;
    y = _y;
    scored = false;
}