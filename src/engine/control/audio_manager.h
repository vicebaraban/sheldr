#ifndef AUDIO_MANAGER_H_
#define AUDIO_MANAGER_H_

#include <SFML/Audio.hpp>
#include <string>
#include <map>


namespace sheldr {

    class AudioManager {

        static std::map<std::string, sf::SoundBuffer*> audioBuffers;
        static std::map<std::string, sf::Sound*> playingSounds;
        static std::vector<std::string> order;

        AudioManager();

    public:
        ~AudioManager();

        static int getLength();

        static sf::SoundBuffer *getAudio(std::string name);

        static sf::SoundBuffer *getAudio(int index);

        static sf::SoundBuffer *loadAudio(std::string name, std::string path);

        static void playAudio(std::string name);

        static void stopAudio(std::string name);

    };

}

#endif  // AUDIO_MANAGER_H_
