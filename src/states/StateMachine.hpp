/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class StateMachine.
*/

#pragma once

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>

#include <src/states/BaseState.hpp>

class StateMachine
{
public:
    using StateBuilder = std::function<std::shared_ptr<BaseState>(StateMachine*)>;

    StateMachine(const std::initializer_list<std::pair<std::string, StateBuilder>>& init_states = {}) noexcept;
    
    void change_state(const std::string& state_name, std::shared_ptr<World> world = nullptr, std::shared_ptr<Bird> bird = nullptr, std::string _game_mode = "normal") noexcept;

    void handle_inputs(const sf::Event& event) noexcept;
    
    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;
    
    std::string get_game_mode() const noexcept;

    void set_game_mode(std::string _game_mode) noexcept;

private:
    std::string game_mode;

    std::unordered_map<std::string, StateBuilder> states;
    std::shared_ptr<BaseState> current_state{std::make_shared<BaseState>(this)};
};
