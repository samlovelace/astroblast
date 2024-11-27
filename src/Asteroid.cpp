
#include "Asteroid.h"
#include "constants.h"

Asteroid::Asteroid(sf::Sprite aSprite, float angularVel, float linearVel) : 
    mSprite(aSprite), mIsExploding(false), 
    mAngularVel(angularVel), mLinearVel(linearVel)
{
    

}

Asteroid::~Asteroid()
{
}

void Asteroid::update(float deltaTime)
{
    if(mIsExploding)
    {
        // update to the next frame of the explosion
        if(!mExplosion->update(deltaTime))
        {
            delete mExplosion;
            mIsExploding = false; 
        }
    }
    else
    {
        mSprite.move(sf::Vector2f(0.0f, mLinearVel));
        mSprite.rotate(mAngularVel);
    }
     
}

// Function to check if a sprite is outside the window bounds
bool Asteroid::isSpriteOutsideWindow() 
{
    sf::FloatRect spriteBounds = mSprite.getGlobalBounds();
    sf::FloatRect windowBounds(0.f, 0.f, WINDOW_HEIGHT, WINDOW_WIDTH);

    // Check if the sprite is completely outside the window
    return (spriteBounds.left + spriteBounds.width < windowBounds.left ||   // Outside left
            spriteBounds.left > windowBounds.left + windowBounds.width ||  // Outside right
            spriteBounds.top > windowBounds.top + windowBounds.height);    // Outside bottom
}

void Asteroid::startExplosion()
{
    sf::FloatRect bounds = mSprite.getGlobalBounds();

    float centerX = bounds.left + bounds.width / 2.f;
    float centerY = bounds.top + bounds.height / 2.f;

    mExplosion = new Explosion(sf::Vector2f(centerX, centerY), 300, 300, 12, 0.1f);
    mIsExploding = true;
    mSprite.setPosition(-100.f, -100.f); 
}

bool Asteroid::inCollisionWithOther(std::vector<Asteroid*> others)
{
    for(const auto& other : others)
    {
        if(other->getSprite().getGlobalBounds().intersects(this->getSprite().getGlobalBounds()))
        {
            return true; 
        }
    }

    return false; 
}