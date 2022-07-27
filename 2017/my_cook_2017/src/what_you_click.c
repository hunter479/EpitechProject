/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** handle buttons on the main menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	check_if_pressed(window_s *w, stage *tmp, int x, int y)
{
	int	r = w->ratio;
	float	s = tmp->scale;

	if (same_strings(w->cur_scene, tmp->scene) != 1)
		return;
	if (x >= (tmp->x + tmp->box.width * s) / r || x <= tmp->x / r)
		return;
	if (y >= (tmp->y + tmp->box.height * s) / r || y <= tmp->y / r)
		return;
	if (same_strings(tmp->class, "button") == 1) {
		w->select = tmp->type;
		tmp->box.left += tmp->box.width;
	}
	if (same_strings(tmp->class, "oneclick") == 1)
		w->select = tmp->type;
	if (same_strings(tmp->class, "food") == 1) {
		w->class_select = tmp->class;
		w->select = tmp->type;
		add_food(&w->game.cur_meal, tmp->texture);
	}
}

void	check_button_pressed(window_s *w)
{
	int	x = w->evt.mouseButton.x;
	int	y = w->evt.mouseButton.y;
	stage	*tmp = &w->scene;

	if (w->evt.mouseButton.button == sfMouseLeft)
		while (tmp != NULL) {
			check_if_pressed(w, tmp, x, y);
			tmp = tmp->next;
		}
}

void	check_wrong_box(window_s *w, stage *tmp)
{
	int	x = w->evt.mouseButton.x;
	int	y = w->evt.mouseButton.y;
	float	s = tmp->scale;
	int	r = w->ratio;

	if (same_strings(w->select, tmp->type) != 1)
		return;
	if (x >= (tmp->x + tmp->box.width * s) / r || x <= tmp->x / r)
		return;
	if (y >= (tmp->y + tmp->box.height * s) / r || y <= tmp->y / r)
		return;
	check_select(w);
}

void	oneclick_blocker(window_s *w, stage *tmp)
{
	if (same_strings(w->cur_scene, tmp->scene) == 1) {
		check_wrong_box(w, tmp);
		if (same_strings(tmp->class, "oneclick") != 1)
			tmp->box.left = 0;
	}
}

void	reset_buttons(window_s *w)
{
	stage	*tmp = &w->scene;

	if (w->evt.mouseButton.button == sfMouseLeft)
		while (tmp != NULL) {
			oneclick_blocker(w, tmp);
			tmp = tmp->next;
		}
	w->select = NULL;
}
