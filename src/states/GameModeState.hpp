/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class GameModeState.
*/

#pragma once

#include <unordered_map>

#include <src/World.hpp>
#include <src/states/BaseState.hpp>

class GameModeState: public BaseState
{
public:
    GameModeState(StateMachine* sm) noexcept;

    void enter(std::shared_ptr<World> _world = nullptr, std::shared_ptr<Bird> _bird = nullptr, std::shared_ptr<HandleGameModeBase> _handler = nullptr) noexcept override;

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

private:
    std::shared_ptr<World> world;
    
    sf::Color opt1;
    sf::Color opt2;
    std::string select;
    std::unordered_map<std::string, std::shared_ptr<HandleGameModeBase>> handlers;
};
