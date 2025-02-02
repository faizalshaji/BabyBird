#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <stdexcept>
#include <string>

class Animation {
private:
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;
    int numFrames;
    int numRows;
    int frameWidth;
    int frameHeight;
    float animationSpeed;
    sf::IntRect currentFrame;
    int currentFrameIndex;
    float elapsedTime;

public:
    Animation();
    Animation(const std::string& texturePath, int frameWidth, int frameHeight, int numFrames, int numRows, float animationSpeed);

    void update(float dt);
    sf::Texture& getTexture();
    sf::Sprite& getSprite();
};
