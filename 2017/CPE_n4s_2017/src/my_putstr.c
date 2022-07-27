/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
	return;
}

void	my_putstr(char *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i += 1;
	}
	return;
}
