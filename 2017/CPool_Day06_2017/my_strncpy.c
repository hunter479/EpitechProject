/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** CPool_Day06_2017_Task02
*/

#include <unistd.h>

char	*my_strncpy(char *dest, char const *src, int n)
{
	int len_nsrc = 0;
	int nchar = 0;

	while (src[len_nsrc] != '\0')
	{
		if (nchar < n)
		{
			dest[len_nsrc] = src[len_nsrc];
			nchar = nchar + 1;
		}
		len_nsrc = len_nsrc + 1;
	}
	return (dest);
}
