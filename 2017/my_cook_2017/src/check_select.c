/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** check wich button was clicked
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	check_select_menu(window_s *w)
{
	if (w->select == NULL)
		return;
	if (same_strings(w->select, "play") == 1)
		play(w);
	if (same_strings(w->select, "quit") == 1)
		sfRenderWindow_close(w->window);
	if (same_strings(w->select, "settings") == 1)
		settings(w);
}

void	check_ratio(window_s *w)
{
	if (same_strings(w->select, "960*540") == 1) {
		sfRenderWindow_setSize(w->window, create_vector2u(960, 540));
		w->width = 2;
		w->height = 2;
		w->ratio = 2;
	}
	if (same_strings(w->select, "1920*1080") == 1) {
		sfRenderWindow_setSize(w->window, create_vector2u(1920, 1080));
		w->width = 1;
		w->height = 1;
		w->ratio = 1;
	}
}

void	check_select_settings(window_s *w)
{
	if (w->select == NULL)
		return;
	if (same_strings(w->select, "return") == 1)
		w->loop = 0;
	if (same_strings(w->select, "music") == 1) {
		if (w->audio.mute == 0) {
			w->audio.mute = 1;
			sfMusic_setVolume(w->audio.theme, 0);
		}
		else if (w->audio.mute != -1) {
			w->audio.mute = 0;
			sfMusic_setVolume(w->audio.theme, w->audio.volume);
		}
	}
	check_ratio(w);
}

void	check_select(window_s *w)
{
	if (same_strings(w->cur_scene, "settings") == 1)
		check_select_settings(w);
	if (same_strings(w->cur_scene, "menu") == 1)
		check_select_menu(w);
	if (same_strings(w->cur_scene, "play") == 1)
		check_select_play(w);
	if (same_strings(w->cur_scene, "pause") == 1)
		check_select_pause(w);
}
