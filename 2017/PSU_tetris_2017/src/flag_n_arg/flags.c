/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** same
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "nick.h"
#include "struct.h"
#include "proto.h"

int	flags(int ac, char **av, tetri_t *it)
{
	keys_t	keys;
	fl_t	*fl = NULL;

	init_keys(&keys);
	fl = init_flags(fl);

	if (!fl || !it)
		return (-1);
	if (ac == 1)
		return (0);
	else
		return (check_flags(av, &keys, fl, it));
}
