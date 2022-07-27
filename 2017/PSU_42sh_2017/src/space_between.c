/*
** EPITECH PROJECT, 2018
** minishell
** File description:
** put space betwen pigrsp
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*space_between(char *str)
{
	int	mal = 0;
	int	j = 0;
	char	*tmp;

	for (int i = 0; str[i] != '\0'; i++)
		mal += check_pgs(str, i);
	tmp = malloc(sizeof(char) * (mal + 1));
	for (int k = 0; str[k] != '\0'; k ++) {
		if (cpy_pgs(str, k) == 0);
		else {
			tmp[j] = ' ';
			j += 1;
		}
		tmp[j] = str[k];
		j += 1;
	}
	tmp[j] = '\0';
	free(str);
	while ((*tmp < 33 || *tmp > 126) && *tmp != '\0')
		tmp += 1;
	return (tmp);
}
