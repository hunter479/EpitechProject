/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** tools
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "radar.h"
#include <string.h>

void		up(game_t *game)
{
	sfRenderWindow_clear(game->w, sfBlack);
	sfRenderWindow_drawSprite(game->w, game->sb, NULL);
	sfRenderWindow_display(game->w);
}
