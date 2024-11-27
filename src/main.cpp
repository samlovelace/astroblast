
#include <cstdio> 
#include "SFML/Graphics.hpp"
#include "TravelingBackground.h"
#include "constants.h"
#include "Spaceship.h"
#include "AsteroidHandler.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Astroblast");

    std::unique_ptr<TravelingBackground> background = std::make_unique<TravelingBackground>(150); 
    std::unique_ptr<Spaceship> spaceship = std::make_unique<Spaceship>("../textures/spaceship.png"); 
    std::unique_ptr<AsteroidHandler> asteroidHandler = std::make_unique<AsteroidHandler>("../textures/asteroids.png"); 
    
    background->init();  

    sf::Clock clock; 

    while(window.isOpen())
    {
        sf::Event e; 
        while(window.pollEvent(e))
        {
            if(sf::Event::Closed == e.type || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close(); 
            } 
        }

         // Get elapsed time
        sf::Time deltaTime = clock.restart();
        float dt = deltaTime.asSeconds();

        spaceship->handleMovement(dt); 
        asteroidHandler->generateAsteroids();
        spaceship->fireLasers(); 
        spaceship->updateLasers(); 
        asteroidHandler->checkForExplodedAsteroids(spaceship->getLasersFired()); 

        window.clear(sf::Color::Black); 

        background->scroll(); 

        for(auto& star : background->getStars())
        {
            window.draw(star->getShape()); 
        }

        window.draw(spaceship->getSprite()); 

        for(auto& laser : spaceship->getLasersFired())
        {
            window.draw(laser); 
        }

        for(auto& asteroid : asteroidHandler->getAsteroids())
        {
            asteroid->update(dt); 
            window.draw(asteroid->getSprite()); 
        }

        for(auto& asteroid : asteroidHandler->getExplodingAsteroids())
        {
            asteroid->getExplosion()->draw(window); 
        }

        window.display(); 

        sf::sleep(sf::milliseconds(50)); 

    }

}