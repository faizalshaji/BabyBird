#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <stdexcept>

struct SpriteComponent {
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect currentFrame;  // Rectangle to hold the current frame's coordinates
    float animationSpeed;      // Speed of the animation (time per frame)
    float elapsedTime;         // Elapsed time for the animation timer
    int numFrames;             // Total number of frames in the sprite sheet (total number of frames across all rows)
    int numRows;               // Number of rows in the sprite sheet
    int currentFrameIndex;     // Current frame index (flattened index)
    int frameWidth;            // Width of a single frame
    int frameHeight;           // Height of a single frame

    // Constructor that accepts a texture path, frame size, rows, and total number of frames
    SpriteComponent(const std::string& texturePath, int frameWidth, int frameHeight, int numFrames, int numRows, float animationSpeed = 0.1f) :
        texture(), sprite(texture), currentFrameIndex(0), animationSpeed(animationSpeed), elapsedTime(0), numFrames(numFrames),
        numRows(numRows), frameWidth(frameWidth), frameHeight(frameHeight)
    {
        if (!texture.loadFromFile(texturePath)) {
            throw std::runtime_error("Failed to load texture from " + texturePath);
        }

        // Set the initial frame (first frame of the sprite sheet)
        currentFrame = sf::IntRect({ 0, 0 }, {frameWidth, frameHeight});
        sprite.setTextureRect(currentFrame);
    }

    // Update the sprite animation based on elapsed time
    void update(float dt) {
        elapsedTime += dt;
        if (elapsedTime >= animationSpeed) {
            // Move to the next frame
            currentFrameIndex = (currentFrameIndex + 1) % numFrames;

            // Calculate the row and column of the current frame
            int frameX = (currentFrameIndex % (numFrames / numRows)) * frameWidth;  // Column (X)
            int frameY = (currentFrameIndex / (numFrames / numRows)) * frameHeight;  // Row (Y)

            // Update the texture rect based on the current frame
            currentFrame.position.x = frameX;
            currentFrame.position.y = frameY;
            sprite.setTextureRect(currentFrame);

            // Reset the animation timer
            elapsedTime = 0;
        }
    }
};
