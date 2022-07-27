/*
** EPITECH PROJECT, 2018
** map size
** File description:
** oui
*/

#include <unistd.h>
#include "nick.h"

int	map_size(keys_t *keys, char **av, int j, int k)
{
	char	*tmp_row = NULL;
	char	*tmp_col = NULL;
	int	i = 0;

	while (av[j][i] != '=')
		i += 1;
	tmp_row = my_strdup(av[j] + 1 + i);
	keys->row = my_getnbr(tmp_row);
	while (av[j][i] != ',')
		i += 1;
	tmp_col = my_strdup(av[j] + 1 + i);
	keys->col = my_getnbr(tmp_col);
	if (keys->row <= 0 || keys->col <= 0) {
		write(2, "Error: wrong size of map\n", 25);
		return (84);
	}
	else
		return (0);
}
