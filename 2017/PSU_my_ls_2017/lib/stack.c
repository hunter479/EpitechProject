/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** stack
*/

#include "my_ls.h"
#include <stdlib.h>
#include <stdio.h>

void	put_in_list(char *str, stack_t **list)
{
	stack_t	*elem = NULL;
	stack_t	*tail = *list;

	elem = malloc(sizeof(stack_t));
	if (!elem)
		return;
	elem->data = str;
	elem->next = NULL;
	if (!tail) {
		*list = elem;
		return;
	}
	while (tail->next)
		tail = tail->next;
	tail->next = elem;
}

void	split(stack_t *source, stack_t **front, stack_t **back)
{
	stack_t *fast;
	stack_t *slow;

	if (source == NULL || source->next == NULL) {
		*front = source;
		*back = NULL;
		return;
	}
	slow = source;
	fast = source->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = source;
	*back = slow->next;
	slow->next = NULL;
}

void	sort(stack_t **headref, char to_sort)
{
	stack_t *head = *headref;
	stack_t *a;
	stack_t *b;

	if (!head || !(head->next))
		return;
	split(head, &a, &b);
	sort(&a, to_sort);
	sort(&b, to_sort);
	if (to_sort == 'd')
		*headref = sorted_merge_dir(a, b);
	if (to_sort == 'f')
		*headref = sorted_merge_file(a, b);
	if (to_sort == 't')
		*headref = sorted_merge_modif(a, b);
}

stack_t	*to_merge(stack_t *list, stack_t *list2)
{
	stack_t *tail = (list) ? (list) : NULL;
	stack_t *merge = (list) ? (list) : NULL;

	if (!list)
		return (list2);
	if (!list2)
		return (list);
	tail = list;
	while (tail->next)
		tail = tail->next;
	tail->next = list2;
	return (merge);
}