/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class HandleInputBirdBase.
*/

#pragma once

#include <Settings.hpp>
#include <src/Bird.hpp>

class HandleInputBirdBase
{
public:
    HandleInputBirdBase() {}

    virtual ~HandleInputBirdBase() {}

    virtual void handle_inputs(const sf::Event& event, std::shared_ptr<Bird> bird) noexcept {}
};
