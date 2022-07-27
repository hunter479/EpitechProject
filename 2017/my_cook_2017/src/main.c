/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** A 'Cook Serve Delicious' like game
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "proto.h"

int	main(int ac, char **av, char **env)
{
	int	status = check(ac, av, env);

	if (status == 1)
		return (0);
	else if (status == -1)
		return (84);
	else
		prepare_game();
	return (0);
}
