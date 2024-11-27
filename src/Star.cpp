
#include "Star.h"
#include "constants.h"
#include "utilities.h"

Star::Star(std::pair<int, int> aLoc, sf::Color aColor) : 
    mShape(sf::RectangleShape(sf::Vector2f(0, 0))), 
    mColor(aColor), mIsVisible(true)
{
    int size = utils::generateRandomInt(0, 3); 
    mShape.setSize(sf::Vector2f((size * CELL_SIZE)/CELL_SIZE, (size*CELL_SIZE)/CELL_SIZE)); 
    mShape.setFillColor(mColor);
    mShape.setPosition(sf::Vector2f(aLoc.first, aLoc.second)); 
}

Star::~Star()
{
}

void Star::updateColor()
{
    if(!mIsVisible)
    {
        mShape.setFillColor(sf::Color::Black); 
    }
    else
    {
        mShape.setFillColor(mColor); 
    }
}

