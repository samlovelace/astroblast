#ifndef STAR_H
#define STAR_H

#include <SFML/Graphics.hpp>

class Star
{
public:
    Star(std::pair<int, int> aLoc, sf::Color aColor);
    ~Star();

    sf::RectangleShape& getShape() {return mShape; }
    bool isVisible() {return mIsVisible; }
    void setVisibility(bool aVisibleFlag) {mIsVisible = aVisibleFlag; updateColor(); }
private:
    sf::RectangleShape mShape; 
    sf::Color mColor;
    bool mIsVisible; 

    void updateColor(); 

};
#endif