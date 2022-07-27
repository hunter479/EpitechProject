/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** animation 2
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <framebuffer.h>
#include <string.h>
#include <math.h>

void	a_2(frameb_t **f, sfRenderWindow **w, sfSprite **s, sfTexture **t)
{
	sfColor	color;
	sfEvent 		event;
	int		x = 100;
	int		y = HEIGHT / 2;
	int		v = 3;

	while (sfRenderWindow_isOpen(*w)) {
		if (x + 50 >= WIDTH)
			v *= -1;
		if (x - 50 <= 0)
			v *= -1;
		x += v;
		memset((*f)->pixels, 0, WIDTH * HEIGHT * 4);
		draw_circle(50, &(**f), vec(x, y), sfWhite);
		up(&(*w), &(*f), &(*s), &(*t));
		while (sfRenderWindow_pollEvent(*w, &event))
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(*w);
	}
}