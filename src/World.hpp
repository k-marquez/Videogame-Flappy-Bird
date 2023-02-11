/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com
    
    Author: Kevin Márquez
    marquezberriosk@gmail.com

    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class World.
*/

#pragma once

#include <list>
#include <memory>
#include <random>

#include <SFML/Graphics.hpp>

#include <src/Factory.hpp>
#include <src/LogPair.hpp>

class World
{
public:
    World(bool _generate_logs = false) noexcept;

    World(const World& world) = delete;

    World& operator = (World) = delete;

    void reset(bool _generate_logs) noexcept;

    void resetScore() noexcept;

    bool collides(const sf::FloatRect& rect) const noexcept;

    bool update_scored(const sf::FloatRect& rect) noexcept;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

    void increase_score() noexcept;

    int get_score() const noexcept;

    int get_level_limit() const noexcept;

    void set_level_limit(int _limit) noexcept;
    
    void set_aditional_time_to_spwan(float _aditional_time) noexcept;

private:
    
    void update_last_y() noexcept;
    
    void update_time_to_spawn() noexcept;

private:
    bool generate_logs;

    sf::Sprite background;
    sf::Sprite ground;

    float background_x{0.f};
    float ground_x{0.f};

    Factory<LogPair> log_factory;

    std::list<std::shared_ptr<LogPair>> logs;

    std::mt19937 rng;

    float logs_spawn_timer{0.f};
    float last_log_y{0.f};
    float aditional_time{0.f};
    float time_to_spawn{0.f};

    int level_limit;
    int score{0};
};
