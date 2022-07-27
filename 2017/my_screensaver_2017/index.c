/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** index for -d -h
*/

#include "my.h"

void	list_animation()
{
	my_putstr("1: Apparition of random squares with random color\n");
	my_putstr("2: A disk which goes to left and right\n");
	my_putstr("3: A disk which move and rebounce.\n");
	my_putstr("4: Two disk, one is moving and the other");
	my_putstr("one is traking him\n");
}

void	help_screensaver()
{
	my_putstr("Animation rendering in a CSFML window.\n");
	my_putstr("USAGE\n ./my_screensaver [OPTIONS] animation_id\n");
	my_putstr(" ID of the animation to process (between 1 and 4).\n");
	my_putstr("OPTIONS\n");
	my_putstr(" -d	print the description");
	my_putstr(" of all the animations and quit.\n");
	my_putstr(" -h	print the usage and quit.\n");
}

int	index_screensaver(char c)
{
	if (c == 'h') {
		help_screensaver();
		return (0);
	}
	if (c == 'd') {
		list_animation();
		return (0);
	}
	return (-1);
}