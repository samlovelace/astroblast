#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <algorithm>
#include <random>
#include "constants.h"

namespace utils
{
    inline std::pair<int, int> generateRandomPair()
    {
        // Create random number generators
        std::random_device rd;
        std::mt19937 gen(rd());

        // Define the range for the x and y positions (0 to GRID_WIDTH-1, and 0 to GRID_HEIGHT-1)
        std::uniform_int_distribution<> disX(0, WINDOW_WIDTH);
        std::uniform_int_distribution<> disY(0, WINDOW_HEIGHT);

        int x = disX(gen); 
        int y = disY(gen); 

        std::pair<float, float> coord = std::make_pair(x, y);  

        return coord; 
    }


    inline int generateRandomInt(int min, int max)
    {
        // Create random number generators
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> disX(min, max);
        int x = disX(gen);
        return x; 
    }

    inline float generateRandomFloat(float min, float max)
    {

        // Create random number generators
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> disX(min, max);
        float x = disX(gen);
        return x;
    }
}

#endif