#ifndef ASTEROID_H
#define ASTEROID_H

#include <SFML/Graphics.hpp>
#include "Explosion.h"

class Asteroid
{
public:
    Asteroid(sf::Sprite aSprite, float angularVel, float linearVel);
    ~Asteroid();

    void update(float deltaTime); 
    void startExplosion(); 
    bool isExploding() {return mIsExploding;}
    Explosion* getExplosion() {return mExplosion; }
    sf::Sprite& getExplosionSprite() {return mExplosion->getSprite();}
    bool inCollisionWithOther(std::vector<Asteroid*> others); 

    bool isSpriteOutsideWindow();

    sf::Sprite& getSprite() {return mSprite; }

private:
    sf::Sprite mSprite;
    bool mIsExploding;
    Explosion* mExplosion; 
    float mAngularVel; 
    float mLinearVel; 
};
#endif 

