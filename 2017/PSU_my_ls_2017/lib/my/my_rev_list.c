/*
** EPITECH PROJECT, 2017
** my_rev_list.c
** File description:
** CPool_Day11_2017_Task03
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_ls.h"

void	my_rev_list(stack_t **begin)
{
	stack_t	*before = NULL;
	stack_t	*cur = (*begin) ? *begin : NULL;
	stack_t	*ahead = (cur) ? cur->next : NULL;

	if (!ahead)
		return;
	while (cur != NULL) {
		cur->next = before;
		before = cur;
		cur = ahead;
		if (cur)
			ahead = cur->next;
	}
	*begin = before;
}
