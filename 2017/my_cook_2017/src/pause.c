/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Pause de game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	init_pause(stage *pause)
{
	FILE	*stream = fopen("config/pause", "r");
	size_t	len = 0;
	char	*line = NULL;
	int	i = 0;

	while (getline(&line, &len, stream) > 0) {
		while (line[i] != '\0')
			i++;
		add_object(&pause, line);
		i = 0;
	}
	fclose(stream);
}

void	check_select_pause(window_s *w)
{
	if (w->select == NULL)
		return;
	if (same_strings(w->select, "pause") == 1)
		w->game.is_pause = 0;
	if (same_strings(w->select, "resume") == 1)
		w->game.is_pause = 0;
	if (same_strings(w->select, "menu") == 1) {
		w->game.is_pause = 0;
		w->loop = 0;
	}
	if (same_strings(w->select, "quit") == 1)
		sfRenderWindow_close(w->window);
	w->select = NULL;
}

void	pause_game(window_s *w)
{

	w->game.is_pause = 1;
	w->cur_scene = "pause";
	w->select = NULL;
	while (w->game.is_pause) {
		sfRenderWindow_clear(w->window, sfWhite);
		render(w);
		render_mouse(w);
		check_events(w);
		sfRenderWindow_display(w->window);
		if (!sfRenderWindow_isOpen(w->window))
			w->game.is_pause = 0;
	}
	w->cur_scene = "play";
	w->select = NULL;
}
