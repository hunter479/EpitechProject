/*
** EPITECH PROJECT, 2018
** debug modde
** File description:
** ouo
*/

#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <curses.h>
#include "nick.h"
#include "my.h"
#include "struct.h"
#include "proto.h"

int	debug_mode(keys_t *keys, tetri_t *it)
{
	char	tmp[1];

	if (keys)
		key_print(keys);
	if (it && keys)
		tetri_print(it, keys);
	if (keys && it) {
		my_printf("Press any key to start Tetris\n");
		initscr();
		read(0, tmp, 1);
	}
	if (!it || !keys)
		return (84);
	return (0);
}
