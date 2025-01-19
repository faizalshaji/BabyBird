#pragma once
#include "../pch.h"
#include <vector>
#include <memory>
#include "../Entity.h"

class System {
public:
    virtual void update(float dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};
