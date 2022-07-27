/*
** EPITECH PROJECT, 2017
** my_strupcase.c
** File description:
** CPool_Day06_2017_Task07
*/

#include <unistd.h>

char	 *my_strupcase(char *str)
{
	int	cpt_str = 0;

	while (str[cpt_str] != '\0') {
		if (str[cpt_str] >= 97 && str[cpt_str] <= 122)
			str[cpt_str] = str[cpt_str] - 32;
		cpt_str = cpt_str + 1;
	}
	return (str);
}
