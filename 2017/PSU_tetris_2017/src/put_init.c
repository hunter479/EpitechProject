/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** function to put in list and to init
*/

#include <unistd.h>
#include "struct.h"
#include "proto.h"
#include "my.h"

void	put_in_list(tetri_t *new, tetri_t **list)
{
	tetri_t	*elem = NULL;
	tetri_t	*tail = *list;

	elem = new;
	if (!tail) {
		*list = elem;
		return;
	}
	while (tail->next)
		tail = tail->next;
	tail->next = elem;
}

void	init_struct(tetri_t *it)
{
	it->name = NULL;
	it->x = -1;
	it->y = -1;
	it->ok = -1;
	it->color = -1;
	it->form = NULL;
	it->next = NULL;
	return;
}
