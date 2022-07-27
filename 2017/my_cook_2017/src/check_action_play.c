/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Check the action when the game is in the "play" scene
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	check_serve(window_s *w)
{
	if (same_strings(w->game.recipe, w->game.meal) == 1) {
		w->game.score += 10;
		w->game.score_animation = 1;
		w->game.order = NULL;
		w->game.recipe = NULL;
	}
	suppr_meal(&w->game.cur_meal);
	w->game.meal = NULL;
}

void	check_select_play(window_s *w)
{
	if (w->select == NULL)
		return;
	if (same_strings(w->select, "trash") == 1) {
		w->game.meal = NULL;
		suppr_meal(&w->game.cur_meal);
	}
	if (same_strings(w->select, "pause") == 1) {
		pause_game(w);
		w->select = NULL;
	}
	if (same_strings(w->select, "serve") == 1)
		check_serve(w);
	if (w->class_select != NULL) {
		if (same_strings(w->class_select, "food") == 1) {
			w->game.meal = concatenate(w->game.meal, w->select);
			w->class_select = NULL;
		}
	}
	w->select = NULL;
}
