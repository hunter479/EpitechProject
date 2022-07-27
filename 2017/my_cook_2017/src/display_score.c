/*
** EPITECH PROJECT, 2018
** display_score
** File description:
** Display the score
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	score_animation(window_s *w)
{
	sfText	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("assets/fonts/score.ttf");
	sfColor color = sfColor_fromRGBA(0, 0, 0, w->game.score_alpha);

	sfText_setFont(text, font);
	sfText_setColor(text, color);
	sfText_setString(text, "+10$");
	sfText_setScale(text, create_vector(2, 2));
	sfText_setPosition(text, create_vector(140, w->game.score_y));
	sfRenderWindow_drawText(w->window, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
	if (w->game.score_alpha == 5) {
		w->game.score_animation = 0;
		w->game.score_alpha = 255;
		w->game.score_y = 600;
		return;
	}
	w->game.score_y -= 3;
	w->game.score_alpha -= 10;
}

void	display_score(window_s *w)
{
	sfText	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("assets/fonts/score.ttf");
	char	*s;

	if (w->game.score == 0)
		s = concat_strings("0", " $");
	else
		s = concat_strings(int_in_char(w->game.score), " $");
	sfText_setFont(text, font);
	sfText_setColor(text, sfBlack);
	sfText_setString(text, s);
	sfText_setScale(text, create_vector(2, 2));
	sfText_setPosition(text, create_vector(120, 25));
	sfRenderWindow_drawText(w->window, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
	if (w->game.score_animation == 1)
		score_animation(w);
	free(s);
}
