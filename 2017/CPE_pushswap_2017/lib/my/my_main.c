/*
** EPITECH PROJECT, 2017
** pushswap
** File description:
** fonction to make the pushswap
*/

#include "mylist.h"
#include "my.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	linked_list_t	*list = NULL;

	if (my_params_to_list(ac, av, &list) == 84)
		return (84);
	if (is_sorted(list) == 1 || ac == 2) {
		my_putchar('\n');
		my_free_list(&list);
		return (0);
	}
	push_swap(&list);
	my_free_list(&list);
	return (0);
}
