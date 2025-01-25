#pragma once
#include <vector>
#include <memory>
#include "../Entity.h"
#include "System.h"

class RenderSystem : public System {
    std::vector<std::shared_ptr<Entity>> entities;

public:
    void addEntity(std::shared_ptr<Entity> entity);
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;
};
