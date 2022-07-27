/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Loop of the game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	destroy_everything(window_s *w)
{
	stage	*tmp = &w->scene;

	suppr_stage(&tmp);
	free(w->select);
	sfRenderWindow_destroy(w->window);
	sfMusic_destroy(w->audio.theme);
}

void	launch_menu(window_s *w)
{
	w->scene = init_menu(&w->scene);
	while (sfRenderWindow_isOpen(w->window)) {
		sfRenderWindow_clear(w->window, sfWhite);
		check_events(w);
		render(w);
		render_mouse(w);
		sfRenderWindow_display(w->window);
	}
	destroy_everything(w);
}

void	prepare_game(void)
{
	window_s	window = init_window(window);

	launch_menu(&window);
}
