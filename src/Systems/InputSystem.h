#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>
#include <unordered_map>
#include <vector>
#include "../Entity.h"
#include "../Components/InputComponent.h"

// System for processing input and updating input components
class InputSystem {
public:
    void addEntity(std::shared_ptr<Entity> entity);
    void processInput(const sf::Event& event);
    void update(float dt);

private:
    std::vector<std::shared_ptr<Entity>> entities;

    // Function to check if a key is pressed
    bool isKeyPressed(sf::Keyboard::Key key) const;
};
