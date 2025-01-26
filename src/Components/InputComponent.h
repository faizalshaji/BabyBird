#pragma once
#include <SFML/System/Vector2.hpp>

// Component for storing input-related data (e.g., velocity)
struct InputComponent {
    sf::Vector2f velocity;  // Velocity based on input
    float speed;            // Movement speed for the entity

    InputComponent(float movementSpeed = 200.0f)
        : velocity(0.f, 0.f), speed(movementSpeed) {
    }
};
