/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** animation 3
*/


#include <SFML/Graphics.h>
#include <stdlib.h>
#include <framebuffer.h>
#include <string.h>
#include <math.h>
#include <time.h>

void	v_calc(int *v_x, int *v_y, int x, int y)
{
	if (x + 50 >= WIDTH)
		*v_x *= -1;
	if (x < 50)
		*v_x *= -1;
	if (y + 50 >= HEIGHT)
		*v_y *= -1;
	if (y < 50)
		*v_y *= -1;
}

void	a_3(frameb_t **f, sfRenderWindow **w, sfSprite **s, sfTexture **t)
{
	sfColor		color;
	sfEvent 	event;
	int		*m = malloc(1);
	srand((unsigned long) *m);
	free (m);
	int	x = rand() % WIDTH;
	int	y = rand() % HEIGHT;
	int	v_x = 3;
	int	v_y = 3;

	while (sfRenderWindow_isOpen(*w)) {
		memset((*f)->pixels, 0, WIDTH * HEIGHT * 4);
		v_calc(&v_x, &v_y, x, y);
		draw_circle(50, &(**f), vec(x, y), sfRed);
		x = x + v_x;
		y = y + v_y;
		up(&(*w), &(*f), &(*s), &(*t));
		while (sfRenderWindow_pollEvent(*w, &event))
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(*w);
	}
}