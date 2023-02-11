/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class PauseState.
*/
#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PauseState.hpp>

PauseState::PauseState(StateMachine* sm) noexcept
    : BaseState{sm}, curtain{sf::RectangleShape(sf::Vector2f(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT))}
{
    curtain.setFillColor(sf::Color(255, 255, 255, 100));
}

void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, std::shared_ptr<HandleGameModeBase> _handler) noexcept
{
    world = _world;    
    bird = _bird;
    handler = _handler;
}

void PauseState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::Space)
    {
        Settings::sounds["pause"].play();
        state_machine->change_state("playing", world, bird, handler);
        Settings::music.play();
    }
}

void PauseState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    
    target.draw(curtain);
    
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Pause", Settings::HUGE_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, "Press Space to resume", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
}
