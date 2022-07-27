/*
** EPITECH PROJECT, 2017
** COMBINE 2 STR
** File description:
** same
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*my_strcatenv(char *dest, char *src)
{
	int	i = 0;
	int	j = 0;
	char	*str;

	str = malloc(sizeof(str) * (my_strlen(dest) + my_strlen(src) + 1));
	if (str == NULL)
		return (NULL);
	while (dest[i] != '\0') {
		str[i] = dest[i];
		i += 1;
	}
	str[i ++] = '=';
	while (src[j] != '\0')
		str[i ++] = src[j ++];
	str[i] = '\0';
	return (str);
}
