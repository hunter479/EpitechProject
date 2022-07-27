/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** sorting_algo
*/

#include "mylist.h"
#include "my.h"
#include <unistd.h>

void	sort2(linked_list_t **a, linked_list_t **b, linked_list_t **tmp)
{
	while ((*tmp) && ((*a)->data <= (*tmp)->data))
		(*tmp) = (*tmp)->next;
	if (!(*tmp)) {
		pb(&(*b), &(*a));
		(*tmp) = (*a)->next;
		if (!(*tmp)) {
			pb(&(*b), &(*a));
		}
	}
}

void	sort(linked_list_t **a, linked_list_t **b)
{
	linked_list_t	*tmp = (*a)->next;

	while (*a) {
		if (tmp && ((*a)->data <= tmp->data))
			sort2(&(*a), &(*b), &tmp);
		while (tmp && (*a)->data > tmp->data) {
			rra(&(*a));
			tmp = (*a)->next;
		}
	}
	while (*b) {
		pa(&(*a), &(*b));
		if (*b)
			my_putstr("pa ");
		else
			my_putstr("pa\n");
	}
}