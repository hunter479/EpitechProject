/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** fonctions rotations
*/

#include "mylist.h"
#include <unistd.h>
#include "my.h"

void	rra(linked_list_t **list)
{
	linked_list_t	*tail = (*list) ? *list : NULL;
	linked_list_t	*head = (*list) ? *list : NULL;
	linked_list_t	*before_last = NULL;

	if (!(*list))
		return;
	while (tail && tail->next)
		tail = tail->next;
	if (tail)
		before_last = tail->prev;
	if (before_last)
		before_last->next = NULL;
	if (tail) {
		tail->prev = NULL;
		tail->next = head;
	}
	if (head)
		head->prev = tail;
	*list = tail;
	my_putstr("rra ");
}

void	rrb(linked_list_t **list)
{
	linked_list_t	*tail = (*list) ? (*list) : NULL;
	linked_list_t	*head = (*list) ? (*list) : NULL;
	linked_list_t	*before_last = NULL;

	if (!(*list))
		return;
	my_putstr("rrb ");
	while (tail && tail->next)
		tail = tail->next;
	if (tail)
		before_last = tail->prev;
	if (before_last)
		before_last->next = NULL;
	if (tail) {
		tail->prev = NULL;
		tail->next = head;
	}
	if (head)
		head->prev = tail;
	*list = tail;
}