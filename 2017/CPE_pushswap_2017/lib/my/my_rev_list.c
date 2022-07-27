/*
** EPITECH PROJECT, 2017
** my_rev_list.c
** File description:
** CPool_Day11_2017_Task03
*/

#include "mylist.h"
#include <stdlib.h>
#include <unistd.h>

void	my_rev_list(linked_list_t **begin)
{
	linked_list_t	*before = NULL;
	linked_list_t	*cur = *begin;
	linked_list_t	*ahead = cur->next;

	while (cur != NULL) {
		cur->next = before;
		before = cur;
		cur = ahead;
		if (cur)
			ahead = cur->next;
	}
	*begin = before;
}