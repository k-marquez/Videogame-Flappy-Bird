/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com

    This file contains the definition of the class PauseBaseState.
*/
#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PauseState.hpp>

PauseState::PauseState(StateMachine* sm) noexcept
    : BaseState{sm}
{

}

void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
{
    world = _world;    
    bird = _bird;
    
    curtain = sf::RectangleShape(sf::Vector2f(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT));
    curtain.setFillColor(sf::Color(255, 255, 255, 100));
}

void PauseState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::Space)
    {
        Settings::sounds["pause"].play();
        state_machine->change_state("playing", world, bird);
    }
}

void PauseState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    
    target.draw(curtain);
    
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "PAUSE", Settings::HUGE_TEXT_SIZE, "flappy", sf::Color::White, true);
}
