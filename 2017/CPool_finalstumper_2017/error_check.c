/*
** EPITECH PROJECT, 2017
** error
** File description:
** managing
*/

#include <unistd.h>
#include "my.h"
#define BUFF_SIZE (4096)


int	my_error(char *str)
{
	int	i = 0;
	int	k = 0;

	while (str[i] != '\0') {
		if (str[i] == '\n')
			k++;
		i++;
	}

	if (k == 0 || i == 0) {
		return (84);
	}
	if (i >= BUFF_SIZE) {
		return (84);
	}
	return (0);
}