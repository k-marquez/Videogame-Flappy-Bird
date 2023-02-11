/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class GameOverState.
*/
#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/GameOverState.hpp>

GameOverState::GameOverState(StateMachine* sm) noexcept
    : BaseState{sm}, opt1{sf::Color::Yellow}, opt2{sf::Color::White}, select{"replay"}, curtain{sf::RectangleShape(sf::Vector2f(Settings::VIRTUAL_WIDTH, Settings::VIRTUAL_HEIGHT))}
{
    curtain.setFillColor(sf::Color(0, 0, 0, 100));
}

void GameOverState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, std::shared_ptr<HandleGameModeBase> _handler) noexcept
{
    world = _world;    
    bird = _bird;
    handler = _handler;
}

void GameOverState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::Enter)
    {
        if(select == "quit")
        {
            Settings::sounds["return"].play();
            state_machine->change_state("title", nullptr, nullptr, handler);
            Settings::music.play();
        }
        else if(select == "replay")
        {
            bird->reset();
            world->reset(false);
            Settings::sounds["enter"].play();
            state_machine->change_state("count_down", world, nullptr, handler);
            Settings::music.play();
        }
    }
    else if (event.key.code == sf::Keyboard::Down && select != "quit")
    {
        Settings::sounds["change"].play();
        opt1 = sf::Color::White;
        opt2 = sf::Color::Yellow;
        select = "quit";
    }
    else if (event.key.code == sf::Keyboard::Up && select != "replay")
    {
        Settings::sounds["change"].play();
        opt1 = sf::Color::Yellow;
        opt2 = sf::Color::White;
        select = "replay";
    }
}

void GameOverState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    
    target.draw(curtain);
    
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Game Over", Settings::HUGE_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 1.6 * Settings::VIRTUAL_HEIGHT / 3, "You Score: " + std::to_string(world->get_score()), Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.0 * Settings::VIRTUAL_HEIGHT / 3, "Press Enter to select", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.4 * Settings::VIRTUAL_HEIGHT / 3, "Play Again", Settings::MEDIUM_TEXT_SIZE, "font", opt1, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.6 * Settings::VIRTUAL_HEIGHT / 3, "Quit", Settings::MEDIUM_TEXT_SIZE, "font", opt2, true);
}