/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** play loop
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	render_meal(window_s *w)
{
	meal_s	*tmp = w->game.cur_meal;
	sfSprite	*s = sfSprite_create();
	int	y = 0;

	sfSprite_setScale(s, create_vector(1.5, 1.5));
	while (tmp != NULL) {
		sfSprite_setTexture(s, tmp->texture, sfTrue);
		sfSprite_setPosition(s, create_vector(tmp->x, tmp->y + y));
		sfRenderWindow_drawSprite(w->window, s, NULL);
		tmp = tmp->next;
		y -= 20;
	}
	sfSprite_destroy(s);
}

int	cycle_game(window_s *w)
{
	if (sfTime_asMilliseconds(sfClock_getElapsedTime(w->game.cy)) > 500) {
		if (w->game.minutes >= 59) {
			w->game.hours += 1;
			w->game.minutes = 0;
		} else
			w->game.minutes += 1;
		sfClock_restart(w->game.cy);
	}
	return (0);
}

int	count_recipes(void)
{
	int	i = 0;
	FILE	*stream = fopen("config/commands", "r");
	size_t	len = 0;
	char	*line = NULL;

	while (getline(&line, &len, stream) > 0)
		i++;
	fclose(stream);
	return (i);
}

void	load_orders(window_s *w)
{
	int	nb_recipes = count_recipes();
	FILE	*stream = fopen("config/commands", "r");
	size_t	len = 0;
	int	i;
	char	*line = NULL;

	if (w->game.recipe != NULL) {
		fclose(stream);
		return;
	}
	srand(w->game.minutes);
	i = rand() % nb_recipes + 1;
	while (i != 0) {
		getline(&line, &len, stream);
		i--;
	}
	w->game.order = sfTexture_createFromFile(cut_text(&i, line), NULL);
	w->game.recipe = cut_text(&i, line);
	fclose(stream);
}

void	play(window_s *w)
{
	stage	*tmp = &w->scene;

	init_pre_play(w);
	while (w->loop && w->game.hours != 14) {
		sfRenderWindow_clear(w->window, sfWhite);
		load_orders(w);
		render(w);
		display_score(w);
		render_mouse(w);
		cycle_game(w);
		sfRenderWindow_display(w->window);
		check_events(w);
		if (!sfRenderWindow_isOpen(w->window))
			w->loop = 0;
	}
	suppr_meal(&w->game.cur_meal);
	suppr_stage(&tmp);
	w->scene = init_menu(&w->scene);
	w->cur_scene = "menu";
	w->alpha = 255;
}
