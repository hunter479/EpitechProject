/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** CPool_Day08_2017_Task01
*/

#include <stdlib.h>

char	*my_strdup(char const *src)
{
	char *str;

	
	my_strlen(src);
	str = malloc(sizeof(char) * (my_strlen(src) + 1));
	str = my_strcpy(str, src);
	return (str);
}
