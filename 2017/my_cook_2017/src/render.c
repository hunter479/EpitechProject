/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Initialise and render the menu
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

void	display_time(window_s *w)
{
	sfText	*text = sfText_create();
	sfFont	*font = sfFont_createFromFile("assets/fonts/digital.ttf");
	char	*minutes = int_in_char(w->game.minutes);
	char	*s;

	if (w->game.minutes == 0)
		minutes = "0";
	if (w->game.minutes < 10)
		minutes = concat_strings("0", minutes);
	s = concat_strings(int_in_char(w->game.hours), ":");
	s = concat_strings(s, minutes);
	sfText_setFont(text, font);
	sfText_setString(text, s);
	sfText_setScale(text, create_vector(1.9, 1.9));
	sfText_setPosition(text, create_vector(955, 250));
	sfRenderWindow_drawText(w->window, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
	free(s);
	free(minutes);
}

void	render_transitions(window_s *w)
{
	sfTexture	*texture;
	sfSprite	*sprite = sfSprite_create();

	texture = sfTexture_createFromFile("assets/black.png", NULL);
	sfSprite_setColor(sprite, fade_out(w));
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, create_vector(0, 0));
	sfRenderWindow_drawSprite(w->window, sprite, NULL);
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
}

void	render_sprite(window_s *w, stage *tmp)
{
	sfSprite	*sprite = sfSprite_create();
	float	scale_x = tmp->scale;
	float	scale_y = tmp->scale;

	if (same_strings(tmp->type, "music") == 1 && w->audio.mute == 1)
		tmp->box.left = 512;
	else if (same_strings(tmp->type, "music") == 1)
		tmp->box.left = 0;
	sfSprite_setTexture(sprite, tmp->texture, sfTrue);
	sfSprite_setTextureRect(sprite, tmp->box);
	sfSprite_setPosition(sprite, create_vector(tmp->x, tmp->y));
	sfSprite_setScale(sprite, create_vector(scale_x, scale_y));
	sfRenderWindow_drawSprite(w->window, sprite, NULL);
	sfSprite_destroy(sprite);
	if (same_strings(tmp->type, "clock") == 1)
		if (same_strings(tmp->scene, "play") == 1)
			display_time(w);
}

void	render_mouse(window_s *w)
{
	sfTexture	*texture_mouse;
	sfSprite	*sprite = sfSprite_create();
	float	x = w->x_mouse * w->width;
	float	y = w->y_mouse * w->height;

	texture_mouse = sfTexture_createFromFile("assets/mouse.png", NULL);
	sfSprite_setTexture(sprite, texture_mouse, sfTrue);
	sfSprite_setPosition(sprite, create_vector(x, y));
	sfSprite_setScale(sprite, create_vector(0.07, 0.07));
	sfRenderWindow_drawSprite(w->window, sprite, NULL);
	sfTexture_destroy(texture_mouse);
	sfSprite_destroy(sprite);
}

void	render(window_s *w)
{
	stage	*tmp = &w->scene;

	while (tmp != NULL) {
		if (same_strings(w->cur_scene, tmp->scene) == 1)
			render_sprite(w, tmp);
		tmp = tmp->next;
	}
	if (same_strings(w->cur_scene, "play") == 1)
		display_order(w);
	if (!w->game.is_pause && w->game.cur_meal != NULL)
		render_meal(w);
	render_transitions(w);
}
