/*
** EPITECH PROJECT, 2017
** my_screensaver.c
** File description:
** animation for my_screensaver
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <framebuffer.h>
#include <string.h>
#include <math.h>

void	line_y(int size, int *x, int *y, frameb_t **buff)
{
	sfColor	color;
	size = rand() % size;
	draw_square(size, *buff, vec(*y, *x), color_rdn(color));
}

void	a_1(frameb_t **b, sfRenderWindow **w, sfSprite **s, sfTexture **t)
{
	int	x = 0;
	int	y = 0;
	sfEvent 		event;

	while (sfRenderWindow_isOpen(*w)) {
		line_y(25, &x, &y, &(*b));
		x += 50;
		if (x >= 1080) {
			y += 50;
			x = 0;
		}
		if (y >= 1920)
			y = 0;
		up(&(*w), &(*b), &(*s), &(*t));
		while (sfRenderWindow_pollEvent(*w, &event))
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(*w);
	}
}
