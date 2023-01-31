/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com

    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class HandleInputBirdRegular
*/

#pragma once

#include <SFML/Graphics.hpp>

#include <src/Bird.hpp>
#include <src/HandleInputsBird.hpp>

class HandleInputBirdRegular: public HandleInputBirdBase
{

public:
    HandleInputBirdRegular() noexcept;

    void handle_inputs(const sf::Event& event, std::shared_ptr<Bird> bird) noexcept override;
};