/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Initialise the game window
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"
#include <sys/stat.h>
#include <fcntl.h>

audio_s	init_audio(char *path)
{
	audio_s	audio;

	if (open(path, O_RDONLY) == -1) {
		audio.mute = -1;
		return (audio);
	}
	audio.theme = sfMusic_createFromFile(path);
	sfMusic_setLoop(audio.theme, sfTrue);
	sfMusic_play(audio.theme);
	audio.mute = 0;
	audio.volume = 100;
	return (audio);
}

window_s	init_window(window_s w)
{
	w.width = 1;
	w.height = 1;
	w.ratio = 1;
	w.mode.width = 1920;
	w.mode.height = 1080;
	w.mode.bitsPerPixel = 32;
	w.window = sfRenderWindow_create(w.mode, "my_cook", sfClose, NULL);
	w.fullscreen = 0;
	w.select = NULL;
	w.cur_scene = "menu";
	w.alpha = 255;
	sfRenderWindow_setFramerateLimit(w.window, 60);
	sfRenderWindow_setMouseCursorVisible(w.window, sfFalse);
	w.audio = init_audio("./assets/menu.ogg");
	w.game.cur_meal = NULL;
	return w;
}
