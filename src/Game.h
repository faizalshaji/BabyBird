#pragma once
#include "pch.h"
#include "Entity.h"
#include "Components/SpriteComponent.h"
#include "Systems/System.h"
#include <memory>
#include "Systems/RenderSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/SpawnerSystem.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();
    void RegisterEntities();
    void RegisterBirdEntity();

    sf::RenderWindow window;
    RenderSystem renderSystem;
    MovementSystem movementSystem;
    SpawnerSystem spawnerSystem;
    std::shared_ptr<Entity> bird;
};

