/*
* Класс, отвечающий за проигрыш звуков
*/
#ifndef _CLASS_MUSIC_HPP_
#define _CLASS_MUSIC_HPP_

#include <SDL2/SDL_mixer.h>



class ClassMusic
{
public:

    /*
    * Перечень звуков двигателя
    */
    enum class Sound
    {

    };

    ClassMusic();
    ~ClassMusic();
    static void play(Sound snd);
    static void clear();
private:
    Mix_Chunk** sounds = nullptr;
};

#endif //_CLASS_MUSIC_HPP_
