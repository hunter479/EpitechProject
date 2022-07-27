/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** pushing list to list
*/

#include "mylist.h"
#include <unistd.h>
#include "my.h"

void	pa(linked_list_t **to, linked_list_t **from)
{
	linked_list_t	*tmp = NULL;

	if (!(*from))
		return;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	tmp->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	*to = tmp;
	(*to)->prev = NULL;
}

void	pb(linked_list_t **to, linked_list_t **from)
{
	linked_list_t	*tmp = NULL;

	if (!(*from))
		return;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	tmp->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	*to = tmp;
	(*to)->prev = NULL;
	my_putstr("pb ");
}