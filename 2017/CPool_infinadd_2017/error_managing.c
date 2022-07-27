/*
** EPITECH PROJECT, 2017
** infinadd
** File description:
** error managing
*/

#include <unistd.h>

int	error_managing(int ac, char *str1, char *str2)
{
	int	a = 0;
	int	b = 0;
	if (ac != 3)
		return (84);
	while (str1[a] != '\0') {
		if (str1[a] == '-' || str1[a] >= '0' && str1[a] <= '9')
			a++;
		else
			return (84);
	}
	while (str2[b] != '\0') {
		if (str2[b] == '-' || str2[b] >= '0' && str2[b] <= '9')
			b++;
		else
			return (84);
	}
	return (0);
}