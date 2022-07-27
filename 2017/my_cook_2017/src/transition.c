/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** create transitions as fade in and fade out
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

sfColor	fade_in(window_s *w)
{
	sfColor	color = sfColor_fromRGBA(0, 0, 0, w->alpha);

	if (w->alpha > 250)
		w->alpha = 255;
	else
		w->alpha += 5;
	return color;
}

sfColor	fade_out(window_s *w)
{
	sfColor	color = sfColor_fromRGBA(0, 0, 0, w->alpha);

	if (w->alpha < 8)
		w->alpha = 0;
	else
		w->alpha -= 8;
	return color;
}
