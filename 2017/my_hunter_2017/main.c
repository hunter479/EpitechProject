/*
** EPITECH PROJECT, 2017
** my_screensaver
** File description:
** main
*/

#include "framebuffer.h"

int	main(int ac, char **av)
{
	int	id = 0;

	if (ac > 1)
		return (84);
	if (window(id) == -1)
		return (84);
}