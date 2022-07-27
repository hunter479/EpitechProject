/*
** EPITECH PROJECT, 2017
** framebuffer
** File description:
** Day13
*/

#ifndef FRAMEBUFFER_H_
	#define FRAMEBUFFER_H_

	#define	WIDTH 	(1920)
	#define	HEIGHT 	(1080)

#include <SFML/Graphics.h>

typedef struct 	framebuffer_s {
	sfUint8 *pixels;
	unsigned int	w;
	unsigned int	h;
}		frameb_t;

typedef struct 	target_s {
	int	x0;
	int	y0;
}		target_t;

void	up(sfRenderWindow **w, frameb_t **, sfSprite **, sfTexture **);
void stage(int *, int *, int);
sfVector2u vec(int, int);
sfColor	color_rdn(sfColor);
void	my_put_pixel(frameb_t *, int, int, sfColor);
void	draw_circle(double, frameb_t *, sfVector2u, sfColor);
void	draw_square(int, frameb_t *, sfVector2u, sfColor);
void	game(frameb_t **, sfRenderWindow **, sfSprite **, sfTexture **);
int	mouse_event(sfEvent, target_t, sfClock *);
int	window(int);

#endif /* !FRAMEBUFFER_H_ */