/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** animation 4
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"
#include "my.h"
#include <string.h>
#include <SFML/Window.h>
#include <time.h>
#include <stdio.h>

void	v_calc(int *v_x, int *v_y, target_t *target, int score)
{
	if (target->x0 + 30 >= WIDTH)
		*v_x *= -1;
	if (target->x0 < 30)
		*v_x *= -1;
	if (target->y0 + 30 >= HEIGHT)
		*v_y *= -1;
	if (target->y0 < 30)
		*v_y *= -1;
	stage(&(*v_x), &(*v_y), score);
	target->x0 += *v_x;
	target->y0 += *v_y;
}

void	vec_rand(int *v_x, int *v_y)
{
	srand(time(0));
	if ((rand() % 2) == 0)
		*v_x *= -1;
	if ((rand() % 2) == 0)
		*v_y *= -1;
}

void	init_rand(target_t *target)
{
	srand(time(0));
	target->x0 = rand() % WIDTH;
	target->y0 = rand() % HEIGHT;
}

void	draw_it(target_t *track, sfClock **timer, frameb_t **f)
{
	if (sfTime_asSeconds(sfClock_getElapsedTime(*timer)) >= 2)
		draw_circle(30, &(**f), vec(track->x0, track->y0), sfGreen);
	else
		draw_circle(30, &(**f), vec(track->x0, track->y0), sfRed);
	if (sfTime_asSeconds(sfClock_getElapsedTime(*timer)) >= 2.3)
		sfClock_restart(*timer);
}

void	game(frameb_t **f, sfRenderWindow **w, sfSprite **s, sfTexture **t)
{
	sfColor		color;
	sfEvent 	event;
	target_t	track;
	sfClock		*timer = sfClock_create();
	int		v_x = 1;
	int		v_y = 1;
	int		score = 0;

	init_rand(&track);
	vec_rand(&v_x, &v_y);
	while (sfRenderWindow_isOpen(*w)) {
		memset((*f)->pixels, 0, WIDTH * HEIGHT * 4);
		draw_it(&track, &timer, &(*f));
		v_calc(&v_x, &v_y, &track, score);
		track.x0 += v_x;
		track.y0 += v_y;
		up(&(*w), &(*f), &(*s), &(*t));
		while (sfRenderWindow_pollEvent(*w, &event)) {
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(*w);
			else if (event.type == sfEvtMouseButtonPressed)
				score += mouse_event(event, track, timer);
		}
		my_putchar('\r');
		my_putstr("score= ");
		my_put_nbr(score);
		fflush(stdout);
	}
}
