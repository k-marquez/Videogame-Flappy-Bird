/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class StateMachine.
*/

#include <src/states/StateMachine.hpp>

StateMachine::StateMachine(const std::initializer_list<std::pair<std::string, StateBuilder>>& init_states) noexcept
    : states{init_states.begin(), init_states.end()}, game_mode{"normal"}
{

}

void StateMachine::change_state(const std::string& state_name, std::shared_ptr<World> world, std::shared_ptr<Bird> bird, std::string _game_mode) noexcept
{
    auto it = states.find(state_name);

    if (it == states.end())
    {
        return;
    }

    current_state->exit();
    current_state = it->second(this);
    current_state->enter(world, bird);
}

void StateMachine::handle_inputs(const sf::Event& event) noexcept
{
    current_state->handle_inputs(event);
}

void StateMachine::update(float dt) noexcept
{
    current_state->update(dt);
}

void StateMachine::render(sf::RenderTarget& target) const noexcept
{
    current_state->render(target);
}

std::string StateMachine::get_game_mode() const noexcept
{
    return game_mode;
}

void StateMachine::set_game_mode(std::string _game_mode) noexcept
{
    game_mode = _game_mode;
}
