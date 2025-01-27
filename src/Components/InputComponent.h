#pragma once
#include <SFML/System/Vector2.hpp>

struct InputComponent {
    sf::Vector2f velocity;
    float speed; 

    InputComponent()
        : velocity(0.f, 0.f), speed(200.f) {
    }
};
