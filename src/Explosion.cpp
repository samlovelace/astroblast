#include "Explosion.h"

Explosion::Explosion(const sf::Vector2f& position, int frameWidth, int frameHeight, int numFrames, float frameDuration)
    : frameWidth(frameWidth), frameHeight(frameHeight), numFrames(numFrames), frameDuration(frameDuration), currentFrame(0), elapsedTime(0.f) 
{
    if(!mTexture.loadFromFile("../textures/explode.png"))
    {
        printf("no able to load explode.png\n");
    }
    sprite.setTexture(mTexture);
    sprite.setPosition(position);  
    sprite.setScale(sf::Vector2f(0.35f, 0.35f)); 
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight)); // Start with the first frame
    sf::FloatRect bounds = sprite.getLocalBounds(); 
    sprite.setOrigin(bounds.width/2.f, bounds.height/2.f);
}

bool Explosion::update(float deltaTime) {
    elapsedTime += deltaTime;

    // Check if it's time to move to the next frame
    if (elapsedTime >= frameDuration) {
        elapsedTime -= frameDuration;
        currentFrame++;

        // Stop the animation if all frames have been displayed
        if (currentFrame >= numFrames) {
            return false;
        }

        // Update the texture rectangle to the next frame
        int column = currentFrame % (sprite.getTexture()->getSize().x / frameWidth);
        int row = currentFrame / (sprite.getTexture()->getSize().x / frameWidth);
        sprite.setTextureRect(sf::IntRect(column * frameWidth, row * frameHeight, frameWidth, frameHeight));
    }

    return true; // Animation is still active
}

void Explosion::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}
