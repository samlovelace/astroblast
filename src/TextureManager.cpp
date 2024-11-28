
#include "TextureManager.h"
#include <iostream> 
#include <fstream>

TextureManager::TextureManager(/* args */)
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::loadTextures(std::string aJsonFilePath)
{
    using json = nlohmann::json; 

    // Open the JSON file
    std::ifstream file(aJsonFilePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open textures.json\n";
        return false;
    }

    // Parse the JSON
    json textureData;
    file >> textureData;

    // Access the textures
    for (const auto& object : textureData["textures"]) {
        std::string name = object["name"];
        std::string path = object["path"];
        std::cout << "Texture Name: " << name << ", Path: " << path << "\n";

        std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();  

        if(!texture->loadFromFile(path))
        {
            std::cerr << "Could not load " << name << " texture from " << path << std::endl; 
            return false; 
        }

        mTextures[name] = texture; 
    }

    return true; 
}

std::shared_ptr<sf::Texture> TextureManager::getTexture(std::string aTextureName)
{
    if(mTextures.find(aTextureName) != mTextures.end())
    {
        return mTextures[aTextureName]; 
    }
    else
    {
        std::cerr << "No texture exists for " << aTextureName << std::endl; 
        return nullptr; 
    }
}
