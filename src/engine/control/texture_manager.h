#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_


#include <SFML/Graphics.hpp>
#include <string>
#include <map>

namespace sheldr {


    class TextureManager {

        static std::map<std::string, sf::Texture*> textures;
        static std::vector<std::string> order;
        
        TextureManager();

    public:

        ~TextureManager();
        
        static int getLength();

        static sf::Texture *getTexture(std::string name);
        static sf::Texture *getTexture(int index);
        static sf::Texture *loadTexture(std::string name, std::string path);
    };

}

#endif  // DATA_MANAGER_H_