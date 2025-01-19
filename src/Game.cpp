#include "Game.h"

Game::Game()
	: window(sf::VideoMode({ 1920u, 1080u }), "Baby Bird") {
	window.setFramerateLimit(144);

	auto bird = std::make_shared<Entity>();
	auto birdSprite = std::make_shared<SpriteComponent>();
	birdSprite->sprite.setRadius(20.f);
	birdSprite->sprite.setPosition(sf::Vector2f(100.f, 500.f));

	bird->addComponent(birdSprite);
	renderSystem.addEntity(bird);
}

void Game::processEvents() {
	while (const std::optional event = window.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			window.close();
		}
	}
}

void Game::update(float deltaTime) {
	renderSystem.update(deltaTime);
}

void Game::render() {
	window.clear();
	renderSystem.render(window);
	window.display();
}

void Game::run() {
	while (window.isOpen()) {
		processEvents();
		update(0.016f);
		render();
	}
}
