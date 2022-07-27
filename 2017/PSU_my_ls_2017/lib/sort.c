/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** list of functions which change the way of sorting
*/

#include "my_ls.h"
#include <stdlib.h>
#include <stdio.h>

stack_t	*sorted_merge_modif(stack_t *a, stack_t *b)
{
	stack_t	*result = NULL;
	int	k = 0;
	int	na = my_getnbr(a->data);
	int	nb = my_getnbr(b->data);

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (na <= nb) {
		result = a;
		result->next = sorted_merge_file(a->next, b);
	}
	else {
		result = b;
		result->next = sorted_merge_file(a, b->next);
	}
	return (result);
}

stack_t	*sorted_merge_file(stack_t *a, stack_t *b)
{
	stack_t	*result = NULL;
	int	k = 0;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	k = my_strcmp(a->data, b->data);
	if (k >= 0) {
		result = a;
		result->next = sorted_merge_file(a->next, b);
	}
	else {
		result = b;
		result->next = sorted_merge_file(a, b->next);
	}
	return (result);
}

stack_t	*sorted_merge_dir(stack_t *a, stack_t *b)
{
	stack_t	*result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (my_strlen(a->data) <= my_strlen(b->data)) {
		result = a;
		result->next = sorted_merge_file(a->next, b);
	}
	else {
		result = b;
		result->next = sorted_merge_file(a, b->next);
	}
	return (result);
}