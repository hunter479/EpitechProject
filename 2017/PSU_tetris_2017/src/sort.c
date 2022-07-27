/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** function to sort
*/

#include <unistd.h>
#include "struct.h"
#include "my.h"

tetri_t	*sorted_merge_file(tetri_t *a, tetri_t *b)
{
	tetri_t	*result = NULL;
	int	k = 0;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	k = my_strcmp(a->name, b->name);
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

void	split(tetri_t *source, tetri_t **front, tetri_t **back)
{
	tetri_t *fast;
	tetri_t *slow;

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

void	sort(tetri_t **headref)
{
	tetri_t *head = *headref;
	tetri_t *a = NULL;
	tetri_t *b = NULL;

	if (!head || !(head->next))
		return;
	split(head, &a, &b);
	sort(&a);
	sort(&b);
	*headref = sorted_merge_file(a, b);
}
