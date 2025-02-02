struct Animation {
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
        sprite.setTexture(*texture);
        currentFrame = sf::IntRect({ 0, 0 }, { frameWidth, frameHeight });
        sprite.setTextureRect(currentFrame);
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
