#include "Game.h"
#include "Components/VelocityComponent.h"

Game::Game()
	: window(sf::VideoMode({ 1920u, 1080u }), "Baby Bird") {
	
	RegisterBirdEntity();
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

void Game::RegisterBirdEntity()
{
	auto bird = std::make_shared<Entity>();

	auto birdSprite = std::make_shared<SpriteComponent>("C:\\Repos\\BabyBird\\assets\\bird.png");
	bird->addComponent(birdSprite);

	auto birdVelocity = std::make_shared<VelocityComponent>();
	birdVelocity->dx = 100.f;
	birdVelocity->dy = 0.f;
	bird->addComponent(birdVelocity);

	renderSystem.addEntity(bird);
	movementSystem.addEntity(bird);
}