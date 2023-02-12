/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class HandleGameModeRegular.
*/

#include <src/HandleGameModeRegular.hpp>

HandleGameModeRegular::HandleGameModeRegular() noexcept
    : HandleGameModeBase()
{

}

void HandleGameModeRegular::handle_inputs(const sf::Event& event, std::shared_ptr<Bird> bird) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        bird->jump();
    }
}

void HandleGameModeRegular::config_world(std::shared_ptr<World> _world) noexcept
{
    _world->reset(true);
    _world->resetScore();
    
    _world->set_level_limit(20);
    _world->set_aditional_time_to_spwan(1.75f); 
};

void HandleGameModeRegular::config_powerup(float &_probability) noexcept
{
    _probability = 0.f;
}
