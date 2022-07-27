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

typedef	struct	track_s {
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}		track_t;

int	index_screensaver(char);
void	up(sfRenderWindow **w, frameb_t **f, sfSprite **s, sfTexture **t);
sfVector2u vec(int, int);
sfColor	color_rdn(sfColor);
void	my_put_pixel(frameb_t *, int, int, sfColor);
void	draw_circle(double, frameb_t *, sfVector2u, sfColor);
void	draw_square(int, frameb_t *, sfVector2u, sfColor);
void	a_1(frameb_t **, sfRenderWindow **, sfSprite **, sfTexture **);
void	a_2(frameb_t **, sfRenderWindow **, sfSprite **, sfTexture **);
void	a_3(frameb_t **, sfRenderWindow **, sfSprite **, sfTexture **);
void	a_4(frameb_t **, sfRenderWindow **, sfSprite **, sfTexture **);
int	window(int);

#endif /* !FRAMEBUFFER_H_ */