#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <stdexcept>

struct SpriteComponent {
    sf::Texture texture;
    sf::Sprite sprite;

    SpriteComponent(const std::string& texturePath) :
        texture(texturePath), sprite(texture)  
    {
    }
};
