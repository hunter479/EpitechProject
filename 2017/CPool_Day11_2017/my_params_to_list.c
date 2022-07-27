/*
** EPITECH PROJECT, 2017
** my_params_to_list
** File description:
** CPool_Day11_2017_Task01
*/

#include "mylist.h"
#include <stdlib.h>
#include <unistd.h>

linked_list_t *create_elem(char *str)
{
	linked_list_t *element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->data = str;
	element->next = NULL;
	return (element);
}

linked_list_t *my_params_to_list(int ac, char const **av)
{
	linked_list_t *list = NULL;
	linked_list_t *elem;
	int j = 0;

	while (j < ac) {
		elem = create_elem(av[j]);
		elem->next = list;
		list = elem;
		j++;
	}
	return (list);
}
