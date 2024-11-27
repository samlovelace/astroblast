
#include "TravelingBackground.h"
#include "utilities.h"


TravelingBackground::TravelingBackground(int aNumberOfScrollingStars) : 
    mNumberOfStars(aNumberOfScrollingStars)
{
    mStarColors = {sf::Color::Blue, sf::Color::Red, sf::Color::Yellow, sf::Color::Green};
}

TravelingBackground::~TravelingBackground()
{
}

void TravelingBackground::init()
{
    for(int i = 0; i < mNumberOfStars; i++)
    {
        Star* star = initStar(); 

        mStars.push_back(star);  
    }
}

Star* TravelingBackground::initStar()
{
    std::pair<int,int> loc = utils::generateRandomPair(); 
    int colorIndex = utils::generateRandomInt(0, 3); 

    Star* star = new Star(loc, mStarColors[colorIndex]);

    return star; 

}

void TravelingBackground::scroll()
{
    for(auto it = mStars.begin(); it !=mStars.end(); it++)
    {
        sf::RectangleShape& starShape = (*it)->getShape(); 
        // update the y location of each star 
        if(starShape.getSize().x <= 1.5 && starShape.getSize().y <= 1.5)
        {
            starShape.move(0.0f, (float)CELL_SIZE/2.0); 
        }
        else
        {
            starShape.move(0.0f, 1.25f * (float)CELL_SIZE);
        }

        if(starShape.getPosition().y > WINDOW_HEIGHT)
        {
            mStars.erase(it); 
            mStars.push_back(initStar());        
        }
    }
}
