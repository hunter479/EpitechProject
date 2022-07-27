/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** tools for the project
*/

#include "mylist.h"
#include <unistd.h>
#include <stdlib.h>

int	is_sorted(linked_list_t *list)
{
	int	sorted = 1;

	while (list && list->next) {
		if (list->data <= list->next->data)
			list = list->next;
		else
			return (-1);
	}
	return (1);
}

void	push_swap(linked_list_t **list)
{
	linked_list_t	*a = *list;
	linked_list_t	*b = NULL;

	sort(&a, &b);
	*list = a;
}

void	my_free_list(linked_list_t **list)
{
	if (!(*list))
		return;
	while ((*list)->next) {
		*list = (*list)->next;
		free((*list)->prev);
	}
	free((*list));
}