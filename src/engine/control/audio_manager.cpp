#include "audio_manager.h"


namespace sheldr {

    AudioManager::AudioManager() {}

    std::map<std::string, sf::SoundBuffer*> AudioManager::audioBuffers;
    std::map<std::string, sf::Sound*> AudioManager::playingSounds;
    std::vector<std::string> AudioManager::order;

    int AudioManager::getLength() {
        return audioBuffers.size();
    }

    sf::SoundBuffer *AudioManager::getAudio(std::string name) {
        if (audioBuffers.find(name) != audioBuffers.end()) {
            return audioBuffers[name];
        } else {
            return nullptr;
        }
    }

    sf::SoundBuffer *AudioManager::getAudio(int index) {
        return getAudio(order.at(index));
    }

    sf::SoundBuffer *AudioManager::loadAudio(std::string name, std::string path) {
        sf::SoundBuffer *audioBuffer = new sf::SoundBuffer();

        if (audioBuffer->loadFromFile(path)) {
            audioBuffers[name] = audioBuffer;
            order.push_back(name);
            return audioBuffers[name];
        } else {
            delete audioBuffer;
            return nullptr;
        }
    }

    void AudioManager::playAudio(std::string name) {
        if (audioBuffers.find(name) != audioBuffers.end()) {
            if (playingSounds.find(name) != playingSounds.end()) {
                playingSounds[name]->stop();
            }

            sf::Sound* sound = new sf::Sound();
             sound->setBuffer(*(audioBuffers[name]));
           sound->play();
           playingSounds[name] = sound;
       }
   }

   void AudioManager::stopAudio(std::string name) {
       if (playingSounds.find(name) != playingSounds.end()) {
           playingSounds[name]->stop();
           delete playingSounds[name];
           playingSounds.erase(name);
       }
   }

   AudioManager::~AudioManager() {
       for (auto& pair : audioBuffers) {
           delete pair.second;
       }

       for (auto& pair : playingSounds) {
           delete pair.second;
       }
   }

}
