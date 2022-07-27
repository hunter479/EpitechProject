/*
** EPITECH PROJECT, 2017
** my_str_add
** File description:
** add a string at the end of another string
*/

#include "my.h"
#include <stdlib.h>

char	*dest_add_src(char *dest, char const *src)
{
	int	i = my_strlen(dest);
	int	a = 0;
	int	k = 0;
	char	*tmp = dest;

	dest = my_strset(i + my_strlen(src), '(');
	while (tmp[k] != '\0') {
		dest[k] = tmp[k];
		k++;
	}
	while (src[a] != '\0') {
		dest[i] = src[a];
		i++;
		a++;
	}
	dest[i] = '\0';
	return (dest);
}
