/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** CPool_Day06_2017_Task01
*/

#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
	int len_src;

	len_src = 0;
	while (src[len_src] != '\0')
	{
		dest[len_src] = src[len_src];
		len_src = len_src + 1;
	}
	return (dest);
}
