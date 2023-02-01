/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class PlayingBaseState.
*/

#include <Settings.hpp>
#include <src/HandleInputsBirdHard.hpp>
#include <src/HandleInputsBirdRegular.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PlayingState.hpp>
#include <src/text_utilities.hpp>

PlayingState::PlayingState(StateMachine* sm) noexcept
    : BaseState{sm}
{

}

void PlayingState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
{
    world = _world;
    world->reset(true);
    
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
    
    bird_handler.insert({
        {"normal",std::make_shared<HandleInputBirdRegular>()},
        {"hard",std::make_shared<HandleInputBirdHard>()}});
}

void PlayingState::handle_inputs(const sf::Event& event) noexcept
{
    std::string game_mode = state_machine->get_game_mode(); 
    bird_handler[game_mode]->handle_inputs(event, bird);
    
    if (event.key.code == sf::Keyboard::Space)
    {
        Settings::music.pause();
        Settings::sounds["pause"].play();
        state_machine->change_state("pause", world, bird);
    }
}

void PlayingState::update(float dt) noexcept
{
    bird->update(dt);
    world->update(dt);

    if (world->collides(bird->get_collision_rect()))
    {
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        bird->reset();
        state_machine->change_state("count_down");
    }

    if (world->update_scored(bird->get_collision_rect()))
    {
        world->increase_score();
        Settings::sounds["score"].play();
    }
}

void PlayingState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(world->get_score()), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
    render_text(target, Settings::VIRTUAL_WIDTH - Settings::VIRTUAL_WIDTH / 3, 10, "Press Space to Pause", Settings::LOW_TEXT_SIZE, "font", sf::Color::White, false);
}
