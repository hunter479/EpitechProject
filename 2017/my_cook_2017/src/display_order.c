/*
** EPITECH PROJECT, 2018
** display_order
** File description:
** Display the customer command int the game loop
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	change_timer(window_s *w)
{
	sfTime	t = sfClock_getElapsedTime(w->game.timer);

	if (sfTime_asSeconds(t) >= 0.2f) {
		w->game.timer_left += 100;
		if (w->game.timer_left >= 400) {
			w->game.timer_left = 0;
			w->game.timer_top += 100;
		}
		if (w->game.timer_top >= 200)
			w->game.timer_top = 0;
		sfClock_restart(w->game.timer);
	}
}

void	display_order(window_s *w)
{
	sfSprite	*sprite = sfSprite_create();
	sfTexture	*timer;
	sfIntRect	box = {0, 0, 80, 80};

	box.top = w->game.timer_top;
	box.left = w->game.timer_left;
	timer = sfTexture_createFromFile("assets/timer.png", NULL);
	sfSprite_setTexture(sprite, w->game.order, sfTrue);
	sfSprite_setPosition(sprite, create_vector(1405, 10));
	sfSprite_setScale(sprite, create_vector(1, 1));
	sfRenderWindow_drawSprite(w->window, sprite, NULL);
	sfSprite_setTexture(sprite, timer, sfTrue);
	sfSprite_setTextureRect(sprite, box);
	sfSprite_setPosition(sprite, create_vector(1800, 15));
	sfRenderWindow_drawSprite(w->window, sprite, NULL);
	sfTexture_destroy(timer);
	sfSprite_destroy(sprite);
	change_timer(w);
}
