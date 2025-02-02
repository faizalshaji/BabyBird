#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <memory>
#include "../Animation/Animation.h"

struct SpriteComponent {

	std::unordered_map<std::string, Animation> animations;
	std::string currentState;

	SpriteComponent() : currentState("idle") {}

	void addAnimation(const std::string& name, const std::string& texturePath, int frameWidth, int frameHeight, int numFrames, int numRows, float animationSpeed) {
		animations[name] = Animation(texturePath, frameWidth, frameHeight, numFrames, numRows, animationSpeed);
	}

	void setState(const std::string& state) {
		if (animations.find(state) != animations.end()) {
			currentState = state;
		}
		else {
			throw std::runtime_error("Animation state " + state + " not found.");
		}
	}
};
