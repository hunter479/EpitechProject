/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** Initialise the menu scene
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

stage	init_menu(stage *menu)
{
	FILE	*stream = fopen("config/menu", "r");
	size_t	len = 0;
	char	*line = NULL;
	int	i = 0;

	menu = NULL;
	while (getline(&line, &len, stream) > 0) {
		while (line[i] != '\0')
			i++;
		add_object(&menu, line);
		i = 0;
	}
	fclose(stream);
	return *menu;
}
