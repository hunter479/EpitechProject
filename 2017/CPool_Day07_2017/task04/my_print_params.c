/*
** EPITECH PROJECT, 2017
** my_print_params.c
** File description:
** CPool_Day07_2017_Task04
*/

#include <unistd.h>

int main(int ac, int **av)
{
	int mloop = 0;

	while (av[mloop] != NULL) {
		my_putstr(av[mloop]);
		mloop++;
	}
	return (0);
}
