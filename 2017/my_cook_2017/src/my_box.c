/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Create all kind of box: big boxes, tiny boxes, ... can also be
** used for sprites
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

sfIntRect	create_box(int left, int top, int height, int width)
{
	sfIntRect	box;

	box.left = left;
	box.top = top;
	box.width = width;
	box.height = height;
	return (box);
}

sfIntRect	set_box(int *i, char *line)
{
	int	left = 0;
	int	top = 0;
	int	height = 0;
	int	width = 0;
	sfIntRect	to_return;

	left = cut_param(i, line);
	top = cut_param(i, line);
	height = cut_param(i, line);
	width = cut_param(i, line);
	to_return = create_box(left, top, height, width);
	return (to_return);
}
