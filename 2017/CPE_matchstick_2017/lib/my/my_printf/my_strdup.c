/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** transfer a string into another one
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
	char	*str = NULL;
	char	*tmp = src;
	int	i = my_strlen(tmp);

	if (src) {
		str = malloc(sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
		str = my_strcpy(str, tmp);
		return (str);
	}
	else
		return (NULL);
}