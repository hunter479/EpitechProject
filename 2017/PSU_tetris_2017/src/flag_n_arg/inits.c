/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** same
*/

#include <stdlib.h>
#include <stdio.h>
#include "nick.h"
#include "struct.h"

fl_t	*init_flags2(fl_t *fl)
{
	fl[8].cmp = "--key-right";
	fl[8].flags = &key_change;
	fl[9].cmp = "-t";
	fl[9].flags = &change_key;
	fl[10].cmp = "--key-turn";
	fl[10].flags = &key_change;
	fl[11].cmp = "-d";
	fl[11].flags = &change_key;
	fl[12].cmp = "--key-drop";
	fl[12].flags = &key_change;
	fl[13].cmp = "-q";
	fl[13].flags = &change_key;
	fl[14].cmp = "--key-quit";
	fl[14].flags = &key_change;
	fl[15].cmp = "-p";
	fl[15].flags = &change_key;
	fl[16].cmp = "--key-pause";
	fl[16].flags = &key_change;
	fl[17].cmp = NULL;
	return (fl);
}

fl_t	*init_flags(fl_t *fl)
{
	fl = malloc(sizeof(*fl) * 18);
	fl[0].cmp = "--level";
	fl[0].flags = &level_long;
	fl[1].cmp = "-L";
	fl[1].flags = &change_level;
	fl[2].cmp = "--map-size";
	fl[2].flags = &map_size;
	fl[3].cmp = "-w";
	fl[3].flags = &without_next;
	fl[4].cmp = "--without-next";
	fl[4].flags = &without_next;
	fl[5].cmp = "-l";
	fl[5].flags = &change_key;
	fl[6].cmp = "--key-left";
	fl[6].flags = &key_change;
	fl[7].cmp = "-r";
	fl[7].flags = &change_key;
	init_flags2(fl);
	return (fl);
}

int	check_flags(char **av, keys_t *keys, fl_t *fl, tetri_t *it)
{
	int	j = 1;
	int	ret = 0;

	for (int k = 1; av[k] != NULL; k++)
		if (check_arg("--help", av[k]) == 1)
			return (display_help(av[0]));
	while (av[j]) {
		ret = check_opt(av, j, keys, fl);
		if (ret == 84) {
			write(2, "Error\n", 6);
			return (84);
		}
		else if (ret == 1)
			j += 2;
		else
			j += 1;
	}
	if (keys->debug == 1)
		return (debug_mode(keys, it));
	return (0);
}
