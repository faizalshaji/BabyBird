#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "../Entity.h"

class RenderSystem {
public:
    void addEntity(std::shared_ptr<Entity> entity);
    void update(float dt);
    void render(sf::RenderWindow& window);

private:
    std::vector<std::shared_ptr<Entity>> entities;  // List of entities to render
};
