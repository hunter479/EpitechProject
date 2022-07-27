/*
** EPITECH PROJECT, 2018
** init_play
** File description:
** initialise the play scene
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

stage	init_play(stage *play)
{
	FILE	*stream = fopen("config/play", "r");
	size_t	len = 0;
	char	*line = NULL;
	int	i = 0;

	play = NULL;
	while (getline(&line, &len, stream) > 0) {
		while (line[i] != '\0')
			i++;
		add_object(&play, line);
		i = 0;
	}
	fclose(stream);
	return (*play);
}

void	init_pre_play2(window_s *w)
{
	w->game.timer_top = 0;
	w->game.timer_left = 0;
	w->game.score = 0;
	w->game.score_animation = 0;
	w->game.score_alpha = 255;
	w->game.score_y = 600;
	w->game.is_pause = 0;
	w->game.cy = sfClock_create();
	w->game.minutes = 0;
	w->game.hours = 10;
}

void	init_pre_play(window_s *w)
{
	stage	*tmp = &w->scene;

	suppr_stage(&tmp);
	w->scene = init_play(&w->scene);
	w->cur_scene = "play";
	w->loop = 1;
	w->alpha = 255;
	w->game.meal = NULL;
	w->game.cur_meal = NULL;
	w->game.recipe = NULL;
	w->class_select = NULL;
	w->select = NULL;
	init_pre_play2(w);
	w->game.timer = sfClock_create();
}
