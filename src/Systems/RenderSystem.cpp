#include "RenderSystem.h"
#include "../Entity.h"
#include "../Components/SpriteComponent.h"
#include "../Components/PositionComponent.h"

void RenderSystem::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void RenderSystem::update(float dt) {
    for (auto& entity : entities) {
        auto spriteComponent = entity->getComponent<SpriteComponent>();
        if (spriteComponent) {
            spriteComponent->update(dt);  // Update the sprite animation based on the elapsed time
        }
    }
}

void RenderSystem::render(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        auto spriteComponent = entity->getComponent<SpriteComponent>();
        auto position = entity->getComponent<PositionComponent>();
        if (spriteComponent && position) {
            spriteComponent->sprite.setPosition(position->position);
            window.draw(spriteComponent->sprite);  // Draw the sprite with the updated animation
        }
    }
}
