
#include "Spaceship.h"
#include <cmath>

Spaceship::Spaceship(std::string aTexturePath) : mVelocity(sf::Vector2f(0.0f, 0.0f)), 
    mLaserCooldownFilter(0), fired(false)
{
    // load the texture
    if(!mTexture.loadFromFile(aTexturePath))
    {
        printf("Could not load spaceship texture\n"); 
    } 

    mSprite.setTexture(mTexture);
    mSprite.setPosition(400, 650); 
    mSprite.setScale(sf::Vector2f(0.12f, 0.12f));

    if(!mLaserTexture.loadFromFile("../textures/laser.png"))
    {
        printf("could not load laser texture\n"); 
    }

    mLaserSprite.setTexture(mLaserTexture); 
    mLaserSprite.setTextureRect(sf::IntRect(21, 64, 10, 15)); // Top-left asteroid (64x64 pixels)
    //asteroid1.setPosition(100.f, 100.f); // Position on screen
    mLaserSprite.setScale(1.75f, 1.75f);
    mLaserSprite.setPosition(200.f, 200.f);

}

Spaceship::~Spaceship()
{
}

// Handle movement logic
void Spaceship::handleMovement(float dt) {
    // Apply acceleration based on arrow key input
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        mVelocity.x -= acceleration * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        mVelocity.x += acceleration * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        mVelocity.y -= acceleration * dt;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        mVelocity.y += acceleration * dt;
    }

    // Apply friction to reduce mVelocity
    applyFriction(dt);

    // Cap mVelocity to maximum speed
    capVelocity();

    // Update position
    mSprite.move(mVelocity * dt);

    // Rotate spaceship to face movement direction
    if (mVelocity.x != 0 || mVelocity.y != 0) {
        float angle = std::atan2(mVelocity.y, mVelocity.x) * 180.f / 3.14159f; // Radians to degrees
        //mSprite.setRotation(angle); // Adjust offset as needed
    }
}

// Apply friction to reduce mVelocity
void Spaceship::applyFriction(float dt) {
    if (mVelocity.x > 0) {
        mVelocity.x -= friction * dt;
        if (mVelocity.x < 0) mVelocity.x = 0; // Prevent overshooting
    } else if (mVelocity.x < 0) {
        mVelocity.x += friction * dt;
        if (mVelocity.x > 0) mVelocity.x = 0;
    }

    if (mVelocity.y > 0) {
        mVelocity.y -= friction * dt;
        if (mVelocity.y < 0) mVelocity.y = 0;
    } else if (mVelocity.y < 0) {
        mVelocity.y += friction * dt;
        if (mVelocity.y > 0) mVelocity.y = 0;
    }
}

// Cap mVelocity to prevent exceeding max speed
void Spaceship::capVelocity() {
    if (std::abs(mVelocity.x) > maxSpeed) {
        mVelocity.x = (mVelocity.x > 0 ? 1 : -1) * maxSpeed;
    }
    if (std::abs(mVelocity.y) > maxSpeed) {
        mVelocity.y = (mVelocity.y > 0 ? 1 : -1) * maxSpeed;
    }
}

void Spaceship::fireLasers()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        if(mLaserCooldownFilter > 10)
        {
            fired = true; 
            sf::Sprite newLaser(mLaserSprite); 
            newLaser.setPosition(mSprite.getPosition() + sf::Vector2f(28.f, -10.f));

            mLasersFired.push_back(newLaser);

            mLaserCooldownFilter = 0;  
        }
          
    }

    mLaserCooldownFilter++; 
}

void Spaceship::updateLasers()
{
    for(auto& laser : mLasersFired)
    {
        laser.move(sf::Vector2f(0.0f, -20.25f)); 
    }
}