#include <memory>
#include "RenderSystem.h"
#include "../Components/SpriteComponent.h"
#include "MovementSystem.h"
#include "../Components/VelocityComponent.h"

void MovementSystem::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void MovementSystem::update(float deltaTime) {
    for (auto& entity : entities) {
        auto velocity = entity->getComponent<VelocityComponent>();
        auto sprite = entity->getComponent<SpriteComponent>();
        if (velocity && sprite) {
            sf::Vector2f displacement(velocity->dx * deltaTime, velocity->dy * deltaTime);
            sprite->sprite.move(displacement); // Move by scaled velocity
        }
    }
}

void MovementSystem::render(sf::RenderWindow& window)
{
}
