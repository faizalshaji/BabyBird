#include "InputSystem.h"
#include "../Components/VelocityComponent.h"
#include "../Components/SpriteComponent.h"

void InputSystem::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void InputSystem::processInput(const sf::Event& event) {
    // Not needed in this approach as we're directly polling input state
    // Event-based input handling can be implemented here if required
}

void InputSystem::update(float dt) {
    for (auto& entity : entities) {
        auto inputComponent = entity->getComponent<InputComponent>();
        auto velocityComponent = entity->getComponent<VelocityComponent>();
        auto spriteComponent = entity->getComponent<SpriteComponent>();

        if (inputComponent && velocityComponent && spriteComponent) {
            float dx = 0.f, dy = 0.f;
            bool isMoving = false;  // Flag to track if any key is pressed

            // Map keys to movement directions
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
                dy -= 1.f;
                isMoving = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
                dy += 1.f;
                isMoving = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
                dx -= 1.f;
                spriteComponent->setState("run");
                spriteComponent->animations[spriteComponent->currentState].sprite.setScale(sf::Vector2f(-1.f, 1.f)); // Flip horizontally
                isMoving = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                dx += 1.f;
                spriteComponent->setState("run");
                spriteComponent->animations[spriteComponent->currentState].sprite.setScale(sf::Vector2f(1.f, 1.f)); // Default direction
                isMoving = true;
            }

            // If no keys are pressed, set the state to "idle"
            if (!isMoving) {
                spriteComponent->setState("idle");
                spriteComponent->animations[spriteComponent->currentState].sprite.setScale(sf::Vector2f(1.f, 1.f)); // Default to facing right when idle
            }

            // Normalize the direction vector
            float length = std::sqrt(dx * dx + dy * dy);
            if (length > 0.f) {
                dx /= length;  // Normalize dx
                dy /= length;  // Normalize dy
            }

            // Apply the speed from InputComponent
            velocityComponent->dx = dx * inputComponent->speed;
            velocityComponent->dy = dy * inputComponent->speed;
        }
    }
}



bool InputSystem::isKeyPressed(sf::Keyboard::Key key) const {
    return sf::Keyboard::isKeyPressed(key);
}
