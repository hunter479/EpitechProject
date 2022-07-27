/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** the beginning of everything
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "radar.h"
#include <string.h>

int	usage(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	if (i == 2 && str[0] == '-' && str[1] == 'h') {
		my_printf("%s\n\n", "Air traffic simulation panel.");
		my_printf("%s\n%s\n\n\n", "USAGE", "./myradar");
	}
	else
		return (-1);
}

void	close_w(game_t *game)
{
	if (game->event.type == sfEvtClosed)
		sfRenderWindow_close(game->w);
}

int	window(game_t game)
{
	sfVideoMode 	m = {WIDTH, HEIGHT, 60};

	game.w = sfRenderWindow_create(m, "my_radar", sfResize | sfClose, NULL);
	if (!(game.w))
		return (84);
	stg(&game);
	while (sfRenderWindow_isOpen(game.w)) {
		up(&game);
		while (sfRenderWindow_pollEvent(game.w, &game.event))
			close_w(&game);
	}
	return (0);
}

int	main(int ac, char **av)
{
	game_t	game;

	if (ac > 2)
		return (84);
	if (ac == 2)
		if (usage(av[1]) == 1)
			return (0);
	if (window(game) == 84)
		return (84);
}