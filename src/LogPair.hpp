/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class LogPair.
*/

#pragma once

#include <src/Bird.hpp>
#include <src/Log.hpp>

class LogPair
{
public:
    LogPair(float _x, float _y, int _level) noexcept;

    bool collides(const sf::FloatRect& rect) const noexcept;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    bool is_out_of_game() const noexcept;

    bool update_scored(const sf::FloatRect& rect) noexcept;

    void reset(float _x, float _y) noexcept;

private:
    float x;
    float y;
    float ty;
    float by;
    Log top;
    Log bottom;
    bool close{false};
    bool impact{false};
    bool scored{false};
    bool first{true};
    int level;
};