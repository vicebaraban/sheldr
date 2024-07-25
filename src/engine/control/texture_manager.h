#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_


#include <SFML/Graphics.hpp>
#include <string>
#include <map>

namespace sheldr {


    class TextureManager
    {
    // The textures that are loaded
    static std::map<std::string, sf::Texture*> textures;
        
    // Manually keep track of the order in which textures were loaded, so you can get by index.
    static std::vector<std::string> order;

    // Constructor that is not used
    TextureManager();
    public:
    // Destructor which deletes the textures previously loaded
    ~TextureManager();
        
    static int getLength();

    // Get texutre by name specified in loadTexture, or return null
    static sf::Texture *getTexture(std::string name);
        
    // Get texutre by index in map, or return null
    static sf::Texture *getTexture(int index);
        
    // Loads the texture and returns a pointer to it
    // If it is already loaded, this function just returns it
    // If it cannot find the file, returns NULL
    static sf::Texture *loadTexture(std::string name, std::string path);
    };

}

#endif  // DATA_MANAGER_H_