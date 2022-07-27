/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** core function such as player
*/

#include "matchstick.h"
#include "my.h"
#include <unistd.h>

char	**undo_stick(char **tab, int nbr, int line)
{
	int	i = my_strlen(tab[line]) - 1;
	int	a = 0;

	while (tab[line][i] != '\0' && a < nbr) {
		if (tab[line][i] == '|') {
			tab[line][i] = ' ';
			a++;
		}
		i--;
	}
	return (tab);
}

void	is_winner(nb_t *nb, char **tab)
{
	if (nb->winner == 2) {
		print_tab(tab);
		my_printf("I lost... snif... but I'll get you next time!!\n");
		nb->winner = 1;
		return;
	}
	if (nb->winner == 1) {
		my_printf("You lost, too bad...\n");
		nb->winner = 2;
		return;
	}
}

char	**action_of_the_player(char **tab, int matches, int line, nb_t *nb)
{
	char	**tmp = tab;

	tmp = undo_stick(tmp, matches, line);
	my_printf("Player removed %d match(es) from line %d\n", matches, line);
	nb->winner = 1;
	return (tmp);
}

char	**player(char **tab, nb_t *nb)
{
	int	line = 0;
	int	matches = 0;
	char	**tmp = tab;

	print_tab(tmp);
	if (tab_stick(tab) == 0)
		return (NULL);
	my_printf("\nYour turn:\n");
	while (matches == 0 || matches == -1) {
		line = line_box(nb, tab);
		if (line == -1)
			return (NULL);
		matches = matches_box(nb, line, tab);
		if (matches == -2) {
			nb->ex = 1;
			return (NULL);
		}
	}
	tmp = action_of_the_player(tmp, matches, line, nb);
	return (tmp);
}

int	start(char **tab, nb_t *nb)
{
	char	**tmp = tab;

	while (tmp && tab_stick(tmp) != 0) {
		tmp = player(tmp, nb);
		if (!tmp || nb->ex == 1) {
			nb->winner = 0;
			return (-1);
		}
		else
			ia(nb, tab);
	}
	return (0);
}