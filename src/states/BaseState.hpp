/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class BaseState.
*/

#pragma once

#include <memory>

#include <SFML/Graphics.hpp>
#include <src/HandleGameMode.hpp>


class StateMachine;
class World;
class Bird;

class BaseState
{
public:
    BaseState(StateMachine* sm) : state_machine(sm) {}

    virtual ~BaseState() {}

    virtual void enter(std::shared_ptr<World> world, std::shared_ptr<Bird> bird, std::shared_ptr<HandleGameModeBase> _handler) noexcept {}

    virtual void exit() noexcept {}

    virtual void handle_inputs(const sf::Event& event) noexcept {}

    virtual void update(float dt) noexcept {}

    virtual void render(sf::RenderTarget& target) const noexcept {}


protected:
    StateMachine* state_machine;
};
