#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <nlohmann/json.hpp>
#include "SFML/Graphics.hpp"


class TextureManager
{
public:
    TextureManager(/* args */);
    ~TextureManager();

    bool loadTextures(std::string aTexturesFilePath); 
    std::shared_ptr<sf::Texture> getTexture(std::string aTextureName); 


private:
    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> mTextures; 
};

#endif
