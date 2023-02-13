//
//  AudioComponent.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/11/23.
//

#pragma once
#include <string>
#include <iostream>
#include <SDL2_mixer/SDL_mixer.h>
#include "EntityComponentSystem.hpp"
#include <SDL2/SDL.h>
#include <map>

using sounds_maps = std::map<std::string, Mix_Chunk*>;
using music_maps = std::map<std::string, Mix_Music*>;


class AudioComponent : public Component {
private:
    music_maps music_map;
    sounds_maps sound_map;
    
    static const int _MIX_DEFAULT_FREQUNECY = 44100;
    static const int _MIX_CHANNEL_STEREO = 2;
    static const int _MIX_CHANNEL_MONO = 1;
    static const int _MIX_CHUNK_SIZE = 2048;
    static const int _MIX_LOOP_INF = -1;
    static const int _MIX_CHANNEL = -1;
    static const int _MIX_PLAY_ONCE = 0;
public:
    
    void Clean();
    AudioComponent() {
        Mix_OpenAudio(_MIX_DEFAULT_FREQUNECY, MIX_DEFAULT_FORMAT, _MIX_CHANNEL_STEREO, _MIX_CHUNK_SIZE);
    }
    
    void PlayMusic(std::string song_id) {
        if (Mix_PlayMusic(music_map[song_id], -1) == -1) {
            std::cerr << song_id << "could not be played!" <<std::endl;
        }
    }
    void LoadMusic(std::string song_id, std::string source) {
        Mix_Music* song = Mix_LoadMUS(source.c_str());
        if (song != nullptr) {
            music_map[song_id] = song;
        } else {
            std::cerr << song_id << "could not be loaded!" <<std::endl;
        }
    }
    
    void PlayEffect(std::string effect_id) {
        if (Mix_PlayChannel(_MIX_CHANNEL, sound_map[effect_id], _MIX_PLAY_ONCE)== -1) {
            std::cerr << effect_id << "could not be played!" <<std::endl;
        }
    }
    void LoadEffect(std::string effect_id, std::string source) {
        Mix_Chunk* effect = Mix_LoadWAV(source.c_str());
        if (effect != nullptr) {
            sound_map[effect_id] = effect; 
        } else {
            std::cerr << effect_id << "could not be loaded!" <<std::endl;
        }
    }
    

   
    
};


//TODO: init audio mix, load music / sound effect. then function to play said music and sound effect
