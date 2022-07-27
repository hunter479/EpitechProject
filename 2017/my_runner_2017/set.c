/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** first setting for the runner
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "framebuffer.h"
#include <string.h>

void	set_bg(game_t *game)
{
	game->sb = sfSprite_create();
	game->tb = sfTexture_createFromFile(BG, NULL);
	sfSprite_setTexture(game->sb, game->tb, sfTrue);
	sfSprite_setScale(game->sb, vec(1.8, 1.9));
	game->sb2 = sfSprite_create();
	game->tb2 = sfTexture_createFromFile(BG, NULL);
	sfSprite_setTexture(game->sb2, game->tb2, sfTrue);
	sfSprite_setScale(game->sb2, vec(1.8, 1.9));
}

void	set_fg(game_t *game)
{
	game->s_fg = sfSprite_create();
	game->t_fg = sfTexture_createFromFile(FG, NULL);
	sfSprite_setTexture(game->s_fg, game->t_fg, sfTrue);
	sfSprite_setScale(game->s_fg, vec(1.422, 2));
	game->s_fg2 = sfSprite_create();
	game->t_fg2 = sfTexture_createFromFile(FG, NULL);
	sfSprite_setTexture(game->s_fg2, game->t_fg2, sfTrue);
	sfSprite_setScale(game->s_fg2, vec(1.422, 2));
}

void	set_p(game_t *game)
{
	game->sp = sfSprite_create();
	game->tp = sfTexture_createFromFile(PR, NULL);
	sfSprite_setTexture(game->sp, game->tp, sfTrue);
}

void	set_txt(game_t *game)
{
	game->font = sfFont_createFromFile("./assets/font.ttf");
	game->text = sfText_create();
	game->sc = sfText_create();
	sfText_setFont(game->text, game->font);
	sfText_setFont(game->sc, game->font);
	sfText_setCharacterSize(game->text, 30);
	sfText_setCharacterSize(game->sc, 30);
	sfText_setString(game->text, "SCORE = ");
	sfText_setString(game->sc, int_to_charstr(game->score));
	sfText_setOrigin(game->text, vec(-10, 0));
	sfText_setOrigin(game->sc, vec(-200, 0));
}

void	stg(game_t *game, obs_t **obs)
{
	use_map(game, obs);
	game->timer_p = sfClock_create();
	game->timer_bg = sfClock_create();
	game->timer_fg = sfClock_create();
	game->timer_obs = sfClock_create();
	game->timer_end = sfClock_create();
	game->x = 100;
	game->y = 540;
	game->x_bg = 0;
	game->dead = 0;
	game->score = 100;
	set_bg(game);
	set_fg(game);
	set_txt(game);
	set_p(game);
	sfRenderWindow_setFramerateLimit(game->w, 120);
	sfRenderWindow_clear(game->w, sfBlack);
}