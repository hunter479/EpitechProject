/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** concate_tab
*/

#include <unistd.h>
#include "proto.h"

char	**concate_tab(char **dest, char **src)
{
	int	b = 0;

	while (src && src[b]) {
		dest = add_in_tab(dest, src[b]);
		b++;
	}
	return (dest);
}