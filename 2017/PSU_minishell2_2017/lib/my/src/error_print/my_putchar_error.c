/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2017
** File description:
** putchar in the output error
*/

#include <unistd.h>

void	my_putchar_rr(char c)
{
	write(2, &c, 1);
	return;
}