/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the clase World.
*/
#include <iostream>

#include <Settings.hpp>
#include <src/World.hpp>

World::World(bool _generate_logs) noexcept
    : generate_logs{_generate_logs}, background{Settings::textures["background"]}, ground{Settings::textures["ground"]},
      logs{}, rng{std::default_random_engine{}()},
      time_to_spawn{Settings::TIME_TO_SPAWN_LOGS}
{
    ground.setPosition(0, Settings::VIRTUAL_HEIGHT - Settings::GROUND_HEIGHT);
}

void World::reset(bool _generate_logs) noexcept
{
    generate_logs = _generate_logs;
}

void World::resetScore() noexcept
{
    score = 0;
}

bool World::collides(const sf::FloatRect& rect) const noexcept
{
    if (rect.top + rect.height >= Settings::VIRTUAL_HEIGHT)
    {
        return true;
    }
    
    for (auto log_pair: logs)
    {
        if (log_pair->collides(rect))
        {
            return true;
        }
    }

    return false;
}

bool World::update_scored(const sf::FloatRect& rect) noexcept
{
    for (auto log_pair: logs)
    {
        if (log_pair->update_scored(rect))
        {
            return true;
        }
    }

    return false;
}

void World::update(float dt) noexcept
{
    if (generate_logs)
    {
        logs_spawn_timer += dt;
        
        if (logs_spawn_timer >= time_to_spawn)
        {
            logs_spawn_timer = 0.f;
            update_time_to_spawn();
            
            std::uniform_int_distribution<int> dist{-level_limit, level_limit};
            float y = std::max(-Settings::LOG_HEIGHT + 10, std::min(last_log_y + dist(rng), Settings::VIRTUAL_HEIGHT + 90 - Settings::LOG_HEIGHT));

            last_log_y = y;

            logs.push_back(log_factory.create(Settings::VIRTUAL_WIDTH, y,level_limit));
        }
    }

    background_x += -Settings::BACK_SCROLL_SPEED * dt;

    if (background_x <= -Settings::BACKGROUND_LOOPING_POINT)
    {
        background_x = 0;
    }

    background.setPosition(background_x, 0);

    ground_x += -Settings::MAIN_SCROLL_SPEED * dt;

    if (ground_x <= -Settings::VIRTUAL_WIDTH)
    {
        ground_x = 0;
    }

    ground.setPosition(ground_x, Settings::VIRTUAL_HEIGHT - Settings::GROUND_HEIGHT);

    for (auto it = logs.begin(); it != logs.end(); )
    {
        if ((*it)->is_out_of_game())
        {
            auto log_pair = *it;
            log_factory.remove(log_pair);
            it = logs.erase(it);
        }
        else
        {
            (*it)->update(dt);
            ++it;
        }
    }
}

void World::render(sf::RenderTarget& target) const noexcept
{
    target.draw(background);

    for (const auto& log_pair: logs)
    {
        log_pair->render(target);
    }

    target.draw(ground);
}

void World::increase_score() noexcept
{
    score++;
}

int World::get_score() const noexcept
{
    return score;
}

int World::get_level_limit() const noexcept
{
    return level_limit;
}

void World::set_level_limit(int _limit) noexcept
{
    level_limit = _limit + 20;
    update_last_y();
}

void World::update_last_y() noexcept
{
    std::uniform_int_distribution<int> dist(0, 80 + level_limit);
    last_log_y = -Settings::LOG_HEIGHT + dist(rng);
}

void World::set_aditional_time_to_spwan(float _aditional_time) noexcept
{
    aditional_time = _aditional_time;
    update_time_to_spawn();
}

void World::update_time_to_spawn() noexcept
{
    std::uniform_real_distribution<float> dist_t{0, aditional_time};
    time_to_spawn = Settings::TIME_TO_SPAWN_LOGS + dist_t(rng);
}
 
