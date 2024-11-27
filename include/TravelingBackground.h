#ifndef TRAVELINGBACKGROUND_H
#define TRAVELINGBACKGROUND_H

#include "Star.h"
#include <vector>

class TravelingBackground
{
public:
    TravelingBackground(int aNumberOfScrollingStars);
    ~TravelingBackground();

    void init(); 
    void scroll(); 

    std::vector<Star*> getStars() {return mStars;} 


private:
    int mNumberOfStars; 
    std::vector<Star*> mStars; 
    std::vector<sf::Color> mStarColors;

    Star* initStar(); 

};
#endif 

