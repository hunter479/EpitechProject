/*
** EPITECH PROJECT, 2017
** windows.c
** File description:
** CPool_Day13_2017
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <framebuffer.h>
#include <string.h>
#include <math.h>

void	up(sfRenderWindow **w, frameb_t **f, sfSprite **s, sfTexture **t)
{
	sfRenderWindow_clear(*w, sfBlack);
	sfTexture_updateFromPixels(*t, (*f)->pixels, (*f)->w, (*f)->h, 0, 0);
	sfRenderWindow_drawSprite(*w, *s, NULL);
	sfRenderWindow_display(*w);
}

frameb_t	*framebuffer_create(int width, int height)
{
	frameb_t	*fb;
	fb = malloc(sizeof(*fb));
	fb->pixels = malloc(sizeof(unsigned char) * width * height * 4);
	if (!(fb->pixels))
		return (0);
	fb->w = width;
	fb->h = height;
	memset(fb->pixels, 0, width * height * 4);
	return (fb);
}

void	stg(frameb_t **b, sfSprite **sp, sfTexture **t, sfRenderWindow **w)
{
	*b = framebuffer_create(WIDTH, HEIGHT);
	*sp	= sfSprite_create();
	*t = sfTexture_create(WIDTH, HEIGHT);
	sfSprite_setTexture(*sp, *t, sfTrue);
	sfRenderWindow_setFramerateLimit(*w, 120);
	sfRenderWindow_clear(*w, sfBlack);
}

void	clean(sfSprite **s, sfRenderWindow **w, frameb_t **b, sfTexture **t)
{
	sfSprite_destroy(*s);
	free ((*b)->pixels);
	free (*b);
	sfTexture_destroy(*t);
	sfRenderWindow_destroy (*w);
}

int	window(int id)
{
	sfVideoMode 		m = {WIDTH, HEIGHT, 60};
	sfRenderWindow		*w;
	sfEvent 		event;
	frameb_t		*buff;
	sfSprite 		*sprite;
	sfTexture		*t;

	w = sfRenderWindow_create(m, "screensaver", sfResize | sfClose, NULL);
	if (!w)
		return (84);
	stg(&buff, &sprite, &t, &w);
	game(&buff, &w, &sprite, &t);
	clean(&sprite, &w, &buff, &t);
}