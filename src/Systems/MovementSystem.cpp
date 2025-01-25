#include <memory>
#include "RenderSystem.h"
#include "../Components/SpriteComponent.h"
#include "MovementSystem.h"
#include "../Components/VelocityComponent.h"
#include "../Components/PositionComponent.h"

void MovementSystem::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void MovementSystem::update(float deltaTime) {
    for (auto& entity : entities) {
        auto velocity = entity->getComponent<VelocityComponent>();
        auto position = entity->getComponent<PositionComponent>();
        if (velocity && position) {
            position->position.x += velocity->dx * deltaTime;
            position->position.y += velocity->dy * deltaTime;
        }
    }
}

void MovementSystem::render(sf::RenderWindow& window)
{
}
