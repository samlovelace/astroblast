#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <SFML/Graphics.hpp>

class Explosion {
public:
    Explosion(const sf::Vector2f& position, int frameWidth, int frameHeight, int numFrames, float frameDuration);

    // Update the animation; returns false if the animation is finished
    bool update(float deltaTime);

    // Render the current frame of the explosion
    void draw(sf::RenderWindow& window) const;

    sf::Sprite& getSprite() {return sprite;}

private:
    sf::Sprite sprite;         // Sprite for rendering the explosion
    int frameWidth;            // Width of each frame
    int frameHeight;           // Height of each frame
    int numFrames;             // Total frames in the animation
    float frameDuration;       // Time per frame
    int currentFrame;          // Current frame index
    float elapsedTime;         // Time since the last frame change

    sf::Texture mTexture; 
};

#endif // EXPLOSION_H
