/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** function which draw in the windows
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <framebuffer.h>
#include <string.h>
#include <math.h>

sfVector2u vec(int x, int y)
{
	sfVector2u	v;

	v.x = x;
	v.y = y;
	return (v);
}

void	my_put_pixel(frameb_t *buffer, int x, int y, sfColor color)
{
	unsigned total = (x + y * buffer->w) * 4;

	if (x >= buffer->w || y >= buffer->h)
		return;
	if (x < 0 || y < 0)
		return;
	buffer->pixels[total + 0] = color.r;
	buffer->pixels[total + 1] = color.g;
	buffer->pixels[total + 2] = color.b;
	buffer->pixels[total + 3] = color.a;
}

void	draw_circle(double s, frameb_t *buff, sfVector2u p, sfColor c)
{
	int	x = -s;
	int	y = -s;

	while (y < s) {
		x = -s;
		while (x ++ < s)
			((x * x) + (y * y) <= (s * s)) ?
		my_put_pixel(buff, p.x + x, p.y + y, c) : 0;
		y += 1;
	}

}

void	draw_square(int size, frameb_t *buff, sfVector2u p, sfColor c)
{
	int	y = -1;
	int	x = -1;

	while (++y < size) {
		x = -1;
		while (++x < size)
			my_put_pixel(buff, p.x + x, p.y + y, c);
	}
}

sfColor	color_rdn(sfColor color)
{
	color.r = rand() % 255;
	color.g = rand() % 255;
	color.b = rand() % 255;
	color.a = 255;
	return (color);
}