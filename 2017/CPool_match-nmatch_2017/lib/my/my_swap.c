/*
** EPITECH PROJECT, 2017
** my_swap.c
** File description:
** CPool_Day04_2017_Task01
*/

#include <unistd.h>

void	my_swap(int *g, int *j)
{
	int h;
	h = *g;
	*g = *j;
	*j = h;
}
