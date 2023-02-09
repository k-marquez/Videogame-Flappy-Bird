/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com

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

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

private:
    World world;
    
    sf::Color opt1;
    sf::Color opt2;
    
    std::string select;
    std::unordered_map<std::string, std::shared_ptr<HandleGameModeBase>> handlers;
};
