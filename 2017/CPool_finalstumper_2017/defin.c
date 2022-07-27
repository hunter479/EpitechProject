/*
** EPITECH PROJECT, 2017
** defin
** File description:
** final stumper
*/

#include <unistd.h>
#include "my.h"
#define BUFF_SIZE (4096)


void	my_x_y(char *str)
{
	int	i = 0;
	int	j = 0;

	while (str[i] != '\0') {
		if (str[i] == '\n')
			j++;
		i++;
	}
	i = 0;
	while (str[i] != '\n')
		i++;
	my_putchar(' ');
	my_put_nbr(i);
	my_putchar(' ');
	my_put_nbr(j);
}

int	affichage(char *str)
{
	my_x_y(str);
	my_putchar(' ');
	my_putstr("||");
	my_putchar(' ');
}

void	rush3(char *str)
{
	int	i = 0;
	int	k = 0;

	while (str[i] != '\n')
		i++;
	while (str[k] != '\0')
		k++;
	rush_detect(str);
	rush_detect2(str, i, k);
	rush_detect3(str);
	my_putchar('\n');
}