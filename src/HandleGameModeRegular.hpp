/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com

    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the declaration of the class HandleGameModeRegular
*/

#pragma once

#include <SFML/Graphics.hpp>

#include <src/Bird.hpp>
#include <src/HandleGameMode.hpp>

class HandleGameModeRegular: public HandleGameModeBase
{

public:
    HandleGameModeRegular() noexcept;

    void handle_inputs(const sf::Event& event, std::shared_ptr<Bird> bird) noexcept override;
};
