
#include "AsteroidHandler.h"
#include "utilities.h"


AsteroidHandler::AsteroidHandler(std::string aTexturePath)
{
    if(!mTexture.loadFromFile(aTexturePath))
    {
        printf("Could not load asteroids texture"); 
    }

    // extract asteroids from texture 
    // Create sprites for individual asteroids by defining sub-rectangles
    sf::Sprite asteroid1(mTexture);
    asteroid1.setTextureRect(sf::IntRect(13, 38, 55, 25)); // Top-left asteroid (64x64 pixels)
    //asteroid1.setPosition(100.f, 100.f); // Position on screen
    asteroid1.setScale(1.4f, 1.4f); 
    // Set the origin to the center of the sprite
    asteroid1.setOrigin(asteroid1.getLocalBounds().width / 2.f, asteroid1.getLocalBounds().height / 2.f);

    sf::Sprite asteroid2(mTexture); 
    asteroid2.setTextureRect(sf::IntRect(30, 100, 60, 57)); // Top-left asteroid (64x64 pixels)
    //asteroid2.setPosition(300.f, 100.f); // Position on screen
    asteroid2.setScale(1.4f, 1.4f); 
    // Set the origin to the center of the sprite
    asteroid2.setOrigin(asteroid2.getLocalBounds().width / 2.f, asteroid2.getLocalBounds().height / 2.f);

    sf::Sprite asteroid3(mTexture); 
    asteroid3.setTextureRect(sf::IntRect(40, 200, 45, 60)); // Top-left asteroid (64x64 pixels)
    //asteroid3.setPosition(500.f, 100.f); // Position on screen
    asteroid3.setScale(1.4f, 1.4f); 
    // Set the origin to the center of the sprite
    asteroid3.setOrigin(asteroid3.getLocalBounds().width / 2.f, asteroid3.getLocalBounds().height / 2.f);

    sf::Sprite asteroid4(mTexture); 
    asteroid4.setTextureRect(sf::IntRect(216, 160, 85, 60)); // Top-left asteroid (64x64 pixels)
    //asteroid4.setPosition(700.f, 100.f); // Position on screen
    asteroid4.setScale(1.4f, 1.4f); 
    // Set the origin to the center of the sprite
    asteroid4.setOrigin(asteroid4.getLocalBounds().width / 2.f, asteroid4.getLocalBounds().height / 2.f);

    mAsteroidSprites.push_back(asteroid1); 
    mAsteroidSprites.push_back(asteroid2); 
    mAsteroidSprites.push_back(asteroid3); 
    mAsteroidSprites.push_back(asteroid4); 
}

AsteroidHandler::~AsteroidHandler()
{
}

void AsteroidHandler::generateAsteroids()
{
    // check if any asteroids have traveled off screen
    for(auto& asteroid : mAsteroids)
    {
        if(asteroid->isSpriteOutsideWindow())
        {
            std::pair<int, int> start = utils::generateRandomPair(); 
            asteroid->getSprite().setPosition(sf::Vector2f(start.first, -start.second)); 
        }
    }

    if(mAsteroids.size() < 10)
    {
        int asteroidSpriteIndex = utils::generateRandomInt(0, 3);
        float angularVel = utils::generateRandomFloat(0.1, 10); 
        float linearVel = utils::generateRandomFloat(0.5, 3.5);
        Asteroid* asteroid = new Asteroid(mAsteroidSprites[asteroidSpriteIndex], angularVel, linearVel);
        
        do
        {
            std::pair<int, int> start = utils::generateRandomPair();   
            asteroid->getSprite().setPosition(sf::Vector2f(start.first, -start.second));

        } while (asteroid->inCollisionWithOther(mAsteroids));
        

        mAsteroids.push_back(asteroid); 
    }
     
}

void AsteroidHandler::checkForExplodedAsteroids(std::vector<sf::Sprite> aFiredLasers)
{
    for(auto& laser : aFiredLasers)
    {
        for(auto& asteroid : mAsteroids)
        {
            if(asteroid->getSprite().getGlobalBounds().intersects(laser.getGlobalBounds()))
            {
                asteroid->startExplosion();
                laser.setPosition(-100.f, -100.f); 
            }
        }

    }
}

std::vector<Asteroid*> AsteroidHandler::getExplodingAsteroids()
{   
    std::vector<Asteroid*> explodingAsteroids; 

    for(auto& asteroid : mAsteroids)
    {
        if(asteroid->isExploding())
        {
            explodingAsteroids.push_back(asteroid); 
        }
    }

    return explodingAsteroids; 
}

