#pragma once

struct PositionComponent {
    sf::Vector2f position;

    PositionComponent(float x = 0.f, float y = 0.f) : position(x, y) {}
};