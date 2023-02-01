/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com

    This file contains the definition of the class GameModeState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/GameModeState.hpp>

GameModeState::GameModeState(StateMachine* sm) noexcept
    : BaseState{sm}, world{}, opt1{sf::Color::Yellow}, opt2{sf::Color::White}
{

}

void GameModeState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::Enter)
    {
        state_machine->change_state("count_down");
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
        opt1 = sf::Color::White;
        opt2 = sf::Color::Yellow;
        state_machine->set_game_mode("hard");
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
        opt1 = sf::Color::Yellow;
        opt2 = sf::Color::White;
        state_machine->set_game_mode("regular");
    }
}

void GameModeState::update(float dt) noexcept
{
    world.update(dt);
}

void GameModeState::render(sf::RenderTarget& target) const noexcept 
{
    world.render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 4, "Select Game Mode", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.6 * Settings::VIRTUAL_HEIGHT / 3, "Press Enter to start", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.1 * Settings::VIRTUAL_HEIGHT / 3, "Regular", Settings::MEDIUM_TEXT_SIZE, "font", opt1, true);
    
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.3 * Settings::VIRTUAL_HEIGHT / 3, "Hard", Settings::MEDIUM_TEXT_SIZE, "font", opt2, true);
}
