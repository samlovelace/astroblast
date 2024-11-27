#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>

class Spaceship
{
public:
    Spaceship(std::string aTexturePath);
    ~Spaceship();

    void handleMovement(float dt); 
    void fireLasers(); 
    void updateLasers(); 

    sf::Sprite getSprite() {return mSprite;}
    std::vector<sf::Sprite> getLasersFired() {return mLasersFired;}

private:
    sf::Texture mTexture; 
    sf::Sprite mSprite; 

    sf::Texture mLaserTexture;
    sf::Sprite mLaserSprite;  

    std::vector<sf::Sprite> mLasersFired; 

    int mLaserCooldownFilter; 
    bool fired; 
    
    sf::Vector2f mVelocity; 
    const float acceleration = 500.f; // Acceleration in pixels/second²
    const float friction = 200.f;     // Friction to slow the spaceship
    const float maxSpeed = 350.f;     // Maximum speed

    void applyFriction(float dt); 
    void capVelocity(); 
    
};

#endif

