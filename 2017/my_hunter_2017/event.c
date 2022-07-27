/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** event
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <framebuffer.h>
#include <string.h>
#include <SFML/Window.h>
#include <time.h>
#include <stdio.h>

void stage(int *v_x, int *v_y, int score)
{
	if (score >= 100) {
		*v_x += 1;
		*v_y += 1;
	}
	if (score >= 200) {
		*v_x += 1;
		*v_y += 1;
	}
	if (score >= 300) {
		*v_x += 2;
		*v_y += 2;
	}
}

int	mouse_event(sfEvent event, target_t track, sfClock *timer)
{
	int	x = event.mouseButton.x;
	int	y = event.mouseButton.y;
	int	nbr = (x - track.x0) * (x - track.x0);
	int	nbr2 = (y - track.y0) * (y - track.y0);
	int	sec = sfTime_asSeconds(sfClock_getElapsedTime(timer));

	if (event.mouseButton.button != sfMouseLeft)
		return (0);
	if ((nbr + nbr2) <= (30 * 30) && sec >= 2 && sec <= 2.3)
		return (25);
	return (-10);
}
