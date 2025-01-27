#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <memory>

struct SpriteComponent {
  
    struct Animation {
        std::shared_ptr<sf::Texture> texture; // Shared pointer for the texture
        sf::Sprite sprite;
        int numFrames;
        int numRows;
        int frameWidth;
        int frameHeight;
        float animationSpeed;
        sf::IntRect currentFrame;
        int currentFrameIndex;
        float elapsedTime;

        Animation()
            : texture(std::make_shared<sf::Texture>()),
            sprite(*texture),
            numFrames(1),
            numRows(1),
            frameWidth(1),
            frameHeight(1),
            animationSpeed(0.1f),
            currentFrameIndex(0),
            elapsedTime(0),
            currentFrame(sf::IntRect({ 0, 0 }, { frameWidth, frameHeight })) {
        }

        Animation(const std::string& texturePath, int frameWidth, int frameHeight, int numFrames, int numRows, float animationSpeed)
            : texture(std::make_shared<sf::Texture>()),
            sprite(*texture),
            numFrames(numFrames),
            numRows(numRows),
            frameWidth(frameWidth),
            frameHeight(frameHeight),
            animationSpeed(animationSpeed),
            currentFrameIndex(0),
            elapsedTime(0) {
            if (!texture->loadFromFile(texturePath)) {
                throw std::runtime_error("Failed to load texture from " + texturePath);
            }
            sprite.setTexture(*texture); // Bind the texture to the sprite
            currentFrame = sf::IntRect({ 0, 0 }, { frameWidth, frameHeight });
            sprite.setTextureRect(currentFrame); // Set the initial texture rectangle
        }

        void update(float dt) {
            elapsedTime += dt;
            if (elapsedTime >= animationSpeed) {
                currentFrameIndex = (currentFrameIndex + 1) % numFrames;

                int frameX = (currentFrameIndex % (numFrames / numRows)) * frameWidth;
                int frameY = (currentFrameIndex / (numFrames / numRows)) * frameHeight;

                currentFrame.position.x = frameX;
                currentFrame.position.y = frameY;
                sprite.setTextureRect(currentFrame);

                elapsedTime = 0;
            }
        }
    };


    std::unordered_map<std::string, Animation> animations;  // Map of animations by name
    std::string currentState;                               // Current animation state

    SpriteComponent() : currentState("idle") {}




    void addAnimation(const std::string& name, const std::string& texturePath, int frameWidth, int frameHeight, int numFrames, int numRows, float animationSpeed) {
        animations[name] = Animation(texturePath, frameWidth, frameHeight, numFrames, numRows, animationSpeed);
        if (!animations[name].texture || !animations[name].texture->getNativeHandle()) {
            throw std::runtime_error("Failed to load texture for animation: " + name);
        }
    }

    void setState(const std::string& state) {
        if (animations.find(state) != animations.end()) {
            currentState = state;
        }
        else {
            throw std::runtime_error("Animation state " + state + " not found.");
        }
    }

    void update(float dt) {
        if (animations.find(currentState) != animations.end()) {
            animations[currentState].update(dt);
        }
    }

    void draw(sf::RenderWindow& window) {
        if (animations.find(currentState) != animations.end()) {
            window.draw(animations[currentState].sprite);
        }
    }



};
