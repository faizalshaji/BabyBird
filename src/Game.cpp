#include "Game.h"
#include "Components/VelocityComponent.h"
#include "Components/PositionComponent.h"
#include "Components/InputComponent.h"

Game::Game()
	: window(sf::VideoMode({ 1920u, 1080u }), "Baby Bird"), spawnerSystem(renderSystem, movementSystem) {

	RegisterEntities();
}

void Game::processEvents() {
	while (const auto event = window.pollEvent()) {  // pollEvent() returns a std::optional in SFML 3.0
		if (event->is<sf::Event::Closed>()) {       // Use is<>() to check event type
			window.close();
		}
		inputSystem.processInput(*event);           // Dereference the event to pass it to the InputSystem
	}
}


void Game::update(float deltaTime) {
	inputSystem.update(deltaTime);
	movementSystem.update(deltaTime);
	renderSystem.update(deltaTime);
	spawnerSystem.update(deltaTime);
}

void Game::render() {
	window.clear();
	renderSystem.render(window);
	window.display();
}

void Game::run() {
	sf::Clock clock;
	while (window.isOpen()) {
		float deltaTime = clock.restart().asSeconds();
		processEvents();
		update(deltaTime);
		render();
	}
}

void Game::RegisterEntities()
{
	RegisterWorldEntity();
	RegisterPlayerEntity();
}

void Game::RegisterWorldEntity()
{
	auto backgroundEntity = std::make_shared<Entity>();

	//auto backgroundSprite = std::make_shared<SpriteComponent>("D:\\Repos\\BabyBird\\assets\\background.png", 2304, 1296, 1, 1);

	auto backgroundPosition = std::make_shared<PositionComponent>();
	backgroundPosition->position = sf::Vector2f(0.f, 0.f);

	//backgroundEntity->addComponent<SpriteComponent>(backgroundSprite);
	backgroundEntity->addComponent<PositionComponent>(backgroundPosition);

	renderSystem.addEntity(backgroundEntity);

}

void Game::RegisterPlayerEntity() {
	auto player = std::make_shared<Entity>();

	auto position = std::make_shared<PositionComponent>(600.f, 325.f);
	player->addComponent(position);

	// Create a SpriteComponent with animations
	auto sprite = std::make_shared<SpriteComponent>();
	sprite->addAnimation("idle", "D:\\Repos\\BabyBird\\assets\\idle.png", 128, 128, 11, 1, 0.1f);
	sprite->addAnimation("run", "D:\\Repos\\BabyBird\\assets\\walk.png", 128, 128, 8, 1, 0.1f);
	sprite->setState("idle");  // Set initial animation state to "idle"
	player->addComponent(sprite);

	auto input = std::make_shared<InputComponent>(300.f);
	player->addComponent(input);

	auto velocity = std::make_shared<VelocityComponent>(0.f, 0.f);
	player->addComponent(velocity);

	// Add player entity to all relevant systems
	inputSystem.addEntity(player);
	renderSystem.addEntity(player);
	movementSystem.addEntity(player);
}

