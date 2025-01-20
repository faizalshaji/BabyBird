#pragma once
#include "pch.h"
#include "Entity.h"
#include "Components/SpriteComponent.h"
#include "Systems/System.h"
#include <memory>
#include "Systems/RenderSystem.h"
#include "Systems/MovementSystem.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();

    sf::RenderWindow window;
    RenderSystem renderSystem;
    MovementSystem movementSystem;
    std::shared_ptr<Entity> bird;
    std::shared_ptr<SpriteComponent> birdSprite;
};

