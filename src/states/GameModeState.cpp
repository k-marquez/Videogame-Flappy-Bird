/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class GameModeState.
*/

#include <Settings.hpp>
#include <src/HandleGameModeHard.hpp>
#include <src/HandleGameModeRegular.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/GameModeState.hpp>
#include <src/text_utilities.hpp>

GameModeState::GameModeState(StateMachine* sm) noexcept
    : BaseState{sm}, opt1{sf::Color::Yellow}, opt2{sf::Color::White}, opt3{sf::Color::White},
      handlers{{"regular",std::make_shared<HandleGameModeRegular>()},{"hard",std::make_shared<HandleGameModeHard>()}}, select{"regular"}
{
}
void GameModeState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, std::shared_ptr<HandleGameModeBase> _handler) noexcept
{
    world = _world;
}

void GameModeState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::Enter)
    {
        Settings::sounds["select"].play();
        state_machine->change_state("count_down", world, nullptr, handlers[select]);
    }
    else if (event.key.code == sf::Keyboard::Up && select == "hard")
    {
        Settings::sounds["change"].play();
        opt1 = sf::Color::Yellow;
        opt2 = sf::Color::White;
        opt3 = sf::Color::White;
        select = "regular";
    }
    else if (event.key.code == sf::Keyboard::Down && select == "regular" || event.key.code == sf::Keyboard::Up  && select == "super")
    {
        Settings::sounds["change"].play();
        opt1 = sf::Color::White;
        opt2 = sf::Color::Yellow;
        opt3 = sf::Color::White;
        select = "hard";
    }
    else if (event.key.code == sf::Keyboard::Down && select == "hard")
    {
        Settings::sounds["change"].play();
        opt1 = sf::Color::White;
        opt2 = sf::Color::White;
        opt3 = sf::Color::Yellow;
        select = "hard";
    }
}

void GameModeState::update(float dt) noexcept
{
    world->update(dt);
}

void GameModeState::render(sf::RenderTarget& target) const noexcept 
{
    world->render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Flappy Bird", Settings::HUGE_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.2 * Settings::VIRTUAL_HEIGHT / 4, "Select Game Mode", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.0 * Settings::VIRTUAL_HEIGHT / 3, "Press Enter to select", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.4 * Settings::VIRTUAL_HEIGHT / 3, "Regular", Settings::MEDIUM_TEXT_SIZE, "font", opt1, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.6 * Settings::VIRTUAL_HEIGHT / 3, "Hard", Settings::MEDIUM_TEXT_SIZE, "font", opt2, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.8 * Settings::VIRTUAL_HEIGHT / 3, "Super Hard", Settings::MEDIUM_TEXT_SIZE, "font", opt3, true);
}
