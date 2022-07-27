/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Functions used to render the settings menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

stage	init_settings(stage *settings)
{
	FILE	*stream = fopen("config/settings", "r");
	size_t	len = 0;
	char	*line = NULL;
	int	i = 0;

	settings = NULL;
	while (getline(&line, &len, stream) > 0) {
		while (line[i] != '\0')
			i++;
		add_object(&settings, line);
		i = 0;
	}
	fclose(stream);
	return *settings;
}

void	init_pre_settings(window_s *w)
{
	w->scene = init_settings(&w->scene);
	w->cur_scene = "settings";
	w->loop = 1;
	w->alpha = 255;
}

void	settings(window_s *w)
{
	stage	*tmp = &w->scene;

	suppr_stage(&tmp);
	init_pre_settings(w);
	while (w->loop) {
		sfRenderWindow_clear(w->window, sfWhite);
		render(w);
		render_mouse(w);
		sfRenderWindow_display(w->window);
		check_events(w);
		if (!sfRenderWindow_isOpen(w->window))
			w->loop = 0;
	}
	tmp = &w->scene;
	suppr_stage(&tmp);
	w-> scene = init_menu(&w->scene);
	w->cur_scene = "menu";
	w->alpha = 255;
}
