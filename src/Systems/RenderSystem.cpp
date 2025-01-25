#include <memory>
#include "RenderSystem.h"
#include "../Components/SpriteComponent.h"
#include "../Components/PositionComponent.h"
void RenderSystem::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void RenderSystem::update(float dt) {

}

void RenderSystem::render(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        auto sprite = entity->getComponent<SpriteComponent>();
        auto position = entity->getComponent<PositionComponent>();
        if (sprite && position) {
            sprite->sprite.setPosition(position->position);
            window.draw(sprite->sprite);
        }
    }
}
