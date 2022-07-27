/*
** EPITECH PROJECT, 2018
** clean_str
** File description:
** solo stumper 1
*/

#include <unistd.h>
#include "clean_str.h"

void	clean_str(char *str)
{
	int	a = 0;

	while (str[0] < 33 || str[0] > 126)
		str++;
	while (str[a]) {
		while (str[a] >= 33 && str[a] <= 126) {
			my_putchar(str[a]);
			a++;
		}
		while (str[a] < 33 && str[a] != '\0' && str[a] != 126)
			a++;
		if (str[a] == '\0') {
			my_putchar('\n');
			return;
		}
		my_putchar(' ');
	}
}

int	main(int ac, char **av)
{
	if (!av[1])
		my_putchar('\n');
	else
		clean_str(av[1]);
	return (0);
}