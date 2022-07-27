/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** function for an ia
*/

#include "matchstick.h"
#include "my.h"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int	remove_or_not(int matches, char **tab)
{
	if (tab_stick(tab) == 1)
		return (1);
	if (tab_stick(tab) - matches == 0)
		return (-1);
	return (1);
}

int	check_ia(int line, int match, nb_t *nb, char **tab)
{
	if (line == 0 || line > nb->line)
		return (-1);
	if (match == 0 || match > nb->limit)
		return (-1);
	if (there_is_stick(line, tab) == 0 || match > there_is_stick(line, tab))
		return (-1);
	if (match != 1 && match != 3 && match != 5 && match != 7)
		return (-1);
	return (0);
}

char	**ia(nb_t *nb, char **tab)
{
	int	line = 0;
	int	matches = 0;
	char	**tmp = tab;

	print_tab(tmp);
	if (tab_stick(tab) == 0)
		return (NULL);
	srand(time(NULL) * getpid());
	my_printf("\nAI's turn...\n");
	while (check_ia(line, matches, nb, tab) == -1) {
		line = rand() / (RAND_MAX / nb->line + 1) + 1;
		matches = rand() / (RAND_MAX / nb->limit + 1) + 1;
		while (remove_or_not(matches, tab) == -1)
			matches = rand() / (RAND_MAX / nb->limit + 1) + 1;
	}
	my_printf("AI removed %d match(es) from line %d\n", matches, line);
	tmp = undo_stick(tmp, matches, line);
	nb->winner = 2;
	return (tmp);
}