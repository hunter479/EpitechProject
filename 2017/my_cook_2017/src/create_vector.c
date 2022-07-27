/*
** EPITECH PROJECT, 2017
** create_vector
** File description:
** create a 2d vector
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "proto.h"

sfVector2u	create_vector2u(float x, float y)
{
	sfVector2u	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

sfVector2f	create_vector(float x, float y)
{
	sfVector2f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}
