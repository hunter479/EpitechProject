/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** animation
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"
#include <string.h>

void	jump(game_t *game, float x, float y)
{
	if (sfKeyboard_isKeyPressed(sfKeyQ))
		game->x -= x;
	if (sfKeyboard_isKeyPressed(sfKeyD))
		game->x += y;
}

void	animation_obs(game_t *game, obs_t *obs)
{
	int		x = 50;
	sfFloatRect	rect = sfSprite_getGlobalBounds(game->sp);

	while (obs) {
		if (sfFloatRect_contains(&rect, obs->x + 50, obs->y + 50))
			game->dead = 1;
		obs->x -= 1;
		sfSprite_setPosition(obs->s, vec(obs->x + x, obs->y));
		sfRenderWindow_drawSprite(game->w, obs->s, NULL);
		obs = obs->next;
		x += 50;
	}

}

void	animation_bg(game_t *game)
{
	game->x_bg -= 0.1;
	sfSprite_setPosition(game->sb, vec(game->x_bg, 0));
	sfSprite_setPosition(game->sb2, vec(game->x_bg + 1600, 0));
	sfClock_restart(game->timer_bg);
	sfRenderWindow_drawSprite(game->w, game->sb2, NULL);
	sfRenderWindow_drawSprite(game->w, game->sb, NULL);
	game->score++;
	sfText_setString(game->sc, int_to_charstr(game->score));
	sfRenderWindow_drawText(game->w, game->sc, NULL);
	sfRenderWindow_drawText(game->w, game->text, NULL);
	if (game->x_bg <= -1600)
		game->x_bg = 0;
}

void	animation_fg(game_t *game)
{
	game->x_fg -= 1;
	sfSprite_setPosition(game->s_fg, vec(game->x_fg, 154));
	sfSprite_setPosition(game->s_fg2, vec(game->x_fg + 1280, 154));
	sfClock_restart(game->timer_fg);
	sfRenderWindow_drawSprite(game->w, game->s_fg, NULL);
	sfRenderWindow_drawSprite(game->w, game->s_fg2, NULL);
	if (game->x_fg <= -1280)
		game->x_fg = 0;
}

void	animation_player(int *i, game_t *game)
{
	sfIntRect	rect = int_rec(0, 0, 130, 150);

	if (sfTime_asMilliseconds(sfClock_getElapsedTime(game->timer_p)) > 90) {
		*i = (*i + 1) % 16;
		rect.left = 130 * *i;
		sfSprite_setTextureRect(game->sp, rect);
		sfClock_restart(game->timer_p);
	}
	sfRenderWindow_drawSprite(game->w, game->sp, NULL);
}
