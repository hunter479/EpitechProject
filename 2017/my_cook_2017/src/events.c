/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Handle events
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	set_pause(window_s *w)
{
	if (same_strings(w->cur_scene, "play") == 1)
		pause_game(w);
	if (same_strings(w->cur_scene, "pause") == 1)
		w->game.is_pause = 0;
}

void	play_events(window_s *w)
{
	int	check1 = same_strings(w->cur_scene, "play");
	int	check2 = same_strings(w->cur_scene, "pause");

	if (check1 != 1 && check2 != 1)
		return;
	if (w->evt.type == sfEvtKeyPressed) {
		if (w->evt.key.code == sfKeyEscape)
			set_pause(w);
	}
}

void	check_events(window_s *w)
{
	while (sfRenderWindow_pollEvent(w->window, &w->evt)) {
		if (w->evt.type == sfEvtClosed)
			sfRenderWindow_close(w->window);
		if (w->evt.type == sfEvtMouseMoved) {
			w->x_mouse = w->evt.mouseMove.x;
			w->y_mouse = w->evt.mouseMove.y;
		}
		if (w->evt.type == sfEvtMouseButtonReleased == sfMouseLeft)
			check_button_pressed(w);
		else if (w->evt.type == sfEvtMouseButtonPressed == sfMouseLeft)
			reset_buttons(w);
		play_events(w);
	}
}
