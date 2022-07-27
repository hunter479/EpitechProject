/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** tools
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int		read_map(char *str, game_t *game)
{
	int	fd = open(str, O_RDONLY);
	int	offset = 0;
	game->map = malloc(sizeof(char *) * 4096 + 1);
	if (fd == -1 || !(game->map))
		return (-1);
	offset = read(fd, game->map, 4096 + 1);
	game->map[offset] = '\0';
	if (game->map[0] == '\0')
		return (-1);
}

sfIntRect	int_rec(int left, int top, int width, int height)
{
	sfIntRect	rect;

	rect.left = left;
	rect.top = top;
	rect.width = width;
	rect.height = height;
	return (rect);
}

sfVector2f	vec(float x, float y)
{
	sfVector2f	v;

	v.x = x;
	v.y = y;
	return (v);
}

void		up(game_t *game, obs_t *obs, int *i)
{
	sfRenderWindow_clear(game->w, sfBlack);
	animation_bg(game);
	animation_fg(game);
	animation_obs(game, obs);
	animation_player(i, game);
	sfRenderWindow_display(game->w);
}

void		clean(game_t *game)
{
	sfSprite_destroy(game->sp);
	sfTexture_destroy(game->tp);
	sfRenderWindow_destroy (game->w);
}