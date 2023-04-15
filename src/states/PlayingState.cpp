/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class PlayingState.
*/

#include <iostream>

#include <Settings.hpp>
#include <src/HandleGameModeHard.hpp>
#include <src/HandleGameModeRegular.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PlayingState.hpp>
#include <src/text_utilities.hpp>

PlayingState::PlayingState(StateMachine* sm) noexcept
    : BaseState{sm}, rng{std::default_random_engine{}()}
{

}

void PlayingState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, std::shared_ptr<HandleGameModeBase> _handler) noexcept
{
    world = _world;
    handler = _handler;
    
    handler->config_world(world);
    
    if (_bird == nullptr)
    {
        bird = std::make_shared<Bird>(
            Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,
            Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT
        );
    }
    else
    {
        bird = _bird;
    }
    if(!bird->get_mode())
        powerup = nullptr;
    else
    {
        Settings::music.pause();
        Settings::music2.play();
        powerup = std::make_shared<Powerup>(Settings::VIRTUAL_WIDTH + 100, Settings::VIRTUAL_HEIGHT + 100);
        powerup->take_powerup();
    }
    handler->config_powerup(probability_powerups);
}

void PlayingState::handle_inputs(const sf::Event& event) noexcept
{
    handler->handle_inputs(event, bird);
    
    if (event.key.code == sf::Keyboard::Space)
    {
        Settings::music.pause();
        Settings::music2.pause();
        Settings::sounds["pause"].play();
        state_machine->change_state("pause", world, bird, handler);
    }
}

void PlayingState::update(float dt) noexcept
{
    std::uniform_real_distribution<float> dist_p{0.f, 100.f};
    float p = dist_p(rng);    
    bird->update(dt);
    world->update(dt);

    if (world->update_scored(bird->get_collision_rect()))
    {
        world->increase_score();
        Settings::sounds["score"].play();
    }

    if (powerup)
    {
        powerup->update(dt);

        if (powerup->collides(bird->get_collision_rect()) && !powerup->is_active())
        {
            Settings::music.pause();
            Settings::sounds["powerup"].play();
            Settings::music2.play();
            bird->set_sprite(1, 38.f, 27.f);
            powerup->take_powerup();
        }

        if (world->collides(bird->get_collision_rect()) && !powerup->is_active())
        {
            Settings::sounds["explosion"].play();
            Settings::sounds["hurt"].play();
            Settings::music.pause();
            Settings::music2.pause();
            state_machine->change_state("game_over", world, bird, handler);
        }

        if(powerup->is_out_of_game())
        {
            powerup = nullptr;
        }

        if (powerup && powerup->is_active() && powerup->get_time() == 0)
        {
            bird->set_sprite(0, 38.f, 27.f);
            Settings::music2.pause();
            Settings::sounds["powerdown"].play();
            Settings::music.play();
            powerup = nullptr;
        }
    }
    else
    {
        if (world->collides(bird->get_collision_rect()))
        {
            Settings::sounds["explosion"].play();
            Settings::sounds["hurt"].play();
            Settings::music.pause();
            Settings::music2.pause();
            state_machine->change_state("game_over", world, bird, handler);
        }
        
        if (p <= probability_powerups && !powerup)
        {
            std::uniform_int_distribution<int> dist{0, Settings::VIRTUAL_HEIGHT};
            float y = dist(rng);
            powerup = std::make_shared<Powerup>(Settings::VIRTUAL_WIDTH, y);
        }
    }
}

void PlayingState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    
    if (powerup)
    {
        if (!powerup->is_active())
        {
            powerup->render(target);
        }   
    }
    
    render_text(target, 20, 10, "Score: " + std::to_string(world->get_score()), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
    render_text(target, Settings::VIRTUAL_WIDTH - Settings::VIRTUAL_WIDTH / 3, 10, "Press Space to Pause", Settings::LOW_TEXT_SIZE, "font", sf::Color::White, false);
    if (world->get_level_limit() > 40)
    {
        render_text(target, Settings::VIRTUAL_WIDTH - Settings::VIRTUAL_WIDTH / 3, 25, "Press A or D to move", Settings::LOW_TEXT_SIZE, "font", sf::Color::White, false);
    }
}
