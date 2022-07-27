/*
** EPITECH PROJECT, 2018
** without next
** File description:
** ou
*/

#include "nick.h"

int	without_next(keys_t *keys, char **av, int j, int i)
{
	if (keys->next == 0) {
		keys->next = 1;
		return (0);
	}
	else if (keys->next == 1) {
		keys->next = 0;
		return (0);
	}
	else
		return (84);
}
