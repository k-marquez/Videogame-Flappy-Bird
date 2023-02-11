/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    Author: Kevin Márquez
    marquezberriosk@gmail.com
    
    Author: Lewis Ochoa
    lewis8a@gmail.com

    This file contains the definition of the Settings methods to load multimedia files.
*/

#include <stdexcept>

#include <Settings.hpp>

const fs::path Settings::GRAPHICS_PATH{"graphics"};

const fs::path Settings::SOUNDS_PATH{"sounds"};

const fs::path Settings::FONTS_PATH{"fonts"};

std::unordered_map<std::string, sf::Texture> Settings::textures{};

std::unordered_map<std::string, sf::SoundBuffer> Settings::sound_buffers;

std::unordered_map<std::string, sf::Sound> Settings::sounds{};

std::unordered_map<std::string, sf::Font> Settings::fonts{};

sf::Music Settings::music{};

void Settings::init()
{
    Settings::load_textures();
    Settings::load_sounds();
    Settings::load_fonts();
}

void Settings::load_textures()
{
    sf::Texture texture{};

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "bird.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/bird.png"};
    }

    Settings::textures["bird"] = texture;

     if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "bird2.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/bird2.png"};
    }

    Settings::textures["bird2"] = texture;

     if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "powerup.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/powerup.png"};
    }

    Settings::textures["powerup"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "background.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/background.png"};
    }

    Settings::textures["background"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "ground.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/ground.png"};
    }

    Settings::textures["ground"] = texture;

    if (!texture.loadFromFile(Settings::GRAPHICS_PATH / "log.png"))
    {
        throw std::runtime_error{"Error loading texture graphics/log.png"};
    }

    Settings::textures["Log"] = texture;
}

void Settings::load_sounds()
{
    sf::SoundBuffer buffer;
    sf::Sound sound;
    
    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "jump.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/jump.wav"};
    }

    auto result = Settings::sound_buffers.emplace("jump", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["jump"] = sound;

    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "explosion.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/explosion.wav"};
    }

    result = Settings::sound_buffers.emplace("explosion", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["explosion"] = sound;

    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "hurt.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/hurt.wav"};
    }

    result = Settings::sound_buffers.emplace("hurt", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["hurt"] = sound;

    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "score.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/score.wav"};
    }

    result = Settings::sound_buffers.emplace("score", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["score"] = sound;
    
    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "pause.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/pause.wav"};
    }

    result = Settings::sound_buffers.emplace("pause", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["pause"] = sound;

    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "change.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/change.wav"};
    }

    result = Settings::sound_buffers.emplace("change", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["change"] = sound;

    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "counter.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/counter.wav"};
    }

    result = Settings::sound_buffers.emplace("counter", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["counter"] = sound;

    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "return.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/return.wav"};
    }

    result = Settings::sound_buffers.emplace("return", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["return"] = sound;

    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "select.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/select.wav"};
    }

    result = Settings::sound_buffers.emplace("select", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["select"] = sound;

    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "powerup.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/powerup.wav"};
    }

    result = Settings::sound_buffers.emplace("powerup", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["powerup"] = sound;

    if (!buffer.loadFromFile(Settings::SOUNDS_PATH / "powerdown.wav"))
    {
        throw std::runtime_error{"Error loading sound sounds/powerdown.wav"};
    }

    result = Settings::sound_buffers.emplace("powerdown", buffer);

    sound.setBuffer(result.first->second);
    Settings::sounds["powerdown"] = sound;

    if (!Settings::music.openFromFile(Settings::SOUNDS_PATH / "marios_way.ogg"))
    {
        throw std::runtime_error{"Error loading music sounds/marios_way.ogg"};
    }
}

void Settings::load_fonts()
{
    sf::Font font;

    if (!font.loadFromFile(Settings::FONTS_PATH / "font.ttf"))
    {
        throw std::runtime_error{"Error loading font fonts/font.ttf"};
    }

    Settings::fonts["font"] = font;

    if (!font.loadFromFile(Settings::FONTS_PATH / "flappy.ttf"))
    {
        throw std::runtime_error{"Error loading font fonts/flappy.ttf"};
    }

    Settings::fonts["flappy"] = font;
}
