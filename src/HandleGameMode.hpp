/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class HandleGameModeBase.
*/

#pragma once

#include <Settings.hpp>
#include <src/Bird.hpp>
#include <src/World.hpp>

class HandleGameModeBase
{
public:
    HandleGameModeBase() {}

    virtual ~HandleGameModeBase() {}

    virtual void handle_inputs(const sf::Event& event, std::shared_ptr<Bird> bird) noexcept {}
};
