/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** same
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "proto.h"
#include "struct.h"
#include "term.h"

int	main(int ac, char **av, char **env)
{
	tetri_t	*it = NULL;
	int	status = 0;
	int	i = 0;

	if (env[0] == NULL)
		return (84);
	if (init_term(env) == -1)
		return (84);
	if (setupterm(NULL, 0, &i) < 0)
		return (84);
	it = get_tetriminos("./tetriminos/");
	if (nb_tetri(it) > 0) {
		status = flags(ac, av, it);
		free_list(it);
		return (status);
	} else {
		write(2, "Error: no tetrimino found.\n", 28);
		return (84);
	}
}
