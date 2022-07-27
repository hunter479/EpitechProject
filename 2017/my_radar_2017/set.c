/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** first setting for the runner
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "radar.h"
#include <string.h>

void	set_bg(game_t *game)
{
	game->sb = sfSprite_create();
	game->tb = sfTexture_createFromFile("./map.png", NULL);
	sfSprite_setTexture(game->sb, game->tb, sfTrue);
}

void	stg(game_t *game)
{
	set_bg(game);
	sfRenderWindow_setFramerateLimit(game->w, 120);
	sfRenderWindow_clear(game->w, sfBlack);
}