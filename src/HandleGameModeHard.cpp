/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class HandleGameModeHard.
*/

#include <src/HandleGameModeHard.hpp>

HandleGameModeHard::HandleGameModeHard() noexcept
    : HandleGameModeBase()
{

}

void HandleGameModeHard::handle_inputs(const sf::Event& event, std::shared_ptr<Bird> bird) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        bird->jump();
    }
    else if (event.key.code == sf::Keyboard::A)
    {
        bird->move_to_left();
    }
    else if (event.key.code == sf::Keyboard::D)
    {
        bird->move_to_right();
    }
}
