/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** function of full of things
*/

#include "matchstick.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int	there_is_stick(int line, char **tab)
{
	int	a = 0;
	int	i = 0;

	while (tab[line][a] != '\0') {
		if (tab[line][a] == '|')
			i++;
		a++;
	}
	return (i);
}

int	matches_verif(nb_t *nb, int line, char **tab, char *s)
{
	int	nbr = my_getnbr(s);

	if (is_number(s) == -1) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	if (nbr > nb->limit) {
		my_printf("Error: you cannot remove more");
		my_printf(" than %d matches per turn\n", nb->limit);
		return (-1);
	}
	if (nbr > there_is_stick(line, tab)) {
		my_printf("Error: not enough matches on this line\n");
		return (-1);
	}
	if (nbr == 0) {
		my_printf("Error: you have to remove at least one match\n");
		return (-1);
	}
	return (0);
}

int	matches_box(nb_t *nb, int line, char **tab)
{
	char	*s = NULL;
	int	nbr = 0;

	my_printf("Matches: ");
	s = get_next_line(0);
	if (!s)
		return (-2);
	nbr = my_getnbr(s);
	if (matches_verif(nb, line, tab, s) == -1)
		return (-1);
	free(s);
	return (nbr);
}

int	verif_player(nb_t *nb, int nbr, char **tab, char *s)
{
		if (is_number(s) == -1) {
			my_printf("invalid input (positive number expected)\n");
			return (-1);
		}
		if (nbr == 0 || nbr > nb->line) {
			my_printf("Error: this line is out of range\n");
			return (-1);
		}
		if (there_is_stick(nbr, tab) == 0) {
			my_printf("Error: not enough matches on this line\n");
			return (-1);
		}
}

int	line_box(nb_t *nb, char **tab)
{
	int	bool = 0;
	char	*s = NULL;
	int	nbr = 0;

	while (bool == 0) {
		my_printf("Line: ");
		s = get_next_line(0);
		if (!s) {
			free(s);
			return (-1);
		}
		nbr = my_getnbr(s);
		if (verif_player(nb, nbr, tab, s) != -1)
			bool = 1;
	}
	free(s);
	return (nbr);
}
