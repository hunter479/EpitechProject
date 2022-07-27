/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Add or delete the food list in my_cook
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	add_food(meal_s **cur_meal, sfTexture *texture)
{
	meal_s	*elem;
	meal_s	*tmp = *cur_meal;

	elem = malloc(sizeof(*elem));
	elem->texture = texture;
	elem->x = 650;
	elem->y = 720;
	elem->scale = 1;
	elem->next = NULL;
	if (*cur_meal == NULL) {
		*cur_meal = elem;
		return;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
}

void	suppr_meal(meal_s **cur_meal)
{
	*cur_meal = NULL;
}
