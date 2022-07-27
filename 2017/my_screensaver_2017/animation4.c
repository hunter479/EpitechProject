/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** animation 4
*/


#include <SFML/Graphics.h>
#include <stdlib.h>
#include <framebuffer.h>
#include <string.h>
#include <math.h>
#include <time.h>

void	v1_calc(int *v_x, int *v_y, int x, int y)
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

void	began_the_track(track_t *track, int v_x, int v_y)
{
	if (track->x0 > track->x1)
		track->x1 += 2;
	if (track->x0 < track->x1)
		track->x1 -= 2;
	if (track->y0 > track->y1)
		track->y1 += 2;
	if (track->y0 < track->y1)
		track->y1 -= 2;
	track->x0 += v_x;
	track->y0 += v_y;

}

void	init_rand(track_t *track)
{
	int		*m = malloc(1);

	srand((unsigned long) *m);
	free (m);
	track->x0 = rand() % WIDTH;
	track->y0 = rand() % HEIGHT;
	track->x1 = rand() % WIDTH;
	track->y1 = rand() % HEIGHT;

}

void	a_4(frameb_t **f, sfRenderWindow **w, sfSprite **s, sfTexture **t)
{
	sfColor		color;
	sfEvent 	event;
	track_t		track;
	int	v_x = 3;
	int	v_y = 3;
	init_rand(&track);

	while (sfRenderWindow_isOpen(*w)) {
		memset((*f)->pixels, 0, WIDTH * HEIGHT * 4);
		v1_calc(&v_x, &v_y, track.x0, track.y0);
		began_the_track(&track, v_x, v_y);
		draw_circle(50, &(**f), vec(track.x0, track.y0), sfRed);
		draw_circle(30, &(**f), vec(track.x1, track.y1), sfWhite);
		up(&(*w), &(*f), &(*s), &(*t));
		while (sfRenderWindow_pollEvent(*w, &event))
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(*w);
	}
}
