#include "RenderSystem.h"
#include "../Entity.h"
#include "../Components/SpriteComponent.h"
#include "../Components/PositionComponent.h"
#include <iostream>

void RenderSystem::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void RenderSystem::update(float dt) {
    for (auto& entity : entities) {
        auto spriteComponent = entity->getComponent<SpriteComponent>();
        if (spriteComponent) {
            if (spriteComponent->animations.find(spriteComponent -> currentState) != spriteComponent->animations.end()) {
                spriteComponent->animations[spriteComponent->currentState].update(dt);
            }
        }
    }
}

void RenderSystem::render(sf::RenderWindow& window) {
    for (auto& entity : entities) {
        auto spriteComponent = entity->getComponent<SpriteComponent>();
        auto position = entity->getComponent<PositionComponent>();

        if (spriteComponent && position) {
            auto animationIt = spriteComponent->animations.find(spriteComponent->currentState);
            if (animationIt != spriteComponent->animations.end()) {
                auto& currentAnimation = animationIt->second;
                currentAnimation.getSprite().setPosition(position->position);
                window.draw(currentAnimation.getSprite());
            }
            else {
                std::cerr << "Warning: Missing animation state '" << spriteComponent->currentState << "'.\n";
            }
        }
    }
}

