#include "InputSystem.h"
#include "../Components/VelocityComponent.h"
#include "../Components/SpriteComponent.h"

void InputSystem::addEntity(std::shared_ptr<Entity> entity) {
    entities.push_back(entity);
}

void InputSystem::processInput(const sf::Event& event) {

}

void InputSystem::update(float dt) {
    for (auto& entity : entities) {
        auto inputComponent = entity->getComponent<InputComponent>();
        auto velocityComponent = entity->getComponent<VelocityComponent>();
        auto spriteComponent = entity->getComponent<SpriteComponent>();

        if (inputComponent && velocityComponent && spriteComponent) {
            float dx = 0.f, dy = 0.f;
            bool isMoving = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
                spriteComponent->setState("attack");
                continue;
            }


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

                auto& sprite = spriteComponent->animations[spriteComponent->currentState].getSprite();

                if (sprite.getScale().x > 0.f) {
                    auto width = sprite.getLocalBounds().size.x;
                    sprite.setOrigin({ width , 0.f });
                    sprite.setScale({ -1.f, 1.f });
                }

                isMoving = true;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                dx += 1.f;
                spriteComponent->setState("run");

                auto& sprite = spriteComponent->animations[spriteComponent->currentState].getSprite();

                if (sprite.getScale().x < 0.f) {
                    sprite.setOrigin({ 0.f, 0.f });
                    sprite.setScale({ 1.f, 1.f });
                }

                isMoving = true;
            }


            if (!isMoving) {
                spriteComponent->setState("idle");
                spriteComponent->animations[spriteComponent->currentState].getSprite().setScale(sf::Vector2f(1.f, 1.f));
            }

            float length = std::sqrt(dx * dx + dy * dy);
            if (length > 0.f) {
                dx /= length;
                dy /= length;
            }

            velocityComponent->dx = dx * 200.f;
            velocityComponent->dy = dy * 200.f;
        }
    }
}



bool InputSystem::isKeyPressed(sf::Keyboard::Key key) const {
    return sf::Keyboard::isKeyPressed(key);
}
