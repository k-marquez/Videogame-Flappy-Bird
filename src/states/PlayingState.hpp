/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class PlayingState.
*/

#pragma once

#include <unordered_map>

#include <src/Bird.hpp>
#include <src/HandleGameMode.hpp>
#include <src/Powerup.hpp>
#include <src/World.hpp>
#include <src/states/BaseState.hpp>

class PlayingState: public BaseState
{

public:
    PlayingState(StateMachine* sm) noexcept;

    void enter(std::shared_ptr<World> _world = nullptr, std::shared_ptr<Bird> _bird = nullptr, std::shared_ptr<HandleGameModeBase> _handler = nullptr) noexcept override;

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

private:
    std::shared_ptr<Bird> bird;
    std::shared_ptr<World> world;
    
    std::shared_ptr<HandleGameModeBase> handler;
    
    std::shared_ptr<Powerup> powerup;
    float probability_powerups{Settings::PROBABILITY};

    std::mt19937 rng;
};
