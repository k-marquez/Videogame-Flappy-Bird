/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class HandleInputBirdHard.
*/

#pragma once

#include <src/Bird.hpp>
#include <src/HandleInputsBird.hpp>

class HandleInputBirdHard: public HandleInputBirdBase
{

public:
    HandleInputBirdHard() noexcept;

    void handle_inputs(const sf::Event& event, std::shared_ptr<Bird> bird) noexcept override;
};
