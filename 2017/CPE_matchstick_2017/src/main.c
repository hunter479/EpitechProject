/*
** EPITECH PROJECT, 2018
** matchstick
** File description:
** main for the project matchstick
*/

#include "matchstick.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_tab(char **tab)
{
	int	a = 0;

	while (tab[a]) {
		my_printf("%s\n", tab[a]);
		a++;
	}
}

int	game(nb_t *nb)
{
	char	**tab = prep_tab(nb);
	int	print_the_winner = 0;

	print_the_winner = start(tab, nb);
	if (print_the_winner != -1)
		is_winner(nb, tab);
	clean_tab(tab);
	return (0);
}

int	first_check_and_init_value(int ac, char **av, nb_t *nb)
{
	if (ac != 3)
		return (84);
	if (is_number(av[1]) == -1 || is_number(av[2]) == -1)
		return (84);
	nb->line = my_getnbr(av[1]);
	nb->limit = my_getnbr(av[2]);
	nb->ex = 0;
	nb->winner = 0;
	if (nb->line <= 1 || nb->limit == 0 || nb->line >= 100)
		return (84);
	return (0);
}

int	main(int ac, char **av)
{
	nb_t	nb;
	if (first_check_and_init_value(ac, av, &nb) == 84)
		return (84);
	game(&nb);
	return (nb.winner);
}