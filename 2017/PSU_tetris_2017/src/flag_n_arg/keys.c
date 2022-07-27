/*
** EPITECH PROJECT, 2018
** checking options
** File description:
** same
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "nick.h"

void	init_keys(keys_t *keys)
{
	int	i = 0;

	keys->level = 1;
	keys->left = tigetstr("kcub1");
	keys->right = tigetstr("kcuf1");
	keys->turn = tigetstr("kcuu1");
	keys->drop = tigetstr("kcud1");
	if (keys->left == NULL || keys->right == NULL ||
		keys->turn == NULL || keys->drop == NULL)
		return;
	keys->quit = "q";
	keys->pause = " ";
	keys->row = 20;
	keys->col = 10;
	keys->next = 1;
	keys->debug = 0;
	return;
}
