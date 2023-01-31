/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com
    
    Author: Kevin Márquez
    marquezberriosk@gmail.com

    This file contains the declaration of the class PlayingBaseState.
*/

#pragma once

#include <unordered_map>

#include <src/Bird.hpp>
#include <src/HandleInputsBird.hpp>
#include <src/World.hpp>
#include <src/states/BaseState.hpp>

class PlayingState: public BaseState
{

public:
    PlayingState(StateMachine* sm) noexcept;

    void enter(std::shared_ptr<World> _world = nullptr, std::shared_ptr<Bird> _bird = nullptr) noexcept override;

    void handle_inputs(const sf::Event& event) noexcept override;

    void update(float dt) noexcept override;

    void render(sf::RenderTarget& target) const noexcept override;

private:
    std::shared_ptr<Bird> bird;
    std::shared_ptr<World> world;
    
    std::string bird_mode;
    
    std::unordered_map<std::string, std::shared_ptr<HandleInputBirdBase>> bird_handler;
};
