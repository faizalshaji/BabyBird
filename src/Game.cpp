#include "Game.h"
#include "Components/VelocityComponent.h"
#include "Components/PositionComponent.h"

Game::Game()
	: window(sf::VideoMode({ 1920u, 1080u }), "Baby Bird"), spawnerSystem(renderSystem, movementSystem) {

	RegisterEntities();
}

void Game::processEvents() {
	while (const std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window.close();
		}
	}
}

void Game::update(float deltaTime) {
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
	RegisterBirdEntity();
}

void Game::RegisterBirdEntity()
{
	auto bird = std::make_shared<Entity>();

	auto birdPosition = std::make_shared<PositionComponent>(0.f, 350.f);
	bird->addComponent(birdPosition);

	auto birdSprite = std::make_shared<SpriteComponent>("D:\\Repos\\BabyBird\\assets\\bird.jpg",80,456,12);
	bird->addComponent(birdSprite);

	auto birdVelocity = std::make_shared<VelocityComponent>(100.f, 0.f);
	bird->addComponent(birdVelocity);

	renderSystem.addEntity(bird);
	movementSystem.addEntity(bird);
}