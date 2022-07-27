/*
** EPITECH PROJECT, 2017
** final_stumper
** File description:
** rush_detect.c
*/

#include <unistd.h>
#include "my.h"
#define BUFF_SIZE (4096)

void	rush_detect3(char *str)
{
	if (str[0] == '*') {
		my_putstr("[rush1-2]");
		my_x_y(str);
	}
	if (str[0] == '/') {
		my_putstr("[rush1-2]");
		my_x_y(str);
	}
}

void	rush_detect2(char *str, int i, int k)
{
	if (str[0] == 'A') {
		if (str[i - 1] == 'A' && str[k - 2] == 'C') {
			my_putstr("[rush1-3]");
			my_x_y(str);
		}
		if (str[i - 1] == 'C' && str[k - 2] == 'C') {
			my_putstr("[rush1-4]");
			my_x_y(str);
		}
		if (str[i - 1] == 'C' && str[k - 2] == 'A') {
			my_putstr("[rush1-5]");
			my_x_y(str);
		}
	}
}


void	rush_detect(char *str)
{
	if (str[0] == 'o') {
		my_putstr("[rush1-1]");
		my_x_y(str);
	}
	if (str[0] == 'B') {
		my_putstr("[rush1-3]");
		affichage(str);
		my_putstr("[rush1-4]");
		affichage(str);
		my_putstr("[rush1-5]");
		my_x_y(str);
	}
}