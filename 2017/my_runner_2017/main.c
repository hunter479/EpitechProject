/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** the beginning of everything
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"
#include <string.h>

int	usage(char *str)
{
	int	i = 0;

	while (str[i] != '\0')
		i++;
	if (i == 2 && str[0] == '-' && str[1] == 'h') {
		my_printf("%s\n\n", "Finite runner created with CSFML.");
		my_printf("%s\n%s\n\n\n", "USAGE", "  ./my_runner map.txt");
		my_printf("%s\n", "OPTIONS");
		my_printf("%s\n", "  -h\t\tprint the usage and quit.");
		my_printf("\n%s\n", "USER INTERACTIONS");
		my_printf("%s\n", "  SPACE_KEY\tjump.");
		my_printf("%s\n", "  Q_KEY\tleft.");
		my_printf("%s\n", "  S_KEY\tright.");
	}
	else
		return (-1);
}

void	jump_player(game_t *game, obs_t *obs, int *i)
{
	if (game->event.mouseButton.button == sfKeySpace) {
		while (game->y > 350) {
			up(game, obs, i);
			sfSprite_setPosition(game->sp, vec(game->x, game->y));
			game->y -= 5;
			jump(game, 2, 3);
		}
		while (game->y < 540) {
			up(game, obs, i);
			sfSprite_setPosition(game->sp, vec(game->x, game->y));
			game->y += 3;
			jump(game, 2, 3);
		}
	}
}

void	games(game_t *game, obs_t *obs)
{
	int		i = 0;

	while (sfRenderWindow_isOpen(game->w)) {
		up(game, obs, &i);
		sfSprite_setPosition(game->sp, vec(game->x, game->y));
		jump(game, 1.3, 2);
		if (game->dead == 1 || DEATH > game->to_time) {
			my_printf("Your score = %d\n", game->score);
			sfRenderWindow_close(game->w);
		}
		while (sfRenderWindow_pollEvent(game->w, &game->event)) {
			if ((*game).event.type == sfEvtClosed)
				sfRenderWindow_close(game->w);
			if ((*game).event.type == sfEvtKeyPressed)
				jump_player(game, obs, &i);
		}
	}
}

int	window(game_t game)
{
	sfVideoMode 	m = {WIDTH, HEIGHT, 60};
	obs_t		*obs = NULL;

	game.w = sfRenderWindow_create(m, "runner", sfResize | sfClose, NULL);
	if (!(game.w))
		return (84);
	stg(&game, &obs);
	games(&game, obs);
	clean(&game);
	return (0);
}

int	main(int ac, char **av)
{
	game_t	game;

	if (ac != 2)
		return (84);
	if (ac == 2) {
		if (usage(av[1]) == 1)
			return (0);
		else if (read_map(av[1], &game) == -1)
			return (84);
	}
	if (window(game) == 84)
		return (84);
}