/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Sound
*/

#ifndef SOUND_HPP_
#define SOUND_HPP_

#include "SFML/Audio.hpp"

class Sound {
	public:
		Sound();
		~Sound();

                void    playBombExplosion(void) { explosionSound.play(); };
                void    playGameMusic(void) { gameMusic.play(); };

	private:
        // EXPLOSION
                sf::SoundBuffer explosionBuffer;
                sf::Sound       explosionSound;
        // MUSIC
                sf::Music       gameMusic;
};

#endif /* !SOUND_HPP_ */
