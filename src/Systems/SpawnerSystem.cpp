#include <memory>
#include <SFML/Graphics.hpp>
#include <random>
#include "../Entity.h"
#include "../Components/SpriteComponent.h"
#include "../Components/PositionComponent.h"
#include "../Components/VelocityComponent.h"
#include "SpawnerSystem.h"

void SpawnerSystem::addEntity(std::shared_ptr<Entity> entity) {

}

void SpawnerSystem::update(float deltaTime) {

    spawnTimer += deltaTime;

    if (spawnTimer >= spawnInterval) {
        spawnPipe();
        spawnTimer = 0.f;
    }
}

void SpawnerSystem::render(sf::RenderWindow& window)
{
}


void SpawnerSystem::spawnPipe() {
    auto pipe = std::make_shared<Entity>();

    //auto pipeSprite = std::make_shared<SpriteComponent>("D:\\Repos\\BabyBird\\assets\\bird.png", 96, 96, 5, 1);
    //pipe->addComponent(pipeSprite);

    auto pipePosition = std::make_shared<PositionComponent>();
    pipePosition->position = sf::Vector2f(600, generateRandomYPosition());
    pipe->addComponent(pipePosition);

    auto pipeVelocity = std::make_shared<VelocityComponent>();
    pipeVelocity->dx = -200.f;
    pipeVelocity->dy = 0.f;
    pipe->addComponent(pipeVelocity);

    renderSystem.addEntity(pipe);
    movementSystem.addEntity(pipe);
}

float SpawnerSystem::generateRandomYPosition() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(300.f, 350.f);
    return dis(gen);
}
