/*
** EPITECH PROJECT, 2017
** my_params_to_list
** File description:
** CPool_Day11_2017_Task01
*/

#include "my.h"
#include "mylist.h"
#include <stdlib.h>
#include <unistd.h>

linked_list_t	*create_elem(int nbr)
{
	linked_list_t *element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->data = nbr;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

int	my_params_to_list(int ac, char **av, linked_list_t **list)
{
	linked_list_t	*elem = 0;
	linked_list_t	*last = 0;
	int		i = 0;

	if (ac < 2)
		return (84);
	while (++i < ac) {
		elem = create_elem(my_getnbr(av[i]));
		if (!(*list)) {
			(*list) = elem;
			last = elem;
		}
		else {
			last->next = elem;
			elem->prev = last;
			last = elem;
		}
	}
	*list = (*list);
	return (0);
}
