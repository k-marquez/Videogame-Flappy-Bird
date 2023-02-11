/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class TitleScreenState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/TitleScreenState.hpp>

TitleScreenState::TitleScreenState(StateMachine* sm) noexcept
    : BaseState{sm}, world{}
{

}

void TitleScreenState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::Enter)
    {
        Settings::sounds["select"].play();
        state_machine->change_state("game_mode", std::make_shared<World>());
    }
}

void TitleScreenState::update(float dt) noexcept
{
    world.update(dt);
}

void TitleScreenState::render(sf::RenderTarget& target) const noexcept 
{
    world.render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Flappy Bird", Settings::HUGE_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, "Press         to start", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2 * Settings::VIRTUAL_HEIGHT / 3, "Enter", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::Yellow, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.4 * Settings::VIRTUAL_HEIGHT / 3, "Press          to exit", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.4 * Settings::VIRTUAL_HEIGHT / 3, "Escape", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::Yellow, true);
}
