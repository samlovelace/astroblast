#ifndef ASTEROIDHANDLER_H
#define ASTEROIDHANDLER_H

#include <string> 
#include <SFML/Graphics.hpp>
#include "Asteroid.h"

class AsteroidHandler
{
public:
    AsteroidHandler(std::string aTexturePath);
    ~AsteroidHandler();

    std::vector<Asteroid*> getAsteroids() {return mAsteroids;}

    void generateAsteroids(); 
    void checkForExplodedAsteroids(std::vector<sf::Sprite> aFiredLasers);
    std::vector<Asteroid*> getExplodingAsteroids(); 


private:
    sf::Texture mTexture; 
    std::vector<Asteroid*>  mAsteroids; 
    std::vector<sf::Sprite> mAsteroidSprites; 

};
#endif

