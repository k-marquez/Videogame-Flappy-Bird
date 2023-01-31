/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the class HandleInputBirdRegular.
*/

#include <src/HandleInputsBirdRegular.hpp>

HandleInputBirdRegular::HandleInputBirdRegular() noexcept
{

}

void HandleInputBirdRegular::handle_inputs(const sf::Event& event, std::shared_ptr<Bird> bird) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        bird->jump();
    }
}
