/*
** EPITECH PROJECT, 2017
** my_strlowcase.c
** File description:
** CPool_Day06_Task08
*/

#include <unistd.h>

char	 *my_strlowcase(char *str)
{
	int	low_str = 0;

	while (str[low_str] != '\0') {
		if (str[low_str] >= 65 && str[low_str] <= 90)
			str[low_str] = str[low_str] + 32;
		low_str = low_str + 1;
	}
	return (str);
}
