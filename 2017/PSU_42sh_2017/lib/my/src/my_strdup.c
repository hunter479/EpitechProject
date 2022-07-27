/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** alocate memory
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char	*my_strdup(char *src)
{
	int	i = 0;
	char	*dest;

	dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
