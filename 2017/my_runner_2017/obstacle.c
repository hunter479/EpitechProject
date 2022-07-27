/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** gestion of obstacle
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"
#include <string.h>

void	set_obs2(game_t *game, obs_t **obs, int x)
{
	obs_t	*elem = NULL;
	obs_t	*tail = *obs;

	elem = malloc(sizeof(obs_t));
	if (!elem)
		return;
	elem->s	= sfSprite_create();
	elem->t	= sfTexture_createFromFile(OB2, NULL);
	elem->x = 1600 + x;
	elem->y = 590;
	sfSprite_setTexture(elem->s, elem->t, sfTrue);
	sfSprite_setScale(elem->s, vec(0.3, 0.3));
	sfSprite_setPosition(elem->s, vec(elem->x, elem->y));
	elem->next = NULL;
	if (!tail) {
		*obs = elem;
		return;
	}
	while (tail->next)
		tail = tail->next;
	tail->next = elem;
}

void	set_obs1(game_t *game, obs_t **obs, int x)
{
	obs_t	*elem = NULL;
	obs_t	*tail = *obs;

	elem = malloc(sizeof(obs_t));
	if (!elem)
		return;
	elem->s	= sfSprite_create();
	elem->t	= sfTexture_createFromFile(OB1, NULL);
	elem->x = 1600 + x;
	elem->y = 540;

	sfSprite_setTexture(elem->s, elem->t, sfTrue);
	sfSprite_setScale(elem->s, vec(0.4, 0.4));
	sfSprite_setPosition(elem->s, vec(elem->x, elem->y));
	elem->next = NULL;
	if (!tail) {
		*obs = elem;
		return;
	}
	while (tail->next)
		tail = tail->next;
	tail->next = elem;
}

void	use_map(game_t *game, obs_t **obs)
{
	int	a = 0;
	int	x = 20;

	game->to_time = 10;
	while (game->map[a] != '\0') {
		if (game->map[a] == '1')
			set_obs1(game, obs, x);
		if (game->map[a] == '2')
			set_obs2(game, obs, x);
		if (game->map[a] == '0') {
			x += 390;
			game->to_time += 5;
		}
		a++;
		x += 390;
		game->to_time += 5;
	}
}