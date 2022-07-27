/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** copy a string on another one
*/

#include "my.h"

char	*my_strcpy(char *dest, char const *src)
{
	int len_src = 0;

	while (src[len_src] != '\0') {
		dest[len_src] = src[len_src];
		len_src++;
	}
	dest[len_src] = '\0';
	return (dest);
}
