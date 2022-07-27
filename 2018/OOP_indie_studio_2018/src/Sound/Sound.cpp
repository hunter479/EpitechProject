/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Sound
*/

#include "iostream"
#include "Sound.hpp"

Sound::Sound()
{
    #ifndef WIN32
        if (!explosionBuffer.loadFromFile("./media/sounds/explosion.wav"))
            std::cout << "Can't open .wav" << std::endl;
        explosionSound.setBuffer(explosionBuffer);

        if (!gameMusic.openFromFile("./media/sounds/GameMusic.ogg"))
            std::cout << "Can't open .wav" << std::endl;
        gameMusic.setLoop(true);
        gameMusic.setVolume(40);
    #endif
}

Sound::~Sound()
{
}
