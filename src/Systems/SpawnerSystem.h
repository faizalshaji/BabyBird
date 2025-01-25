#pragma once
#include <vector>
#include <memory>
#include "../Entity.h"
#include "System.h"
#include "RenderSystem.h"
#include "MovementSystem.h"

class SpawnerSystem : public System {
public:
    SpawnerSystem(RenderSystem& renderSys, MovementSystem& moveSys, float interval = 3.0f)
        : renderSystem(renderSys), movementSystem(moveSys), spawnInterval(interval), spawnTimer(0.0f) {
    }

    void addEntity(std::shared_ptr<Entity> entity);
    void update(float dt) override;
    void render(sf::RenderWindow& window) override;

private:
    void spawnPipe();
    float generateRandomYPosition(); // For randomizing pipe heights

    std::vector<std::shared_ptr<Entity>> entities;

    RenderSystem& renderSystem;
    MovementSystem& movementSystem;


    float spawnTimer = 0.f;  // Timer for spawn intervals
    float spawnInterval = 2.f; // Time in seconds between each pipe spawn
};
