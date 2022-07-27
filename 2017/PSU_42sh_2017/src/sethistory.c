/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** set history
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	nb_len(int nb)
{
	int	tmp = nb;
	int	i = 0;

	while ((tmp /= 10) != 0)
		i++;
	return (i);
}

char	*nbr_to_char(int nb)
{
	char	*char_nb = malloc(sizeof(char) * (nb_len(nb) + 3));
	int	i = nb_len(nb);

	while (nb != 0 && i >= 0) {
		char_nb[i] = (nb % 10) + 48;
		nb /= 10;
		i--;
	}
	char_nb[nb_len(nb) + 1] = '\t';
	char_nb[nb_len(nb) + 2] = '\0';
	return (char_nb);
}

int	tablen(char **tab)
{
	int	i = 0;

	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	*set_hismember(mysh_t ms)
{
	char	*nb = nbr_to_char(tablen(ms.his) + 1);
	char	*time = get_time();
	char	*hismember = my_strdup(nb);

	hismember = my_strcat(hismember, time);
	hismember = my_strcat(hismember, ms.s);
	return (hismember);
}
