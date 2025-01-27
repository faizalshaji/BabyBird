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
            spriteComponent->update(dt);  // Update the sprite animation based on the elapsed time
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

                // Ensure the animation's texture is valid
               

                // Update the sprite's position and draw it
                currentAnimation.sprite.setPosition(position->position);
                window.draw(currentAnimation.sprite);
            }
            else {
                std::cerr << "Warning: Missing animation state '" << spriteComponent->currentState << "'.\n";
            }
        }
    }
}

